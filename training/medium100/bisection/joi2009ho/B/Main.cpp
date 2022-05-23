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
    int D, n, m;
    cin >> D >> n >> m;

    vector<int> d(n, 0), k(m, 0);
    FOR(i, 1, n) cin >> d[i];
    REP(i, m) cin >> k[i];

    sort(ALL(d));

    int ans = 0;
    REP(i, m) {
        auto it = lower_bound(ALL(d), k[i]);
        DEBUG(*it);
        if (it == d.end()) ans += min(D - k[i], k[i]-*(it-1));
        else if (it == d.begin()) ans += 0;
        else {
            ans += min(*it-k[i], k[i]-*(it-1));
        }
    }
    cout << ans << endl;
}

int main() {
    _main();
    return 0;
}

// AC 19.5

