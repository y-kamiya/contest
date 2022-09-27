#include <algorithm>
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

using Graph = vector<vector<int>>;

struct SCC {
    int n;
    Graph G, rG;
    vector<int> order, group;
    vector<bool> used;

    void dfs(int v) {
        used[v] = 1;
        for (auto nv : G[v]) {
            if (!used[nv]) dfs(nv);
        }
        order.push_back(v);
    }

    void rdfs(int v, int k) {
        group[v] = k;
        for (auto nv : rG[v]) {
            if (group[nv] < 0) rdfs(nv, k);
        }
    }

    SCC(Graph &graph) {
        n = graph.size();
        G = graph;
        rG.resize(n);
        group.assign(n, -1);
        used.resize(n);

        REP(v, n) {
            for (auto nv : G[v]) rG[nv].push_back(v);
        }
        REP(v, n) if (!used[v]) dfs(v);

        int k = 0;
        reverse(ALL(order));
        for (auto v : order) {
            if (group[v] == -1) rdfs(v, k), ++k;
        }
    }

    bool is_same(int u, int v) {
        return group[u] == group[v];
    }

    Graph build() {
        int N = *max_element(ALL(group)) + 1;
        Graph dag(N);
        set<pair<int, int>> connected;

        REP(v, N) {
            for (auto nv : G[v]) {
                if (group[v] == group[nv]) continue;
                if (connected.count({v, nv})) continue;
                connected.insert({v, nv});
                dag[group[v]].push_back(group[nv]);
            }
        }
        return dag;
    }
};

void _main() {
    int V, E;
    cin >> V >> E;

    Graph G(V);
    REP(i, E) {
        int s,t; cin >> s >> t;
        G[s].push_back(t);
    }

    SCC scc(G);

    int Q;
    cin >> Q;
    REP(i, Q) {
        int u,v; cin >> u >> v;
        cout << scc.is_same(u, v) << endl;
    }

}

int main() {
    _main();
    return 0;
}

