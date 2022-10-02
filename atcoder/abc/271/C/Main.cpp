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

    vector<int> a(N);
    REP(i, N) cin >> a[i];

    set<int> s(ALL(a));
    vector<int> b(ALL(s));
    sort(ALL(b));
    REP(i, N-s.size()) {
        b.push_back(1e9);
    }

    int i = 0;
    int j = N-1;
    int check = 0;
    while (j >= i) {
        ++check;
        if (b[i] == check) {
            ++i;
        } else if (i == j) {
            --check;
            break;
        } else {
            j -= 2;
        }
        DEBUG(i, j, check);
    }

    cout << check << endl;
}

int main() {
    _main();
    _main();
    _main();
    _main();
    _main();
    return 0;
}

