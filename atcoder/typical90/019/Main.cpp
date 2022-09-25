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

    vector<int> A(2*N);
    REP(i, 2*N) cin >> A[i];

    vector<vector<int>> dp(2*N, vector(2*N, INF));
    REP(i, 2*N-1) {
        dp[i][i+1] = abs(A[i] - A[i+1]);
    }

    for (auto i = 3; i < 2*N; i+=2) {
        for (auto j = 0; j < 2*N-1; j+=1) {
            auto l = j;
            auto r = j + i;
            if (r >= 2*N) break;
            dp[l][r] = min(dp[l][r], dp[l+1][r-1] + abs(A[l]-A[r]));
            FOR(k, l+1, r) {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r]);
            }
            DEBUG(l, r, dp[l][r]);
        }
    }

    REP(i, 2*N) DEBUG(dp[i]);

    cout << dp[0][2*N-1] << endl;
}

int main() {
    _main();
    return 0;
}

