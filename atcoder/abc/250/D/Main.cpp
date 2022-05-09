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

bool is_prime(int n, vector<int> &cache) {
    if (cache[n] != -1) return cache[n];
    if (n < 2) return cache[n] = false;
    if (n == 2) return cache[n] = true;
    if (n % 2 == 0) return cache[n] = false;

    double sqrt_n = sqrt(n);
    FOR(i, 3, sqrt_n+1) {
        if (n % i == 0) return cache[n] = false;
    }
    return cache[n] = true;
}

void _main() {
    ll N;
    cin >> N;

    int M = pow(N/2+1, (double)1/3);
    vector<int> cache(M+1, -1);

    ll ans = 0;
    FOR(p, 2, M+1) {
        if (!is_prime(p, cache)) continue;
        int m = pow(N/p+1, (double)1/3);
        int count = 0;
        FOR(j, p+1, m+1) {
            if (is_prime(j, cache)) {
                if (p * j * j * j <= N) ++count;
            }
        }
        DEBUG(cache);
        ans += count;
        DEBUG(m);
        DEBUG(count);
        DEBUG("-------------");
    }

    cout << ans << endl;
    
}

int main() {
    _main();
    _main();
    return 0;
}

// AC 45min程度
// 2回WA&TLE
// 1. cacheを入れてなかったため
// 2. p*q^3 <= Nのチェックをしてなかったため1ケースだけWAだった
