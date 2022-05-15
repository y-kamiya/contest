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
    string S;
    cin >> S;

    set<int> s;
    REP(i, 10) REP(j, 10) REP(k, 10) {
        int flg = 0;
        REP(c, N) {
            int n = S[c] - '0';
            if (flg == 0 && n == i) {
                ++flg;
                continue;
            }
            if (flg == 1 && n == j) {
                ++flg;
                continue;
            }
            if (flg == 2 && n == k) {
                DEBUG("ok");
                s.insert(100*i+10*j+k);
                break;
            }
        }
        DEBUG(100*i+10*j+k, s.size());
    }
    cout << s.size() << endl;
}

int main() {
    _main();
    return 0;
}

// AC 20min
// 解法を思いつくまでに7min
// デバッグに5min以上かかった
