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

const static int MAX = 200000;

void _main() {
    int N;
    cin >> N;

    vector<int> A(N), a(MAX+1, 0);
    REP(i, N) {
        cin >> A[i];
        ++a[A[i]];
    }

    --a[A[0]];

    ll ans = 0;
    FOR(j, 1, N-1) {
        --a[A[j]];
        REP(i, j) {
            if (A[i] == A[j]) continue;
            ans += max(0, N-j-1 - a[A[i]] - a[A[j]]);
            DEBUG(i, j, ans, a[A[i]], a[A[j]], N-j-1 - a[A[i]] - a[A[j]]);
        }
    }

    cout << ans << endl;
}

void __main() {
    int N;
    cin >> N;

    vector<int> A(N), a(MAX+1, 0);
    REP(i, N) {
        cin >> A[i];
        ++a[A[i]];
    }

    vector<vector<int>> dp(MAX+1, vector(4, 0));
    REP(i, MAX+1) dp[i][0] = 1;

    REP(i, MAX) {
        REP(j, 3) {
            dp[i+1][j+1] += dp[i][j+1] + dp[i][j] * a[i+1];
        }
    }

    REP(i, MAX+1) DEBUG(dp[i]);

    cout << dp[MAX][3] << endl;
}

int main() {
    __main();
    return 0;
}

