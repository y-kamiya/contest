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

    vector<int> a(N+1, 0);
    FOR(i, 1, N+1) cin >> a[i];

    auto s = 0;
    vector<int> c(N+1, 0);
    FORR(i, N, 1) {
        int m = 0;
        for(auto j=2; i*j<=N; ++j) {
            m += c[i*j];
        }
        c[i] = m % 2 == a[i] ? 0 : 1;
        s += c[i];
    }

    cout << s << endl;
    if (s == 0) return;

    DEBUG(c);

    FOR(i, 1, N+1) {
        if (c[i] == 0) continue;
        cout << i << " ";
    }
    cout << endl;

}

int main() {
    _main();
    return 0;
}

