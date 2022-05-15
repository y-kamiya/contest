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
    int n;
    cin >> n;

    vector<int> x(n), y(n);
    REP(i, n) cin >> x[i] >> y[i];

    map<pair<int,int>, bool> exist;
    REP(i, n) {
        exist[{x[i],y[i]}] = true;
    }

    int ans = 0;
    REP(i, n) FOR(j, i+1, n) {
        int dx = x[j] - x[i];
        int dy = y[j] - y[i];

        int x3 = x[i] + dy;
        int y3 = y[i] - dx;
        if (exist.count({x3,y3}) != 0) {
            int nx3 = x3 + dx;
            int ny3 = y3 + dy;
            if (exist.count({nx3,ny3}) != 0) {
                ans = max(ans, dx*dx + dy*dy);
            }
        }

        int x4 = x[i] - dy;
        int y4 = y[i] + dx;
        if (exist.count({x4,y4}) != 0) {
            int nx4 = x4 + dx;
            int ny4 = y4 + dy;
            if (exist.count({nx4,ny4}) != 0) {
                ans = max(ans, dx*dx + dy*dy);
            }
        }

    }

    cout << ans << endl;
}

int main() {
    _main();
    return 0;
}

// AC 22min
// 解法を考えるまで5min未満、デバッグは必要なかったので実装自体に15min程度
