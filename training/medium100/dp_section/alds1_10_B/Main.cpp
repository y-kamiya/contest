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

static const int INF = INT_MAX/2;

int dfs(vector<vector<int>> &dp, const vector<int> &r, const vector<int> &c, int s, int t) {
    if (dp[s][t] != INF) return dp[s][t];
    if (abs(s-t) == 1) return dp[s][t] = 0;

    DEBUG(s, t);
    FOR(i, s, t-1) {
        int a = dfs(dp, r, c, s, i+1);
        int b = dfs(dp, r, c, i+1, t);
        dp[s][t] = min(dp[s][t], a + b + r[s]*c[t-1]*c[i]);
        DEBUG(s,t, a,b,dp[s][t]);
    }
    DEBUG(s, t, dp[s][t]);
    return dp[s][t];
}

void _main() {
    int n;
    cin >> n;

    vector<int> r(n), c(n);
    REP(i, n) cin >> r[i] >> c[i];

    vector<vector<int>> dp(n+1, vector(n+1, INF));
    dfs(dp, r, c, 0, n);

    cout << dp[0][n] << endl;
}

int main() {
    _main();
    return 0;
}

