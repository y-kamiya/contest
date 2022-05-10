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
    vector<int> p;

    UnionFind(int size): p(size) {
        REP(i, size) p[i] = i;
    }

    int root(int a) {
        if (a == p[a]) return a;
        return p[a] = root(p[a]);
    }

    bool same(int a, int b) {
        int x = root(a);
        int y = root(b);
        if (x == y) return true;
        return false;
    }

    void merge(int a, int b) {
        int x = root(a);
        int y = root(b);
        if (x == y) return;
        p[x] = y;
    }
};

int projection(int h, int w, int W) {
    return h * W + w;
}

void _main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    int M = H*W;
    UnionFind uf(M);
    vector<int> color(M, 0);

    int t, ra, ca, rb, cb;
    REP(i, Q) {
        cin >> t;
        if (t == 1) {
            cin >> ra >> ca;
            --ra; --ca;
            auto cur = projection(ra, ca, W);
            auto u = projection(ra-1, ca, W);
            auto r = projection(ra, ca+1, W);
            auto b = projection(ra+1, ca, W);
            auto l = projection(ra, ca-1, W);
            color[cur] = 1;
            if (0 < ra && color[cur] == color[u]) uf.merge(cur, u);
            if (ca < W-1 && color[cur] == color[r]) uf.merge(cur, r);
            if (ra < H-1 && color[cur] == color[b]) uf.merge(cur, b);
            if (0 < ca && color[cur] == color[l]) uf.merge(cur, l);
        } else {
            cin >> ra >> ca >> rb >> cb;
            --ra; --ca; --rb; --cb;
            auto a = ra*W+ca;
            auto b = rb*W+cb;
            Yes(color[a] == 1 && color[b] == 1 && uf.same(a, b));
        }
    }
}

int main() {
    _main();
    return 0;
}

// AC 45min
// WA&RE 22min fieldの範囲外の判定を忘れ
// WA 33min 2次元上での範囲外判定が必要なことに気づく
