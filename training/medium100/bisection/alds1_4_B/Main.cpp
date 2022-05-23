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
    int n, q;
    cin >> n;

    vector<int> S(n);
    REP(i, n) cin >> S[i];

    cin >> q;
    int ans = 0;
    REP(i, q) {
        int x; cin >> x;
        auto itl = lower_bound(ALL(S), x);
        auto l = distance(S.begin(), itl);
        auto itr = upper_bound(ALL(S), x);
        auto r = distance(S.begin(), itr);
        DEBUG(l, r);
        if (r-l > 0) ++ans;
    }
    cout << ans << endl;

}

int main() {
    _main();
    return 0;
}

// AC 7.5

