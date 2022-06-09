#include <bits/stdc++.h>
#include <climits>
#include <iterator>
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

static const int INF = INT_MAX/2;
void _main() {
    int N;
    cin >> N;

    vector<int> c(N);
    REP(i, N) cin >> c[i];

    vector<int> dp(N, INF);
    int p = 0;
    REP(i, N) {
        if (c[i] > dp[p]) {
            ++p;
            dp[p] = c[i];
        } else {
            auto it = lower_bound(dp.begin(), dp.begin()+p, c[i]);
            *it = c[i];
        }
    }

    cout << N-(p+1) << endl;

}

int main() {
    _main();
    return 0;
}

