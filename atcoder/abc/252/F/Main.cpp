#include <bits/stdc++.h>
#include <functional>
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


ll f(const vector<ll> &A, int s, int t, ll L) {
    if (t-s == 1) {
        if (A[s] < L) return L;
        return 0;
    }

    ll sum = 0;
    FOR(i, s, t) {
        sum += A[i];
        if (sum >= L/2) {
            DEBUG("aaaaaaaaa", i, s, t, sum, L);
            auto c1 = f(A, s, i+1, sum);
            auto c2 = f(A, i+1, t, L-sum);
            return L + c1 + c2;
        }
    }

    DEBUG("bbbbbbbb", s, t, sum, L);
    return L + f(A, s, t, sum);
}

void _main() {
    ll N, L;
    cin >> N >> L;

    vector<ll> A(N, 0ll);
    REP(i, N) cin >> A[i];

    sort(ALL(A), greater<ll>());

    auto cost = f(A, 0, N, L);
    cout << cost << endl;


}

int main() {
    _main();
    return 0;
}

