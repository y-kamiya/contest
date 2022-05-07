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

template<typename T>
class SparseTable {
    int n;
    vector<int> log_table;
    vector<vector<T>> table;

public:
    SparseTable(const vector<T> &v): n((int)v.size()), log_table(n+1, 0) {
        FOR(i, 2, n+1) {
            log_table[i] = log_table[i>>1] + 1;
        }
        table.resize(log_table[n]+1, vector<T>(n));

        REP(i, n) {
            table[0][i] = v[i];
        }
        for (int k=1; (1<<k) <= n; ++k) {
            for (int i = 0; i+(1<<k) <= n; ++i) {
                table[k][i] = min(table[k-1][i], table[k-1][i+(1<<(k-1))]);
            }
        }
    }

    T query(int l, int r) {
        int k = log_table[r-l];
        return min(table[k][l], table[k][r-(1<<k)]);
    }

};

void dfs(const Graph &G, vector<pair<int, int>> &tour, vector<int> &appear, int v, int d=0, int p=-1) {
    if (appear[v] == -1) appear[v] = tour.size();
    tour.emplace_back(d, v);
    if (G[v].size() == 1 && G[v][0] == p) return;

    for (auto nv : G[v]) {
        if (nv == p) continue;
        dfs(G, tour, appear, nv, d+1, v);
        tour.emplace_back(d, v);
    }

}

void _main() {
    int N;
    cin >> N;

    Graph G(N);
    REP(i, N-1) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    vector<pair<int, int>> tour;
    vector<int> appear(N, -1);
    dfs(G, tour, appear, 0);

    int n_tour = tour.size();
    DEBUG(appear);

    vector<int> ds(n_tour);
    REP(i, n_tour) {
        ds[i] = tour[i].first;
    }
    SparseTable<int> table(ds);

    int Q;
    cin >> Q;

    REP(i, Q) {
        int a, b;
        cin >> a >> b;
        --a; --b;

        int ia = appear[a];
        int ib = appear[b];
        int l = ia < ib ? ia : ib;
        int r = ia < ib ? ib+1 : ia+1;
        int dc = table.query(l, r);
        int da = tour[ia].first;
        int db = tour[ib].first;
        DEBUG(da, db, dc);
        cout << abs(da-dc) + abs(db-dc) + 1 << endl;
    }
}

int main() {
    _main();
    return 0;
}

