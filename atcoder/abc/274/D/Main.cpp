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
    int N, x, y;
    cin >> N >> x >> y;

    vector<int> A(N);
    REP(i, N) cin >> A[i];

    vector<int> X, Y;
    REP(i, N) {
        if (i % 2 == 0) X.push_back(A[i]);
        else Y.push_back(A[i]);
    }
    DEBUG(X);
    DEBUG(Y);

    int M = 10000;
    vector<vector<bool>> dp(N/2+1, vector(2*M+1, false));
    dp[0][M+X[0]] = true;
    FOR(i, 1, X.size()) {
        FOR(j, 0, 2*M+1) {
            if (j>=X[i]) dp[i][j] = dp[i][j] || dp[i-1][j-X[i]];
            if (j+X[i]<2*M+1) dp[i][j] = dp[i][j] || dp[i-1][j+X[i]];
        }
    }
    REP(i, X.size()) DEBUG(dp[i]);

    if (!dp[X.size()-1][M+x]) {
        Yes(0);
        return;
    }

    
    DEBUG("--------------------");
    REP(i, dp.size()) REP(j, dp[0].size()) dp[i][j] = false;
    dp[0][M+Y[0]] = true;
    dp[0][M-Y[0]] = true;
    FOR(i, 1, Y.size()) {
        FOR(j, 0, 2*M+1) {
            if (j>=Y[i]) dp[i][j] = dp[i][j] || dp[i-1][j-Y[i]];
            if (j+Y[i]<2*M+1) dp[i][j] = dp[i][j] || dp[i-1][j+Y[i]];
        }
    }
    REP(i, Y.size()) DEBUG(dp[i]);

    if (!dp[Y.size()-1][M+y]) {
        Yes(0);
        return;
    }
    Yes(1);
}

int main() {
    _main();
    return 0;
}

