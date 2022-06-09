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
    int N, M;
    cin >> N >> M;

    vector<int> P(M);
    REP(i, M) {
        cin >> P[i];
        --P[i];
    }

    vector<ll> A(N), B(N), C(N);
    REP(i, N-1) cin >> A[i] >> B[i] >> C[i];

    vector<int> a(N);
    REP(i, M-1) {
        int s = P[i];
        int t = P[i+1];
        if (s > t) swap(s,t);
        ++a[s];
        --a[t];
    }
    DEBUG(a);

    REP(i, N) {
        a[i+1] += a[i];
    }
    DEBUG(a);

    ll ans = 0;
    REP(i, N) {
        int c = a[i];
        ans += min(c*A[i], c*B[i] + C[i]);
    }

    cout << ans << endl;

}

int main() {
    _main();
    return 0;
}

// AC 24.5
// WA 19 A,B,Cをintにしていたため
