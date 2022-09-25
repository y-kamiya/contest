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

bool dfs(const Graph& G, int X, int Y, vector<int>& ans, int p = -1) {
    DEBUG(X, p);
    if (X == Y) {
        return true;
    }

    for (auto v : G[X]) {
        if (v == p) continue;
        auto ok = dfs(G, v, Y, ans, X);
        if (ok) {
            ans.push_back(v);
            return true;
        }
    }

    return false;
}

void _main() {
    int N, X, Y;
    cin >> N >> X >> Y;
    --X, --Y;

    Graph G(N);
    REP(i, N-1) {
        int u,v; cin >> u >> v;
        --u; --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    DEBUG("========================");
    REP(i, N) DEBUG(G[i]);

    vector<int> ans;
    dfs(G, X, Y, ans);

    DEBUG(ans);
    cout << X+1 << " ";
    FORR(i, ans.size()-1, 0) {
        cout << ans[i]+1 << " ";
    }
    cout << endl;
}

int main() {
    _main();
    return 0;
}

