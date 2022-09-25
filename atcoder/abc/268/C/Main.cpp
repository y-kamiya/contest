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
    int N;
    cin >> N;

    vector<int> p(N), q(N), c(N), d(N, 0);
    REP(i, N) cin >> p[i];
    REP(i, N) {
        q[p[i]] = i;
    }

    REP(i, N) {
        if (i-q[i] < 0) {
            c[i] = i + N - q[i];
        } else {
            c[i] = i-q[i];
        }
    }

    DEBUG(c);

    REP(i, N) {
        auto j = c[i];
        ++d[(j-1+N)%N];
        ++d[j];
        ++d[(j+1)%N];
    }

    DEBUG(d);

    int ans = 0;
    REP(i, N) ans = max(ans, d[i]);
    cout << ans << endl;

}

int main() {
    _main();
    return 0;
}

