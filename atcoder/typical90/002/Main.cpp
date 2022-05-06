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

    if (N % 2 != 0) {
        cout << endl;
        return;
    }

    set<string> keep;
    keep.insert("()");
    int n = 2;
    while (n < N) {
        set<string> ss;
        for (auto &s : keep) {
            REP(i, n+1) {
                ss.insert(s.substr(0, i) + "()" + s.substr(i));
            }
        }

        DEBUG("n=", n+2);
        for(auto &s : ss) {
            DEBUG(s);
        }
                    
        keep = ss;
        n += 2;
    }

    for (auto &s : keep) {
        cout << s << endl;
    }
}

int main() {
    _main();
    return 0;
}

// AC 60min
// パターン数の上限が2^20であるところを10^20だと勘違い

