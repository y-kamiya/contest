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
    int R, C;
    cin >> R >> C;

    vector<vector<int>> a(R, vector(C, 0));
    REP(i, R) REP(j, C) cin >> a[i][j];

    vector<int> b(C, 0);
    REP(j, C) REP(i, R) {
        if (a[i][j] == 1) b[j] += 1<<i; 
    }

    int ans = 0;
    REP(k, 1<<R) {
        int m = 0;
        REP(j, C) {
            auto v = k ^ b[j];
            auto c = __builtin_popcount(v);
            m += max(c, R-c);
        }
        ans = max(ans, m);
    }

    cout << ans << endl;
}

int main() {
    _main();
    return 0;
}

// AC 25
