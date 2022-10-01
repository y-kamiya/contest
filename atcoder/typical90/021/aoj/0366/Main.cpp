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
        used[v] = true;
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
        G = graph;
        n = G.size();
        rG.resize(n);
        group.resize(n, -1);
        used.resize(n);

        REP(i, n) {
            for (auto nv : G[i]) rG[nv].push_back(i);
        }
        REP(v, n) {
            if (!used[v]) dfs(v);
        }

        int k = 0;
        REP(i, n) {
            auto v = order[n-i-1];
            if (group[v] < 0) {
                rdfs(v, k);
                ++k;
            }
        }
    }
    Graph rebuild() {
        int N = *max_element(ALL(group)) + 1;
        Graph dag(N);
        set<pair<int,int>> connected;

        REP(v, n) {
            auto gv = group[v];
            for (auto nv : G[v]) {
                auto gnv = group[nv];
                if (gv == gnv) continue;
                if (connected.count({gv, gnv})) continue;
                connected.insert({gv, gnv});
                dag[gv].push_back(gnv);
            }
        }
        return dag;
    }
};

void _main() {
    int N, M;
    cin >> N >> M;

    Graph G(N);
    REP(i, M) {
        int s,t; cin >> s >> t;
        G[s].push_back(t);
    }

    SCC scc(G);
    auto dag = scc.rebuild();
    int n_dag = dag.size();
    if (n_dag == 1) {
        cout << 0 << endl;
        return;
    }
    REP(i, n_dag) DEBUG(dag[i]);

    vector<int> in_count(n_dag);
    REP(v, n_dag) {
        for (auto nv : dag[v]) in_count[nv]++;
    }

    int in = 0;
    REP(v, n_dag) {
        if (in_count[v] == 0) ++in;
    }

    int out = 0;
    REP(v, n_dag) {
        if (dag[v].size() == 0) ++out;
    }

    cout << max(in, out) << endl;
}

int main() {
    _main();
    return 0;
}

