#include <bits/stdc++.h>
using namespace std;

class ostreamFork {
public:
    ostream &os1,&os2;
    ostreamFork(ostream& os1, ostream& os2) : os1(os1), os2(os2) {}
};
template <class Data>
ostreamFork& operator<<(ostreamFork& osf, Data d) {
    osf.os1 << d; osf.os2 << d; return osf;
}
ostreamFork& operator<<(ostreamFork& osf, ostream& (*f)(ostream&)) {
    osf.os1 << f; osf.os2 << f; return osf;
}
template <class ManipData>
ostreamFork& operator<<(ostreamFork& osf, ostream& (*f)(ostream&, ManipData)) {
    osf.os1 << f; osf.os2 << f; return osf;
}

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
template<typename T0, typename T1, typename... Tail>
void print(pair<T0,T1> p, Tail... t) {
    cout << "(" << p.first << "," << p.second << ")";
    print(t...);
}
template<typename T, typename... Tail>
void print(vector<T> vec, Tail... t) {
    cout << "["; for (const auto &e : vec) { cout << e << ", "; } cout << "] ";
    print(t...);
}
#ifdef _DEBUG
#define DEBUG(...) print(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

ofstream file("_output.txt");
ostreamFork osf(file, cout);

template<typename T>
class SegmentTree {
    int n = 1;
    vector<T> tree;

    const T empty = -1;
    T op(T lhs, T rhs) const {
        return max(lhs, rhs);
    }
    void update_leaf(T &leaf, T val) {
        leaf = val;
    }

public:
    SegmentTree(int size) {
        while (n < size) n *= 2;
        tree.resize(2*n-1, empty);
    }

    SegmentTree<T> &operator=(const SegmentTree<T> &r) {
        n = r.n;
        tree = r.tree;
        return *this;
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
    int W,N;
    cin >> W >> N;

    vector<ll> L(N), R(N), V(N);
    REP(i, N) cin >> L[i] >> R[i] >> V[i];

    SegmentTree<ll> seg(W+1), prev(W+1);
    seg.update(0, 0);
    prev.update(0, 0);
    // vector<vector<ll>> dp(N+1, vector(W+1, 0ll));
    FOR(i, 0, N) {
        FOR(j, 1, W+1) {
            // auto x = L[i];
            // if (j < x) continue;
            // dp[i+1][j] = max(dp[i][j], dp[i][j-x] + V[i]);

            auto l = max(0ll, j-R[i]);
            auto r = j-L[i];
            if (r < 0) continue;
            auto v = prev.query(l, r+1);
            if (v == -1) continue;
            seg.update(j, max(prev.query(j, j+1), v + V[i]));
        }
        prev = seg;

#ifdef _DEBUG
        vector<ll> a(W+1);
        REP(i, W+1) a[i] = prev.query(i, i+1);
        DEBUG(a);
#endif
    }

    ll ans = seg.query(W, W+1);
    osf << ans << endl;
}

int main() {
    _main();
    return 0;
}

