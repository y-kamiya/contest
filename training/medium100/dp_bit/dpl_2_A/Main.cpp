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
    int V, E;
    cin >> V >> E;

    vector<vector<int>> cost(V, vector(V, INF));
    REP(i, E) {
        int s, t, d;
        cin >> s >> t >> d;
        cost[s][t] = d;
    }

    vector<vector<int>> dp(1<<V, vector(V, INF));
    dp[0][0] = 0;

    REP(S, 1<<V) {
        REP(v, V) {
            REP(u, V) {
                if (S != 0 && !(S & (1<<u))) continue;
                if (u == v) continue;
                if (!(S & (1<<v))) {
                    dp[S | (1<<v)][v] = min(dp[S | (1<<v)][v], dp[S][u] + cost[u][v]);
                }
            }
        }
    }

    if (dp[(1<<V)-1][0] != INF) cout << dp[(1<<V)-1][0] << endl;
    else cout << -1 << endl;
}

int main() {
    _main();
    return 0;
}

