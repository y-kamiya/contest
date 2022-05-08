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
    vector<vector<int>> table;
    const vector<T> vec;

    int op(int i1, int i2) const {
        return vec[i1] < vec[i2] ? i1 : i2;
    }
public:
    SparseTable(const vector<T> &v): n((int)v.size()), log(n+1, 0), vec(v) {
        FOR(i, 2, n+1) log[i] = log[i>>1] + 1;
        table.resize(log[n]+1, vector<int>(n));

        REP(i, n) table[0][i] = i;
        for(int k=1; k <= log[n]; ++k) {
            for(int i=0; i+(1<<k) <= n; ++i) {
                table[k][i] = op(table[k-1][i], table[k-1][i+(1<<(k-1))]);
            }
        }
    }

    int query(int l, int r) const {
        int k = log[r-l];
        return op(table[k][l], table[k][r-(1<<k)]);
    }
};

void _main() {
    vector<int> vec{3, 5, 2, 7, 1, 4, 6};
    SparseTable<int> table(vec);

    int l = 0;
    int r = vec.size();
    auto index = table.query(l, r);

    cout << index << endl;
    assert(index == 4);
    cout << vec[index] << endl;
    assert(vec[index] == 1);
}

int main() {
    _main();
    return 0;
}

