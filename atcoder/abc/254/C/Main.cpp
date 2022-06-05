#include <bits/stdc++.h>
#include <queue>
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
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    REP(i, N) cin >> a[i];

    vector<priority_queue<int, vector<int>, greater<int>>> b(K);
    REP(i, N) {
        b[i%K].push(a[i]);
    }

    int p = b[0].top(); b[0].pop();
    FOR(i, 1, N) {
        auto n = b[i%K].top(); b[i%K].pop();
        DEBUG(i, p, n);
        if (n < p) {
            Yes(0);
            return;
        }
        p = n;
    }
    Yes(1);
}

int main() {
    _main();
    return 0;
}

