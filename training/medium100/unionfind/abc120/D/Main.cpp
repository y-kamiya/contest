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

struct UnionFind {
    vector<int> par;
    vector<ll> count;
    ll ans = 0;

    UnionFind(ll n) {
        par.resize(n);
        count.resize(n);
        REP(i, n) par[i] = i;
        REP(i, n) count[i] = 1;
        ans = n * (n-1) / 2;
    }

    int root(int a) {
        if (par[a] == a) return a;
        return par[a] = root(par[a]);
    }

    bool same(int a, int b) {
        return root(a) == root(b);
    }

    void merge(int a, int b) {
        auto x = root(a);
        auto y = root(b);
        if (x == y) return;

        
        auto cx = count[x];
        auto cy = count[y];
        ans -= cx * cy;
        ans = max(0ll, ans);
        count[x] = cx + cy;
        DEBUG(a+1, b+1, cx, cy);
        par[y] = x;
    }
};

void _main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(M), B(M);
    REP(i, M) {
        int a, b; cin >> a >> b;
        --a; --b;
        A[i] = a;
        B[i] = b;
    }

    UnionFind uf(N);
    vector<ll> ans(M);
    FORR(i, M-1, 0) {
        ans[i] = uf.ans;
        uf.merge(A[i], B[i]);
    }

    REP(i, M) {
        cout << ans[i] << endl;
    }

}

int main() {
    _main();
    return 0;
}

