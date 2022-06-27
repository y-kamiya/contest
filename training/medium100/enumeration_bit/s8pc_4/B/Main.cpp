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
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    REP(i, N) cin >> a[i];

    ll ans = LLONG_MAX/2;
    REP(i, 1<<N) {
        if (__builtin_popcount(i) < K) continue;
        int last = 0;
        ll sum = 0;
        bool first = true;
        REP(j, N) {
            if (last == 0) last = max(last, a[j]);
            if (!(i & (1<<j))) {
                last = max(last, a[j]);
                continue; 
            }
            if (first) {
                first = false;
                continue;
            }
            // cout << bitset<10>(i) << " ";
            DEBUG(j, last, sum, a[j], abs(a[j] - last) + 1);
            if (a[j] <= last) {
                sum += abs(a[j] - last) + 1;
            }
            last = max(last+1, a[j]);
        }
        // if (sum < ans) {
        //     cout << bitset<10>(i) << " " << sum << endl;;
        // }
        ans = min(ans, sum);
    }

    cout << ans << endl;
}

int main() {
    _main();
    return 0;
}

