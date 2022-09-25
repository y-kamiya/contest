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

struct Block {
    ll w, s, v;

    bool operator<(const Block& b) const {
        if (w + s == b.w + b.s) {
            return s < b.s;
        }
        return w + s < b.w + b.s;
    }
    friend ostream& operator<<(ostream& os, const Block& b) {
        return os << "{w:" << b.w << ", s:" << b.s << ", v:" << b.v << "}";
    }
};

void _main() {
    int N;
    cin >> N;

    vector<Block> B(N);
    REP(i, N) cin >> B[i].w >> B[i].s >> B[i].v;

    sort(ALL(B));
    auto M = B.back().s;
    ll W = 0;
    REP(i, N) W = max(W, B[i].w);
    DEBUG(B);

    vector<vector<ll>> dp(N+1, vector(W+M+1, 0ll));
    FOR(i, 0, N) {
        FOR(j, 0, W+M+1) {
            auto b = B[i];
            if (j < b.w || j-b.w > b.s) dp[i+1][j] = dp[i][j];
            else dp[i+1][j] = max(dp[i][j], dp[i][j-b.w] + b.v);
        }
    }

    REP(i, N+1) DEBUG(dp[i]);
    ll ans = 0;
    REP(i, W+M+1) ans = max(ans, dp[N][i]);

    cout << ans << endl;

}

int main() {
    _main();
    return 0;
}

