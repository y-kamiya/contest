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

int dfs(const Graph &G, int v, vector<int> &d, vector<int> &f, int t=1, int p=-1) {
    if (d[v] != 0) return t-1;
    d[v] = t;
    for (auto nv : G[v]) {
        if (nv == p) continue;
        t = dfs(G, nv, d, f, t+1, v);
    }

    ++t;
    f[v] = t;

    return t;
}

void _main() {
    int N;
    cin >> N;

    Graph G(N+1);

    REP(i, N) {
        int u, k; cin >> u >> k;
        REP(j, k) {
            int v; cin >> v;
            G[u].push_back(v);
        }
    }

    vector<int> d(N+1, 0), f(N+1, 0);
    int t = 0;
    FOR(u, 1, N+1) {
        t = dfs(G, u, d, f, t+1);
    }

    FOR(i, 1, N+1) {
        cout << i << " " << d[i] << " " << f[i] << endl;
    }
}

int main() {
    _main();
    return 0;
}

