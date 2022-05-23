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

using Field = vector<vector<int>>;
vector<pair<int,int>> _next = {
    {0,1},{1,0},{0, -1},{-1,0}
};

int dfs(const Field &F, int r, int c, Field &seen, int n, int m, int count=1) {
    int ret = count;
    seen[r][c] = 1;
    for (auto [dx, dy] : _next) {
        auto nx = c + dx;
        auto ny = r + dy;
        if (ny < 0 || n <= ny) continue;
        if (nx < 0 || m <= nx) continue;
        if (seen[ny][nx]) continue;
        if (F[ny][nx] == 0) continue;
        DEBUG(ny,nx,count+1);
        ret = max(ret, dfs(F, ny, nx, seen, n, m, count+1));
    }
    seen[r][c] = 0;
    return ret;
}

void _main() {
    int m, n;
    cin >> m >> n;

    Field F(m, vector(n, 0));
    REP(i, n) REP(j, m) cin >> F[i][j];

    int ans = 0;
    REP(i, n) REP(j, m) {
        if (F[i][j] == 0) continue;
        Field seen(n, vector(m, 0));
        DEBUG("=========", i, j, "==============");
        ans = max(ans, dfs(F, i, j, seen, n, m));
    }

    cout << ans << endl;
    
}

int main() {
    _main();
    return 0;
}

// カウントの仕様上、帰りがけでseenを元に戻す必要があることにテストケースを見るまで気づけず
