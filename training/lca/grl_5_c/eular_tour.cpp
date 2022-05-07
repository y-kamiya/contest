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

void dfs(const Graph &G, vector<int> &ds, vector<int> &vs, vector<int> &appear, int v, int d=0, int p=-1) {
    if (appear[v] == -1) appear[v] = ds.size();
    ds.push_back(d);
    vs.push_back(v);
    if (G[v].size() == 1 && G[v][0] == p) return;

    for (auto nv : G[v]) {
        if (nv == p) continue;
        dfs(G, ds, vs, appear, nv, d+1, v);
        ds.push_back(d);
        vs.push_back(v);
    }
}

template<typename T>
class SparseTable {
    int n;
    vector<T> values;
    vector<int> log;
    vector<vector<int>> table;

public:
    SparseTable(const vector<T> &v): n((int)v.size()), values(v), log(n+1, 0) {
        FOR(i, 2, n+1) {
            log[i] = log[i>>1] + 1;
        }
        table.resize(log[n]+1, vector<int>(n));

        REP(i, n) {
            table[0][i] = i;
        }
        for(int k=1; k <= log[n]; ++k) {
            for(int i=0; i+(1<<k) <= n; ++i) {
                int index1 = table[k-1][i];
                int index2 = table[k-1][i+(1<<(k-1))];
                table[k][i] = values[index1] < values[index2] ? index1 : index2;
            }
        }
    }

    int query(int l, int r) {
        int k = log[r-l];
        int index1 = table[k][l];
        int index2 = table[k][r-(1<<k)];
        return values[index1] < values[index2] ? index1 : index2;
    }
};

void _main() {
    int n;
    cin >> n;

    Graph G(n);

    REP(i, n) {
        int k; cin >> k;
        REP(j, k) {
            int c; cin >> c;
            G[i].push_back(c);
        }
    }

    vector<int> ds, vs, appear(n, -1);
    dfs(G, ds, vs, appear, 0);

    DEBUG(ds);
    DEBUG(vs);
    DEBUG(appear);
    SparseTable table(ds);

    int q; cin >> q;
    REP(i, q) {
        int u, v;
        cin >> u >> v;

        int iu = appear[u];
        int iv = appear[v];
        int l = min(iu, iv);
        int r = max(iu, iv);

        int index = table.query(l, r+1);
        cout << vs[index] << endl;
    }
}

int main() {
    _main();
    return 0;
}

