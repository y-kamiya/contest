#include <bits/stdc++.h>
#include <queue>
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

using P = pair<ll, int>;
struct Edge {
    int to, cost;
    Edge(int t,int c): to(t), cost(c) {}
};

class Graph {
    int n;
    vector<vector<Edge>> G;
public:
    vector<ll> dist;

    Graph(ll size): n(size) {
        dist.resize(size, INF);
        G.resize(size);
    }

    void add_edge(int s, int t, int cost) {
        G[s].emplace_back(t, cost);
        G[t].emplace_back(s, cost);
    }

    void dijkstra(int s) {
        REP(i, n) {
            dist[i] = INF;
        }
        dist[s] = 0;

        priority_queue<P, vector<P>, greater<P>> que;
        que.emplace(0, s);

        while (!que.empty()) {
            P p = que.top();
            que.pop();

            for (auto &e : G[p.second]) {
                if (dist[e.to] > p.first + e.cost) {
                    dist[e.to] = p.first + e.cost;
                    que.emplace(dist[e.to], e.to);
                }
            }
        }
    }
};

void _main() {
    int n, k;
    cin >> n >> k;

    Graph G(n);

    REP(i, k) {
        int f; cin >> f;
        if (f == 0) {
            int a,b; cin >> a >> b;
            --a; --b;
            G.dijkstra(a);
            ll ans = -1;
            if (G.dist[b] != INF) ans = G.dist[b];
            cout << ans << endl;
        } else {
            int c,d,e; cin >> c >> d >> e;
            --c; --d;
            G.add_edge(c, d, e);
        }
    }

}

int main() {
    _main();
    return 0;
}

// AC 22.5 (template使わず)

