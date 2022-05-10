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

class UnionFind {
    vector<int> p;
public:
    UnionFind(int size): p(size) {
        REP(i, size) p[i] = i;
    }

    int root(int a) {
        if (a == p[a]) return a;
        return p[a] = root(p[a]);
    }

    bool same(int a, int b) {
        return root(a) == root(b);
    }

    void merge(int a, int b) {
        int x = root(a);
        int y = root(b);
        if (x != y) p[x] = y;
    }
};


void _main() {
    int n = 3;
    UnionFind uf(n);

    auto is_same = uf.same(0, 2);
    cout << "0, 2: " << is_same << endl;
    assert(!is_same);

    uf.merge(0,1);
    uf.merge(1,2);

    is_same = uf.same(0, 2);
    cout << "0, 2: " << is_same << endl;
    assert(is_same);
}

int main() {
    _main();
    return 0;
}

