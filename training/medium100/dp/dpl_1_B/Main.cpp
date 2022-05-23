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


void _main() {
    int N, W;
    cin >> N >> W;

    vector<int> w(N), v(N);
    REP(i, N) cin >> v[i] >> w[i];

    vector<vector<int>> dp(N+1, vector(W+1, 0));

    FOR(i, 0, N) {
        FOR(j, 0, W+1) {
            if (j >= w[i]) {
                auto a = max(dp[i][j-w[i]] + v[i], dp[i][j]);
                dp[i+1][j] = max(dp[i+1][j], a);
            }
            else dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
        }
    }

    REP(i, N+1) DEBUG(dp[i]);

    cout << dp[N][W] << endl;
}

int main() {
    _main();
    return 0;
}

// AC 22
// 添字の扱いがうまくいかずデバッグに時間かかる
