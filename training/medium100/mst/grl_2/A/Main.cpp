#include <bits/stdc++.h>
#include <queue>
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

struct UnionFind {
    int n;
    vector<int> par;

    UnionFind(int n): n(n) {
        par.resize(n);
        REP(i, n) par[i] = i;
    }

    int root(int a) {
        if (par[a] == a) return a;
        return par[a] = root(par[a]);
    }

    int same(int a, int b) {
        return root(a) == root(b);
    }

    void merge(int a, int b) {
        auto x = root(a);
        auto y = root(b);
        if (x == y) return;
        par[x] = y;
    }
};

using P = pair<int, pair<int,int>>;

void _main() {
    int V, E;
    cin >> V >> E;

    UnionFind uf(V);
    priority_queue<P, vector<P>, greater<P>> que;

    REP(i, E) {
        int s, t, w;
        cin >> s >> t >> w;
        pair<int,int> e = {s,t};
        que.emplace(w, e);
    }

    int ans = 0;
    while (!que.empty()) {
        P p = que.top();
        que.pop();

        auto w = p.first;
        auto s = p.second.first;
        auto t = p.second.second;

        if (uf.same(s,t)) continue;
        ans += w;
        uf.merge(s,t);
    }
    cout << ans << endl;
}

int main() {
    _main();
    return 0;
}

