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
#ifdef _DEBUG
#define DEBUG(...) print(__VA_ARGS__)
#else
#define DEBUG(...)
#endif


void _main() {
    int D, N;
    cin >> D >> N;

    vector<int> T(D), A(N), B(N), C(N);
    REP(i, D) cin >> T[i];
    REP(i, N) cin >> A[i] >> B[i] >> C[i];

    vector<vector<int>> dp(D+1, vector(N, 0));
    FOR(i, 1, D) {
        FOR(j, 0, N) {
            if (!(A[j] <= T[i] && T[i] <= B[j])) continue;
            FOR(k, 0, N) {
                if (!(A[k] <= T[i-1] && T[i-1] <= B[k])) continue;
                dp[i+1][j] = max(dp[i][k] + abs(C[k] - C[j]), dp[i+1][j]);
            }
        }
    }

    // REP(i, D+1) {
    //     REP(j, N) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int ans = 0;
    REP(i, N) ans = max(ans, dp[D][i]);
    cout << ans << endl;
}

int main() {
    _main();
    return 0;
}

// AC 26
// debugに14
