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

using P = pair<ll, ll>;
static const ll INF = 1ll<<61;
struct Edge {
    ll to, cost, id;
};
struct Graph {
    ll n;
    vector<ll> dist;
    vector<vector<Edge>> edges;
    vector<int> ids;

    Graph(ll size): n(size) {
        dist.resize(n, INF);
        edges.resize(n);
        ids.resize(n, -1);
    }

    void add_edge(ll s, ll t, ll cost, ll id) {
        Edge e{t, cost, id};
        edges[s].push_back(e);
    }

    void dijkstra(ll s) {
        REP(i, n) {
            dist[i] = INF;
            ids[i] = -1;
        }
        dist[s] = 0;

        priority_queue<P, vector<P>, greater<P>> que;
        que.emplace(0, s);

        while (!que.empty()) {
            P p = que.top();
            que.pop();

            auto cost = p.first;
            auto v = p.second;

            if (dist[v] < cost) continue;

            for (auto e: edges[v]) {
                if (dist[e.to] > dist[v] + e.cost) {
                    dist[e.to] = dist[v] + e.cost;
                    que.emplace(dist[e.to], e.to);
                    ids[e.to] = e.id;
                }
            }
        }
    }
};

void _main() {
    int N, M;
    cin >> N >> M;

    Graph G(N);
    REP(i, M) {
        int a,b,c;
        cin >> a >> b >> c;
        --a; --b;
        G.add_edge(a, b, c, i+1);
        G.add_edge(b, a, c, i+1);
    }

    G.dijkstra(0);

    REP(i, N) {
        if (G.ids[i] == -1) continue;
        cout << G.ids[i] << " ";
    }
    cout << endl;
}

int main() {
    _main();
    return 0;
}

