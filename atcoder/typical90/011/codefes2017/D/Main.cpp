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


struct Entry {
    ll h, p;
    bool operator<(const Entry &e) const {
        return h + p < e.h + e.p;
    }
    friend ostream& operator<<(ostream& os, const Entry &e) {
        return os << "{h:" << e.h << ", p:" << e.p << "}";
    }
};

static const ll INF = LLONG_MAX/2;

void _main() {
    int N;
    cin >> N;

    vector<Entry> E(N);
    REP(i, N) cin >> E[i].h >> E[i].p;

    sort(ALL(E));
    DEBUG(E);

    vector<vector<ll>> dp(N+1, vector(N+1, INF));
    // REP(i, N+1) dp[0][i] = 0;
    REP(i, N+1) dp[i][0] = 0;

    FOR(i, 0, N) {
        auto e = E[i];
        FOR(j, 1, i+2) {
            if (dp[i][j-1] <= e.h) dp[i+1][j] = min(dp[i][j], dp[i][j-1] + e.p);
            else dp[i+1][j] = dp[i][j];
        }
    }

    REP(i, N+1) DEBUG(dp[i]);

    int ans = 0;
    FORR(i, N, 0) {
        if (dp[N][i] != INF) {
            ans = i;
            break;
        }
    }
    /*
    ll sum = 0;
    REP(i, N) {
        auto e = E[i];
        if (sum <= e.h) {
            sum += e.p;
            ++ans;
        }
    }
    */

    cout << ans << endl;
}

int main() {
    _main();
    return 0;
}

