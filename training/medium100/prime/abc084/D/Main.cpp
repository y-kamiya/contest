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
    int Q;
    cin >> Q;

    int M = 1e5;
    vector<bool> is_prime(M+1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    FOR(i, 2, M+1) {
        int j = 2;
        while (i * j <= M) {
            is_prime[i*j] = false;
            ++j;
        }
    }

    vector<int> a(M, 0);
    FOR(i, 1, M+1) {
        a[i] = a[i-1];
        if (i % 2 == 0) continue;
        if (!is_prime[i]) continue;
        if (!is_prime[(i+1)/2]) continue;
        a[i] = 1 + a[i-1];
    }

    REP(i, Q) {
        int l, r; cin >> l >> r;
        cout << a[r] - a[l-1] << endl;

    }
}

int main() {
    _main();
    return 0;
}

// AC 25
// 12くらいでナイーブに実装してWA
// 累積和に気づく
