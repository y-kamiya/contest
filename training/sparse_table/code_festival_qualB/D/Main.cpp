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
class SparseTable {
    int n;
    vector<int> log;
    vector<vector<T>> table;

    T op(T a, T b) const {
        return max(a, b);
    }
public:
    SparseTable(const vector<T> &v): n((int)v.size()), log(n+1, 0) {
        FOR(i, 2, n+1) {
            log[i] = log[i>>1] + 1;
        }
        table.resize(log[n]+1, vector<T>(n));

        REP(i, n) table[0][i] = v[i];
        for(int k=1; k <= log[n]; ++k) {
            for(int i=0; i+(1<<k) <= n; ++i) {
                table[k][i] = op(table[k-1][i], table[k-1][i+(1<<(k-1))]);
            }
        }
    }

    T query(int l, int r) const {
        int k = log[r-l];
        return op(table[k][l], table[k][r-(1<<k)]);
    }
};

bool is_ok(int l, int r, const SparseTable<int> &table, int thres) {
    int h_max = table.query(l, r);
    return h_max <= thres;

}

int search(int ng, int ok, const SparseTable<int> &table, int thres) {
    int initial = ok;
    while (abs(ok-ng) > 1) {
        int mid = (ng + ok) / 2;
        int l = mid < initial ? mid : initial+1;
        int r = mid < initial ? initial : mid+1;
        if (is_ok(l, r, table, thres)) ok = mid;
        else ng = mid;
    }

    return abs(ok - initial);
}

void _main() {
    int N;
    cin >> N;

    vector<int> h(N);
    REP(i, N) cin >> h[i];

    SparseTable<int> table(h);

    REP(i, N) {
        int west = 0;
        int east = 0;
        if (i != 0) west = search(-1, i, table, h[i]);
        if (i != (N-1)) east = search(N, i, table, h[i]);
        cout << west + east << endl;
    }
}

int main() {
    _main();
    return 0;
}

// AC 53min
// west, eastで開区間の扱いが変わるため苦労
// また、maxではなく元のコードと同じようにminを使ってしまっていたミス

