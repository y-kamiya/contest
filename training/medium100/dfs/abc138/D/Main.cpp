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

void dfs(const Graph &G, int v, int s, const vector<int> &a, vector<int> &b, int p=-1) {
    s += a[v];
    b[v] += s;
    for (auto nv: G[v]) {
        if (nv == p) continue;
        dfs(G, nv, s, a, b, v);
    }
}

void _main() {
    int N, Q;
    cin >> N >> Q;

    Graph G(N);
    REP(i, N-1) {
        int a, b; cin >> a >> b;
        --a; --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> a(N, 0);
    REP(i, Q) {
        int p, x; cin >> p >> x;
        --p;
        a[p] += x;
    }

    vector<int> b(N);
    dfs(G, 0, 0, a, b);

    REP(i, N) {
        cout << b[i] << " ";
    }
    cout << endl;
}

int main() {
    _main();
    return 0;
}

// AC 17.5
