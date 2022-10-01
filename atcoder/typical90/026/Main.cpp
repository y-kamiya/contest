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

void dfs(const Graph &G, vector<int> &color, int v, int p, int c) {
    color[v] = c;
    for (auto nv : G[v]) {
        if (nv == p) continue;
        if (color[nv] != -1) continue;
        dfs(G, color, nv, v, 1-c);
    }
}

void _main() {
    int N;
    cin >> N;

    Graph G(N);
    REP(i, N-1) {
        int a,b; cin >> a >> b;
        --a; --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> color(N, -1);
    dfs(G, color, 0, -1, 0);

    vector<vector<int>> c(2);
    REP(i, N) {
        if (color[i] == 0) c[0].push_back(i+1);
        else c[1].push_back(i+1);
    }
    
    int clr = 0;
    if (c[0].size() < N/2) clr = 1;

    REP(i, N/2) {
        cout << c[clr][i] << " " << endl;
    }


}

int main() {
    _main();
    return 0;
}

