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
    int N, M;
    cin >> N >> M;

    int m = 10;
    vector<vector<int>> dp(N+1, vector(m, 0));
    REP(i, m) dp[1][i] = i % M;

    FOR(i, 1, N) {
        FOR(j, 1, m) {
            dp[i+1][j] = (10 * dp[i][j] + j) % M;
        }
    }

    REP(i, N+1) DEBUG(dp[i]);

    FORR(i, N, 1) FORR(j, m-1, 1) {
        if (dp[i][j] != 0) continue;
        REP(k, i) {
            cout << j;
        }
        cout << endl;
        return;
    }

    cout << -1 << endl;
}

int main() {
    _main();
    return 0;
}

