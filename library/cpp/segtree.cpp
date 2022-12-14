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


template<typename T>
class SegmentTree {
    int n = 1;
    vector<T> tree;

    const T empty = INT_MAX;
    T op(T lhs, T rhs) const {
        return min(lhs, rhs);
    }
    void update_leaf(T &leaf, T val) {
        leaf = val;
    }

public:
    SegmentTree(int size) {
        while (n < size) n *= 2;
        tree.resize(2*n-1, empty);
    }

    void update(int x, T val) {
        x += (n-1);
        update_leaf(tree[x], val);
        while (x > 0) {
            x = (x-1)/2;
            tree[x] = op(tree[2*x+1], tree[2*x+2]);
        }
    }

    T query(int a, int b, int k=0, int l=0, int r=-1) {
        if (r < 0) r = n;
        if (b <= l || r <= a) return empty;
        if (a <= l && r <= b) return tree[k];

        int mid = (l+r)/2;
        auto vl = query(a, b, 2*k+1, l, mid);
        auto vr = query(a, b, 2*k+2, mid, r);
        return op(vl, vr);
    }
};

template<typename T>
class SegmentTreeLazy {
    ll n = 1;
    vector<ll> tree;
    vector<ll> lazy;

    T empty = 0;
    T op(T a, T b) {
        return a + b;
    }
    void _update(T &x, T val, T factor=1) {
        x += val * factor;
    }
    void _update_child(T &x, T val) {
        x += val / 2;
    }

public:
    SegmentTreeLazy(ll size) {
        while (n < size) n <<= 1;
        tree.resize(2*n-1, empty);
        lazy.resize(2*n-1, empty);
    }

    void eval(ll k, ll l, ll r) {
        if (lazy[k] == empty) return;

        _update(tree[k], lazy[k]);
        if (r-l > 1) {
            _update_child(lazy[2*k+1], lazy[k]);
            _update_child(lazy[2*k+2], lazy[k]);
        }

        lazy[k] = empty;
    }

    void update(ll a, ll b, ll x, ll k=0, ll l=0, ll r=-1) {
        if (r < 0) r = n;
        eval(k, l, r);
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            _update(lazy[k], x, r-l);
            eval(k, l, r);
        } else {
            ll mid = (l+r)/2;
            update(a, b, x, 2*k+1, l, mid);
            update(a, b, x, 2*k+2, mid, r);
            tree[k] = op(tree[2*k+1], tree[2*k+2]);
        }
    }

    T query(ll a, ll b, ll k=0, ll l=0, ll r=-1) {
        if (r < 0) r = n;
        eval(k, l, r);
        if (b <= l || r <= a) return empty;
        if (a <= l && r <= b) return tree[k];

        ll mid = (l+r)/2;
        auto vl = query(a, b, 2*k+1, l, mid);
        auto vr = query(a, b, 2*k+2, mid, r);
        return op(vl, vr);
    }
};

void _main() {
    vector<int> vec{1,2,3,4,5};
    SegmentTree<int> seg(vec.size());
    REP(i, vec.size()) {
        seg.update(i, vec[i]);
    }

    auto v1 = seg.query(0, vec.size());
    cout << v1 << endl;
    assert(v1 == 1);

    seg.update(0, 5);
    auto v2 = seg.query(0, vec.size());
    cout << v2 << endl;
    assert(v2 == 2);


    SegmentTreeLazy<ll> seglazy(vec.size());
    REP(i, vec.size()) {
        seglazy.update(i, i+1, vec[i]);
    }
    auto v11 = seglazy.query(0, vec.size());
    cout << v11 << endl;;
    assert(v11 == 15);

    int s = 1, t = 3;
    seglazy.update(s, t+1, 2);
    auto v12 = seglazy.query(0, vec.size());
    cout << v12 << endl;
    assert(v12 == 21);
}

int main() {
    _main();
    return 0;
}

