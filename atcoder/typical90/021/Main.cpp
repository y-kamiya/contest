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
            if (group[nv] == -1) rdfs(nv, k);
        }
    }

    SCC(Graph &graph) {
        n = graph.size();
        G = graph;
        rG.resize(n);
        order.resize(n);
        group.resize(n, -1);
        used.resize(n, false);

        REP(v, n) {
            if (!used[v]) dfs(v);
        }
        REP(v, n) {
            for (auto nv : G[v]) rG[nv].push_back(v);
        }

        reverse(ALL(order));
        int k = 0;
        REP(i, n) {
            auto v = order[i];
            if (group[v] == -1) {
                rdfs(v, k);
                ++k;
            }
        }
    }
};

void _main() {
    int N, M;
    cin >> N >> M;

    vector<set<int>> _G(N);
    REP(i, M) {
        int A, B; cin >> A >> B;
        --A; --B;
        _G[A].insert(B);
    }

    Graph G(N);
    REP(i, N) {
        vector<int> vec(ALL(_G[i]));
        G[i] = vec;
    }

    SCC scc(G);
    int sz = *max_element(ALL(scc.group)) + 1;
    vector<int> count(sz, 0);
    REP(i, N) {
        count[scc.group[i]]++;
    }

    ll ans = 0;
    REP(k, sz) {
        ll c = count[k];
        ans += c * (c-1) / 2;
    }

    cout << ans << endl;


}

int main() {
    _main();
    return 0;
}

