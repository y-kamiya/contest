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
    int n, m;
    cin >> n;
    vector<int> A(n);
    REP(i, n) cin >> A[i];
    cin >> m;

    REP(_, m) {
        int q;
        bool is_ok = false;
        cin >> q;
        FOR(i, 1, 1<<n) {
            int sum = 0;
            REP(j, n) {
                if (i>>j & 1) {
                    sum += A[j];
                }
            }
            if (sum == q) {
                is_ok = true;
                break;
            }
        }
        auto ans = "no";
        if (is_ok) ans = "yes";
        cout << ans << endl;
    }
}

int main() {
    _main();
    return 0;
}

// AC 10
