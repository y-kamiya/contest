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
template<typename T0, typename T1, typename... Tail>
void print(pair<T0,T1> p, Tail... t) {
    cout << "(" << p.first << "," << p.second << ")";
    print(t...);
}
template<typename T, typename... Tail>
void print(vector<T> vec, Tail... t) {
    cout << "["; for (const auto &e : vec) { cout << e << ", "; } cout << "] ";
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

    string S,T;
    cin >> S >> T;

    int h = 0;
    REP(i, N) {
        if (S[i] != T[i]) ++h;
    }
    DEBUG(h);

    if (h % 2 == 1) {
        cout << -1 << endl;
        return;
    }

    int sc = 0;
    int tc = 0;
    string ans = "";
    REP(i, N) {
        if (S[i] == T[i]) {
            ans += "0";
            continue;
        }

        if (sc == h/2) {
            ++tc;
            ans += S[i];
            continue;
        }
        if (tc == h/2) {
            ++sc;
            ans += T[i];
            continue;
        }

        if (S[i] == '0') {
            ++tc;
        } else {
            ++sc;
        }
        ans += "0";

        DEBUG(ans);
    }

    cout << ans << endl;
}

int main() {
    _main();
    return 0;
}

