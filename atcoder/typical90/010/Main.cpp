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

    const T empty = 0;
    T op(T lhs, T rhs) const {
        return lhs + rhs;
    }
    void update_leaf(T &leaf, T val) {
        leaf += val;
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


void _main() {
    int N;
    cin >> N;

    SegmentTree<int> seg1(N);;
    SegmentTree<int> seg2(N);

    int c, p;
    REP(i, N) {
        cin >> c >> p;
        if (c == 1) {
            seg1.update(i, p);
            seg2.update(i, 0);
        } else {
            seg1.update(i, 0);
            seg2.update(i, p);
        }
    }

    int Q;
    cin >> Q;

    int l, r;
    REP(i, Q) {
        cin >> l >> r;
        --l; --r;
        int sum1 = seg1.query(l, r+1);
        int sum2 = seg2.query(l, r+1);
        cout << sum1 << " " << sum2 << endl;
    }

}

int main() {
    _main();
    return 0;
}

// AC 13min
// segtreeはlibaryからコピー、の割には時間がかかった

