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
            if (group[nv] < 0) {
                rdfs(nv, k);
            }
        }
    }

    SCC(Graph &graph) {
        n = graph.size();
        G = graph;
        rG.resize(n);
        group.resize(n, -1);
        used.resize(n, false);

        REP(v, n) {
            if (!used[v]) {
                dfs(v);
            }
        }
        REP(v, n) {
            for (auto nv : G[v]) rG[nv].push_back(v);
        }
        reverse(ALL(order));

        int k = 0;
        REP(i, n) {
            auto v = order[i];
            if (group[v] < 0) {
                rdfs(v, k);
                ++k;
            }
        }
    }

    Graph rebuild() {
        int N = *max_element(ALL(group)) + 1;
        Graph dag(N);
        set<pair<int, int>> connected;

        REP(v, n) {
            for (auto nv : G[v]) {
                auto gv = group[v];
                auto gnv = group[nv];
                if (gv == gnv) continue;
                if (connected.count({gv, gnv})) continue;
                connected.insert({gv, gnv});
                dag[gv].push_back(gnv);
            }
        }
        return dag;
    }

    int calc() {
        int N = *max_element(ALL(group)) + 1;
        vector<vector<ll>> g_g(N);
        reverse(order.begin(), order.end());
        // for (int i : order) {
        REP(i, n) {
            g_g.at(group.at(i)).push_back(i);
        }
        REP(i, N) DEBUG(g_g[i]);

        ll ans = 0;
        for (int i = 0; i < N; i++) {
            bool flag = true;
            for (ll v : g_g.at(i)) {
                for (ll nv : rG.at(v)) {
                    flag &= (group.at(v) == group.at(nv));
                }
            }
            if (flag) {
                DEBUG("----", i);
                ans++;
            }
        }
        return ans;
    }
};

/*
void dfs(const Graph &G, int v, vector<bool> &used) {
    used[v] = true;
    for (auto nv : G[v]) {
        if (!used[nv]) dfs(G, nv, used);
    }
}
*/

void _main() {
    int N, M;
    cin >> N >> M;

    Graph G(N);
    REP(i, M) {
        int a, b; cin >> a >> b;
        --a; --b;
        G[a].push_back(b);
    }

    SCC scc(G);
    auto dag = scc.rebuild();

    vector<int> count(dag.size(), 0);
    REP(i, dag.size()) {
        for (auto v : dag[i]) {
            count[v]++;
        }
    }
    int ans = 0;
    REP(i, dag.size()) if (count[i] == 0) ++ans;

    cout << ans << endl;

    // cout << scc.calc() << endl;

    /*
    SCC scc2(dag);
    int ans = 0;
    REP(i, dag.size()) {
        if (scc2.rG[i].size() == 0) ++ans;
    }
    cout << ans << endl;
    */

    /*
    SCC scc2(dag);
    vector<bool> used(dag.size(), false);
    int ans = 0;
    for (auto v : scc2.order) {
        if (!used[v]) {
            dfs(dag, v, used);
            ++ans;
        }
    }
    cout << ans << endl;
    */
}

int main() {
    _main();
    return 0;
}

