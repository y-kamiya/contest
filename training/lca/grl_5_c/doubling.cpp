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

class LCA {
    static constexpr int NONE = -1;
    vector<int> dist;
    vector<vector<int>> parent;
public:
    LCA(const Graph &G, int root=0) {
        int V = G.size();
        int K = 1;
        while ((1<<K) < V) ++K;

        dist.assign(V, NONE);
        parent.assign(K, vector<int>(V, NONE));

        dfs(G, root);

        REP(k, K-1) {
            REP(v, V) {
                int pv = parent[k][v];
                if (pv == NONE) {
                    parent[k+1][v] = NONE;
                } else {
                    parent[k+1][v] = parent[k][pv];
                }
            }
        }
    }

    void dfs(const Graph &G, int v, int d=0, int p=NONE) {
        dist[v] = d;
        parent[0][v] = p;
        for (auto nv : G[v]) {
            if (nv == p) continue;
            dfs(G, nv, d+1, v);
        }
    }

    int query(int u, int v) {
        if (dist[u] < dist[v]) swap(u, v);
        int K = parent.size();

        int diff = dist[u] - dist[v];
        REP(k, K) {
            if (diff >> k & 1) u = parent[k][u];
        }

        if (u == v) return u;

        FORR(k, K-1, 0) {
            if (parent[k][u] == parent[k][v]) continue;
            u = parent[k][u];
            v = parent[k][v];
        }
        return parent[0][u];
    }
};

void _main() {
    int n;
    cin >> n;

    Graph G(n);
    REP(i, n) {
        int c, k; cin >> k;
        REP(j, k) {
            cin >> c;
            G[i].push_back(c);
        }
    }

    LCA lca(G);
    int q, u, v; cin >> q;
    REP(i, q) {
        cin >> u >> v;
        cout << lca.query(u, v) << endl;
    }
}

int main() {
    _main();
    return 0;
}

