#include <bits/stdc++.h>
#include <climits>
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

static const int INF = INT_MAX/2;

using P = pair<int,int>;

void _main() {
    int N;
    cin >> N;

    vector<P> a(N);
    REP(i, N) cin >> a[i].first;
    REP(i, N) cin >> a[i].second;

    sort(ALL(a));
    REP(i, N) DEBUG(a[i]);

    vector<int> dp(N, INF);
    FOR(i, 0, N) {
        auto it = lower_bound(ALL(dp), a[i].second);
        int idx = distance(dp.begin(), it);
        DEBUG(i, a[i].second, idx, dp[idx]);
        if (dp[idx] > a[i].second) {
            dp[idx] = a[i].second;
        }
    }
    DEBUG(dp);

    int ans = 0;
    FORR(i, N-1, 0) {
        if (dp[i] != INF) {
            ans = i+1;
            break;
        }
    }
    ans += N;

    cout << ans << endl;

}

int main() {
    _main();
    return 0;
}

