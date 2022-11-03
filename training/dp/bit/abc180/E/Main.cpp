#include <bits/stdc++.h>
#include <climits>
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
template<typename T0, typename T1, typename... Tail>
void print(pair<T0,T1> p, Tail... t) {
    cout << "(" << p.first << "," << p.second << ")";
    print(t...);
}
template<typename T, typename... Tail>
void print(vector<T> vec, Tail... t) {
    cout << "["; for (const auto &e : vec) { cout << e << ", "; } cout << "] ";
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

    vector<int> X(N), Y(N), Z(N);
    REP(i, N) cin >> X[i] >> Y[i] >> Z[i];

    vector<vector<int>> dp(1<<N, vector(N, INF));
    dp[0][0] = 0;

    FOR(i, 0, 1<<N) {
        REP(j, N) {
            if (i != 0 && !(i&(1<<j))) continue;
            REP(k, N) {
                if (i&(1<<k)) continue;
                auto cost = abs(X[k]-X[j]) + abs(Y[k]-Y[j]) + max(0, Z[k]-Z[j]);
                dp[i|(1<<k)][k] = min(dp[i|(1<<k)][k], dp[i][j] + cost);
            }
        }
    }

    cout << dp[(1<<N)-1][0] << endl;
}

int main() {
    _main();
    return 0;
}

