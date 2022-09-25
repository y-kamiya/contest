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
    int a, b;
    bool operator<(const Entry& e) const {
        return a > e.a;
    }
    friend ostream& operator<<(ostream& os, const Entry& e) {
        return os << "{a:" << e.a << ", b:" << e.b << "}";
    }
};

void _main() {
    int N, P;
    cin >> N >> P;

    vector<Entry> E(N);
    REP(i, N) cin >> E[i].a >> E[i].b;

    sort(ALL(E));
    auto M = E.front().a;

    int ans = 0;
    vector<int> dp(P+M+1, 0);
    FOR(i, 0, N) {
        auto e = E[i];
        auto prev = dp;
        FOR(j, 0, P+e.a+1) {
            if (j < e.a) continue;
            else dp[j] = max(prev[j], prev[j-e.a] + e.b);
        }
        ans = max(ans, dp[P+e.a]);
    }

    cout << ans << endl;
}

int main() {
    _main();
    return 0;
}

