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


struct Comb {
    int M;
    int mod;
    vector<ll> fac;
    vector<ll> finv;
    vector<ll> inv;

    Comb(int m, int p): M(m+1), mod(p) {
        fac.resize(M, 0);
        finv.resize(M, 0);
        inv.resize(M, 0);
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;

        FOR(i, 2, M) {
            fac[i] = fac[i-1] * i % mod;
            inv[i] = mod - inv[mod % i] * (mod / i) % mod;
            finv[i] = finv[i-1] * inv[i] % mod;
        }
    }

    ll comb(int n, int k) {
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        assert(n <= M);
        return fac[n] * (finv[k] * finv[n-k] % mod) % mod;
    }
};

void _main() {
    int N;
    cin >> N;

    Comb comb(N, 1e9+7);
    int K = 0;
    REP(k, N+1) {
        if (N == comb.comb(k, 2)) {
            K = k;
            break;
        }
    }

    if (N == 1) K = 2;

    if (K == 0) {
        Yes(0);
        return;
    }

    int M = 2*N/K;
    DEBUG(N, K, 2*N/K);
    vector<vector<int>> a(K, vector(M, 0));
    int c = 1;
    REP(m, M) {
        FOR(j, m, M) {
            DEBUG(0, m,j);
            a[m][j] = c+j;
        }
        FOR(i, m, M) {
            DEBUG(1, m,i);
            a[i+1][m] = c+i;
        }
        c += M-m-1;
    }

    REP(i, K) DEBUG(a[i]);

    Yes(1);
    cout << K << endl;
    REP(i, K) {
        cout << M << " ";
        REP(j, M) cout << a[i][j] << " ";
        cout << endl;
    }

}

int main() {
    _main();
    return 0;
}

// AC 72
// 法則に気づくまでに45くらい
// N=1の対応忘れでWA
