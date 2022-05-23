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
    int N, M;
    cin >> N >> M;

    vector<vector<int>> a(N, vector(N, 0));
    REP(i, M) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        a[x][y] = 1;
        a[y][x] = 1;
    }

    int ans = 0;
    FORR(i, (1<<N)-1, 0) {
        vector<int> b;
        REP(j, N) {
            if (i>>j & 1) b.push_back(j);
        }
        int sz = b.size();
        bool is_ok = true;
        DEBUG(b, sz);
        REP(j, sz) FOR(k, j+1, sz) {
            int x = b[j];
            int y = b[k];
            DEBUG(j, k, x, y);
            if (!a[x][y]) {
                DEBUG("aaaaaaaaaaaaaaaa");
                is_ok = false;
                break;
            }
        }
        if (is_ok) {
            ans = max(ans, sz);
        }
    }
    cout << ans << endl;
}

int main() {
    _main();
    return 0;
}

// AC 27.5
// 実装doneまで18くらい
// 逆ループにすればうまくいった段階でreturnしてもよいと考えたがそれだと間違っていた
