#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
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

static const int INF = INT_MAX;
using Graph = vector<vector<int>>;

void dfs(const Graph &G, vector<int> &dist, int v, int d=0, int p=-1) {
    if (dist[v] != INF) return;
    dist[v] = d;
    if (G[v].size() == 1 && G[v][0] == p) return;

    for (auto nv : G[v]) {
        if (nv == p) continue;
        dfs(G, dist, nv, d+1, v);
    }
}

void _main() {
    int N;
    cin >> N;

    Graph G(N);
    REP(i, N-1) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> dist(N, INF);
    dfs(G, dist, 0);

    auto it = max_element(ALL(dist));
    int max_v = distance(dist.begin(), it);

    REP(i, N) dist[i] = INF;
    dfs(G, dist, max_v);

    auto iter = max_element(ALL(dist));

    cout << *iter + 1 << endl;
}


int main() {
    _main();
    return 0;
}

// AC 38min
// 25minほど考えてNlogN以下で計算できる方法が浮かばないためググって調査
// 木の直径という話でO(N)で見つけられることが判明
// https://algo-logic.info/tree-diameter/
// 全頂点対に対して距離を調べないとわからないと思ったが、最長距離を2回たどるだけでOK

