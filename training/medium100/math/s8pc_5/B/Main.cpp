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

double dist(int x0, int y0, int x1, int y1) {
    return sqrt(pow(x1-x0,2) + pow(y1-y0,2));
}

bool is_ok(const vector<int> &x, const vector<int> &y, const vector<int> &r, double R, int N, int M) {
    REP(i, M) {
        REP(j, N) {
            if (N+i == j) continue;
            if (dist(x[N+i], y[N+i], x[j], y[j]) < R + r[j]) return false;
        }
        FOR(j, i+1, M) {
            DEBUG(i, j, dist(x[N+i], y[N+i], x[N+j], y[N+j]), R);
            if(dist(x[N+i], y[N+i], x[N+j], y[N+j]) < 2 * R) return false;
        }
    }
    return true;
}

void _main() {
    int N, M;
    cin >> N >> M;

    vector<int> x(N+M), y(N+M), r(N+M, 0);
    REP(i, N+M) {
        if (i < N) {
            cin >> x[i] >> y[i] >> r[i];
        } else {
            cin >> x[i] >> y[i];
        }
    }

    if (M == 0) {
        int ans = INT_MAX;
        REP(i, N) ans = min(ans, r[i]);
        cout << ans << endl;
        return;
    }

    {
        double l = 0;
        double rr = 100;
        // while (rr-l > 1e-7) {
        REP(_, 500) {
            double mid = (rr+l)/2;
            if (is_ok(x, y, r, mid, N, M)) l = mid;
            else rr = mid;
        }
        DEBUG(l, rr);
        PRINT_DOUBLE(7, rr);
    }

}

int main() {
    _main();
    return 0;
}

// AC 37.5
// midの計算時に引き算にしてるミス

