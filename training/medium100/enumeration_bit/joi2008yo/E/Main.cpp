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
    vector<vector<int>> A(R, vector(C, 0));
    REP(i, R) REP(j, C) cin >> A[i][j];


    int ans = 0;
    REP(i, 1<<R) {
        REP(j, R) REP(k, C) a[j][k] = A[j][k];
        REP(j, R) {
            if (i>>j & 1) {
                REP(k, C) a[j][k] = 1-a[j][k];
            }
        }

        int sum = 0;
        REP(j, C) {
            int b = 0;
            REP(k, R) b += a[k][j];
            sum += (b * 2 > R) ? b : R-b;
            DEBUG("b", b);
        }
        DEBUG(sum);
        ans = max(ans, sum);
    }

    cout << ans << endl;
}

int main() {
    _main();
    return 0;
}

// AC 27
// debugに5くらい




// 列毎の初期値をintとして持ち、xorを使うことで簡単にかける
void __main() {
    int R, C;
    cin >> R >> C;

    vector<int> a(C, 0);
    REP(i, R) REP(j, C) {
        int x; cin >> x;
        if (x == 1) a[j] += 1<<i;
    }

    int ans = 0;
    REP(i, 1<<R) {
        int sum = 0;
        REP(c, C) {
           auto count = __builtin_popcount(i ^ a[c]);
           sum += max(count, R - count);
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
}
