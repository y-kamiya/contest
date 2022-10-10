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


void _main() {
    int N, S;
    cin >> N >> S;

    vector<int> a(N+1, 0), b(N+1, 0);
    FOR(i, 1, N+1) cin >> a[i] >> b[i];

    vector<vector<bool>> dp(N+1, vector(S+1, false));
    dp[0][0] = true;
    FOR(i, 0, N) {
        FOR(j, 1, S+1) {
            if (j-a[i+1]>=0) dp[i+1][j] = dp[i+1][j] || dp[i][j-a[i+1]];
            if (j-b[i+1]>=0) dp[i+1][j] = dp[i+1][j] || dp[i][j-b[i+1]];
        }
    }

    REP(i, N+1) DEBUG(dp[i]);

    if (!dp[N][S]) {
        Yes(0);
        return;
    }
    Yes(1);

    string ans = "";
    int j = S;
    FORR(i, N, 1) {
        if (j>=a[i] && dp[i-1][j-a[i]]) {
            ans += "H";
            j -= a[i];
        } else if (j>=b[i] && dp[i-1][j-b[i]]) {
            ans += "T";
            j -= b[i];
        } else cout << "wrong" << endl;
    }

    reverse(ALL(ans));
    cout << ans << endl;
}

int main() {
    _main();
    return 0;
}

