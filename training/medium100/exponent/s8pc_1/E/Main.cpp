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

static const ll MOD = 1e9+7;

ll modpow(ll a, ll n) {
    ll ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return ret;
}

void _main() {
    int N, Q;
    cin >> N >> Q;

    vector<ll> a(N), b(N, 0), c(Q+2, 0);
    REP(i, N) cin >> a[i];
    FOR(i, 1, Q+1) {
        cin >> c[i];
        --c[i];
    }

    REP(i, N-1) {
        b[i+1] = (b[i] + modpow(a[i], a[i+1])) % MOD;
    }

    DEBUG(a);
    DEBUG(b);

    ll ans = 0;
    REP(i, Q+1) {
        int s = c[i];
        int t = c[i+1];
        int d = b[t] + MOD - b[s];
        // if (d < 0) d += MOD;
        DEBUG(i, s, t, d);
        ans = (ans + d) % MOD;
    }
    cout << ans << endl;
}

int main() {
    _main();
    return 0;
}

