#include <algorithm>
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


ll f(ll n) {
    auto a = to_string(n);
    reverse(ALL(a));
    return stoll(a);
}

void _main() {
    ll N, K;
    cin >> N >> K;
    DEBUG(N, K);

    ll ans = 0;
    auto K1 = f(K);
    auto K2 = f(K1);

    if (K1 < K || K2 < K) {
        cout << ans << endl;
        return;
    }

    if (K2 <= K1) {
        auto k = K2;
        while (k <= N) {
            DEBUG("2", k);
            ++ans;
            k *= 10;
        }

        if (K1 != K2) {
            k = K1;
            while (k <= N) {
                DEBUG("1", k);
                ++ans;
                k *= 10;
            }
        }
    }
    cout << ans << endl;

}

int main() {
    _main();
    return 0;
}

