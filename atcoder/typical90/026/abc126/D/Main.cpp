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

struct Edge {
    int to, cost;
    Edge(int t, int c): to(t), cost(c) {}
};
using Graph = vector<vector<Edge>>;

void dfs(const Graph &G, vector<int> &color, int v, int c = 0, int p = -1) {
    color[v] = c;
    for (const auto &e : G[v]) {
        if (e.to == p) continue;
        if (color[e.to] != -1) continue;
        int clr = e.cost % 2 == 0 ? c : 1-c;
        dfs(G, color, e.to, clr, v);
    }

}

void _main() {
    int N;
    cin >> N;

    Graph G(N);
    REP(i, N-1) {
        int u,v,w; cin >> u >> v >> w;
        --u; --v;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    vector<int> color(N, -1);
    dfs(G, color, 0);

    REP(i, N) {
        cout << color[i] << endl;
    }
}

int main() {
    _main();
    return 0;
}

