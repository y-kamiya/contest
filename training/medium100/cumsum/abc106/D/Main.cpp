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


void _main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<vector<int>> a(N+1, vector(N+1, 0));
    REP(i, M) {
        int l, r; cin >> l >> r;
        ++a[l][r];
    }

    vector<vector<int>> b(N+1, vector(N+1, 0));
    FOR(i, 1, N+1) {
        FOR(j, 1, N+1) {
            b[i][j] += b[i][j-1] + a[i][j];
            DEBUG(i, j, a[i][j], b[i][j]);
        }
    }

    REP(i, N+1) DEBUG(a[i]);
    REP(i, N+1) DEBUG(b[i]);
    REP(i, Q) {
        int p, q; cin >> p >> q;
        int ans = 0;
        FOR(j, p, q+1) {
            ans += b[j][q];
        }
        cout << ans << endl;
    }
}

int main() {
    _main();
    return 0;
}

