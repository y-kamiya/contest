#include <algorithm>
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
    int N, M;
    cin >> N >> M;

    vector<vector<int>> dp(N, vector(N, INF));
    REP(i, N) dp[i][i] = 0;
    REP(i, M) {
        int a,b,t;
        cin >> a >> b >> t;
        --a; --b;
        dp[a][b] = t;
        dp[b][a] = t;
    }

    REP(k, N) {
        REP(i, N) {
            REP(j, N) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    int ans = INF;
    REP(i, N) {
        auto it = max_element(ALL(dp[i]));
        ans = min(ans, *it);
    }

    REP(i, N) DEBUG(dp[i]);

    cout << ans << endl;
}

int main() {
    _main();
    return 0;
}

// AC 7
// 解いたことあった
