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


void _main() {
    int N;
    cin >> N;

    vector<int> vec(N), P(N), Q(N);
    REP(i, N) cin >> P[i];
    REP(i, N) cin >> Q[i];
    REP(i, N) vec[i] = i+1;

    int count = 0;
    int a = 0, b = 0;
    DEBUG(P, "P");
    DEBUG(Q, "Q");
    do {
        DEBUG(vec);
        if (vec == P) a = count;
        if (vec == Q) b = count;
        if (a != 0 && b != 0) break;
        ++count;
    } while(next_permutation(ALL(vec)));

    cout << abs(a - b) << endl;
}

int main() {
    _main();
    return 0;
}

// AC 8

