#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i>=(b);--i)
#define ALL(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define PRINT_DOUBLE(n, x) cout << std::fixed << std::setprecision(n) << x << endl;

void print() { cout << endl; }
template<typename Head, typename... Tail>
void print(Head h, Tail... t) {
    cout << h << " "; print(t...);
}
template<typename T, typename... Tail>
void print(vector<T> vec, Tail... t) {
    cout << "[";
    for (const auto &e : vec) {
        cout << e << ", ";
    }
    cout << "] ";
    print(t...);
}
#ifdef _DEBUG
#define DEBUG(...) print(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

using Vec = vector<double>;
double dist(double x1, double x2, double y1, double y2) {
    return abs(x1-x2) * abs(x1-x2) + abs(y1-y2) * abs(y1-y2);
}

bool is_ok(const Vec &X, const Vec &Y, const Vec &R, double r) {
    int N = R.size();
    int NM = X.size();
    FOR(i, N, NM) {
        REP(j, N) {
            auto d = dist(X[i], X[j], Y[i], Y[j]);
            DEBUG(d, r, R[i]);
            if (d < (R[j]+r)*(R[j]+r)) return false;
        }
        FOR(j, N, NM) {
            if (i == j) continue;
            auto d = dist(X[i], X[j], Y[i], Y[j]);
            DEBUG(d, r);
            if (d < 4*r*r) return false;
        }
    }
    return true;
}

void _main() {
    int N, M;
    cin >> N >> M;

    vector<double> X(N+M), Y(N+M), R(N);
    REP(i, N+M) {
        if (i < N) cin >> X[i] >> Y[i] >> R[i];
        else cin >> X[i] >> Y[i];
    }

    double r_min = 100;
    REP(i, N) r_min = min(r_min, R[i]);

    double l = 0;
    double r = r_min;
    while (r-l > 1e-7) {
        double mid = (l+r)/2;
        if (is_ok(X, Y, R, mid)) l = mid;
        else r = mid;
    }

    PRINT_DOUBLE(7, r);

}

int main() {
    _main();
    return 0;
}


// AC 50min
// 実装しきるまでに35min程度、そこからデバッグ

