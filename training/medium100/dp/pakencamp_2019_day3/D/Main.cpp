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
    int N;
    cin >> N;

    int R = 5;
    vector<vector<int>> S(R, vector(N, 0));
    REP(i, R) {
        string s; cin >> s;
        REP(j, s.size()) {
            if (s[j] == 'B') S[i][j] = 0;
            if (s[j] == 'W') S[i][j] = 1;
            if (s[j] == 'R') S[i][j] = 2;
            if (s[j] == '#') S[i][j] = 3;
        }
    }

    int C = 3;
    vector<vector<int>> a(N, vector(C, 0));
    REP(j, N) REP(k, C) {
        REP(i, R) {
            a[j][k] += S[i][j] == k;
        }
    }

    vector<vector<int>> dp(N, vector(C, INF));
    dp[0][0] = R - a[0][0];
    dp[0][1] = R - a[0][1];
    dp[0][2] = R - a[0][2];

    FOR(i, 0, N-1) {
        FOR(j, 0, C) {
            int change = R-a[i+1][j];
            dp[i+1][j] = min(dp[i][(j+1)%C], dp[i][(j+2)%C]) + change;
        }
    }

    REP(i, N) DEBUG(dp[i]);

    int ans = INF;
    REP(i, C) ans = min(ans, dp[N-1][i]);
    cout << ans << endl;
}

int main() {
    _main();
    return 0;
}

// AC 28
// debug 3
