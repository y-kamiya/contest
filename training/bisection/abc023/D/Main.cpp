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

bool isOk(const vector<ll> &H, const vector<ll> &S, ll h) {
    ll n = H.size();
    vector<int> ns(n);
    REP(i, n) {
        ll l = -1;
        ll r = n;
        while (r-l > 1) {
            ll mid = (l+r)/2;
            if (h < H[i]+S[i]*mid) r = mid;
            else l = mid;
        }
        ns[i] = l;
    }
    sort(ALL(ns));
    REP(i, n) {
        if (i > ns[i]) return false;
    }
    return true;
}

void _main() {
    ll N;
    cin >> N;

    vector<ll> H(N), S(N);
    REP(i, N) cin >> H[i] >> S[i];

    ll l = 0;
    ll r = N * 1e9 + 1;
    while (r-l > 1) {
        ll mid = (l+r) / 2;
        if (isOk(H, S, mid)) r = mid;
        else l = mid;
    }

    cout << r << endl;
}

int main() {
    _main();
    return 0;
}

