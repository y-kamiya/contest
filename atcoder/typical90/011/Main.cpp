#include <bits/stdc++.h>
#include <ostream>
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

struct Task {
    ll c, d, s;

    bool operator<(const Task &t) const {
        return d < t.d;
    }
    friend ostream& operator<<(ostream &os, const Task &t) {
        return os << "{c:" << t.c << ", d:" << t.d << ", s:" << t.s << "}";
    }
};

void _main() {
    int N;
    cin >> N;

    vector<Task> T(N);
    REP(i, N) cin >> T[i].d >> T[i].c >> T[i].s;

    sort(ALL(T));
    auto M = T.back().d;
    DEBUG(T);

    vector<vector<ll>> dp(N+1, vector(M+1, 0ll));
    FOR(i, 0, N) {
        FOR(j, 1, M+1) {
            if (T[i].d < j) break;
            if (j < T[i].c) dp[i+1][j] = dp[i][j];
            else {
                dp[i+1][j] = max(dp[i][j], dp[i][j-T[i].c] + T[i].s);
            }
        }
    }

    REP(i, N+1) DEBUG(dp[i]);

    ll ans = 0;
    REP(j, M+1) ans = max(ans, dp[N][j]);
    cout << ans << endl;


}

int main() {
    _main();
    return 0;
}

