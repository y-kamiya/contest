#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
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


static const int INF = INT_MAX/2;
void _main() {
    int N;
    cin >> N;

    vector<int> X(N), Y(N);
    REP(i, N) cin >> X[i] >> Y[i];

    double ans = 0;
    vector<double> as(N, INF);
    REP(i, N) {
        REP(j, N) {
            as[j] = INF;
            if (i == j) continue;
            auto x = X[j] - X[i];
            auto y = Y[j] - Y[i];
            as[j] = atan2(y, x) * 180 / M_PI;
            DEBUG(i, j, as[j]);
        }
        vector<double> bs;
        copy(ALL(as), back_inserter(bs));
        sort(ALL(bs));
        DEBUG(as, bs);
        REP(j, N) {
            if (i == j) continue;
            auto tgt = (0 < as[j]) ? as[j]-180 : as[j]+180;
            DEBUG(i, j , "base", as[j], "tgt", tgt);
            auto it = lower_bound(bs.begin(), bs.end(), tgt);
            auto a = abs(as[j] - *it);
            a = min(a, 360-a);
            auto b = -INF * 1.0;
            if (it != bs.begin()) {
                b = abs(as[j] - *(it-1));
                b = min(b, 360-b);
            }
            DEBUG("max", a, b, ans);
            ans = max(ans, max(a, b));
        }
    }
    
    PRINT_DOUBLE(7, ans);
}

int main() {
    _main();
    return 0;
}

