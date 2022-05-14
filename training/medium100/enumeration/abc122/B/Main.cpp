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
    string S;
    cin >> S;

    int n = S.size();
    int ans = 0;
    REP(i, n) {
        FOR(j, i+1, n+1) {
            bool is_ok = true;
            int count = j - i;
            FOR(k, i, j) {
                char c = S[k];
                DEBUG(c);
                if (!(c == 'A' || c == 'C' || c == 'G' || c == 'T')) {
                    is_ok = false;
                    break;
                }
            }
            if (is_ok) ans = max(ans, count);
        }
    }
    cout << ans << endl;
}

int main() {
    _main();
    return 0;
}

// 16.5min
// 最初は求める値の認識違い
// その際のifをそのまま使おうとしたため条件が間違っていた
