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

struct UnionFind {
    vector<int> p;

    UnionFind(int size) {
        p.resize(size);
        REP(i, size) p[i] = i;
    }

    int root(int a) {
        if (a == p[a]) return a;
        return p[a] = root(p[a]);
    }

    bool same(int a, int b) {
        auto x = root(a);
        auto y = root(b);
        if (x == y) return true;
        return false;
    }

    void merge(int a, int b) {
        auto x = root(a);
        auto y = root(b);
        if (x == y) return;
        p[x] = y;
    }
};

using Edge = pair<pair<int,int>, pair<int, int>>;

// static const ll INF = 1ll<<61;
// using P = pair<ll, ll>;
// struct E {
//     ll to, cost;
// };
// struct Graph {
//     ll n;
//     vector<vector<E>> edges;
//     vector<ll> dist;
//
//     Graph(ll size) {
//         n = size;
//         edges.resize(n);
//         dist.resize(n, INF);
//     }
//
//     void add_edge(ll s, ll t, ll cost) {
//         E e{t, cost};
//         edges[s].push_back(e);
//     }
//
//     void dijkstra(ll s) {
//         REP(i, n) dist[i] = INF;
//         dist[s] = 0;
//
//         priority_queue<P, vector<P>, greater<P>> que;
//         que.push({0, s});
//
//         while (!que.empty()) {
//             P p = que.top();
//             que.pop();
//
//             auto cost = p.first;
//             auto v = p.second;
//
//             if (dist[v] < cost) continue;
//
//             for (const auto &e : edges[v]) {
//                 DEBUG(v, e.to, e.cost, dist[e.to]);
//                 if (dist[e.to] > dist[v] + e.cost) {
//                     DEBUG(dist[e.to], dist[v], e.cost);
//                     dist[e.to] = dist[v] + e.cost;
//                     que.push({e.cost, e.to});
//                 }
//             }
//         }
//
//     }
// };

void _main() {
    int N, M;
    cin >> N >> M;

    UnionFind uf(N);
    priority_queue<Edge, vector<Edge>, greater<Edge>> que;

    REP(i, M) {
        int s, t, w;
        cin >> s >> t >> w;
        --s; --t;
        Edge e = {{w, i}, {s, t}};
        que.push(e);
    }

    vector<Edge> edges;

    while (!que.empty()) {
        Edge e = que.top();
        que.pop();
        auto w = e.first.first;
        auto s = e.second.first;
        auto t = e.second.second;

        if (uf.same(s, t)) continue;
        uf.merge(s, t);
        edges.push_back(e);
    }

    REP(i, edges.size()) {
        cout << edges[i].first.second+1 << " "; 
    }
    cout << endl;



    // Graph G(N);
    // REP(i, edges.size()) {
    //     auto e = edges[i];
    //     auto w = e.first;
    //     auto s = e.second.first;
    //     auto t = e.second.second;
    //     G.add_edge(s, t, w);
    //     G.add_edge(t, s, w);
    // }
    //
    // G.dijkstra(0);
    //
    // ll ans = 0;
    // FOR(i, 1, N) {
    //     ans += G.dist[i];
    // }
    // cout << ans << endl;

}

int main() {
    _main();
    return 0;
}

