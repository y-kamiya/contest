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


using P = pair<ll,ll>;
static const ll INF = LLONG_MAX/2;

void _main() {
    ll N, M;
    cin >> N >> M;

    vector<vector<ll>> cost(1<<N, vector(N,INF));
    vector<vector<ll>> time(1<<N, vector(N,0ll));
    REP(i, M) {
        ll s, t, d, ti;
        cin >> s >> t >> d >> ti;
        --s, --t;
        cost[s][t] = d;
        cost[t][s] = d;
        time[s][t] = ti;
        time[t][s] = ti;
    }

    vector<vector<P>> dp(1<<N, vector<P>(N, {INF, 0}));
    dp[0][0] = {0, 1};
    REP(S, 1<<N) {
        REP(v, N) {
            if (S & (1<<v)) continue;
            REP(u, N) {
                if (S != 0 && !(S & (1<<u))) continue;
                if (u == v) continue;
                P prev = dp[S][u];
                P next = dp[S|(1<<v)][v];

                auto dist = prev.first + cost[u][v];
                if (prev.first != INF && dist > time[u][v]) continue;
                if (next.first < dist) continue;
                DEBUG(S, v, u);
                dp[S | (1<<v)][v] = {
                    prev.first + cost[u][v],
                    next.second + prev.second,
                };
            }
        }
    }

    REP(i, 1<<N) {
        REP(j, N) {
            string a;
            if (dp[i][j].first == INF) a = "INF";
            else a = to_string(dp[i][j].first);
            cout << "{" << a << " " << dp[i][j].second << "} ";
        }
        cout << endl;
    }


    auto p = dp[(1<<N)-1][0];
    if (p.first == INF) cout << "IMPOSSIBLE" << endl;
    else cout << p.first << " " << p.second << endl;
}

int main() {
    _main();
    return 0;
}

