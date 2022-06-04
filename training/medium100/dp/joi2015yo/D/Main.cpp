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
void _main() {
    int N, M;
    cin >> N >> M;

    vector<int> D(N), C(M);
    REP(i, N) cin >> D[i];
    REP(i, M) cin >> C[i];

    vector<vector<int>> dp(M+1, vector(N+1, INF));
    REP(i, M+1) dp[i][0] = 0;

    FOR(i, 0, M) {
        FOR(j, 0, N) {
            dp[i+1][j+1] = min(dp[i][j+1], dp[i][j] + D[j]*C[i]);
        }
    }

    REP(i, M+1) DEBUG(dp[i]);

    int ans = INF;
    REP(i, M+1) ans = min(ans, dp[i][N]);
    cout << ans << endl;
}

int main() {
    _main();
    return 0;
}

// AC 20.5
// debug 8
