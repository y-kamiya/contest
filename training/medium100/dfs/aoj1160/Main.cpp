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

using Graph = vector<vector<int>>;
vector<pair<int,int>> _next = {
    {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}
};

void dfs(const Graph &G, int h, int w, Graph &seen) {
    int H = G.size();
    int W = G[0].size();
    seen[h][w] = 1;
    for (auto [dh, dw] : _next) {
        auto nh = h+dh;
        auto nw = w+dw;
        if (nh < 0 || H <= nh) continue;
        if (nw < 0 || W <= nw) continue;
        if (G[nh][nw] == 0) continue;
        if (seen[nh][nw] == 1) continue;
        dfs(G, nh, nw, seen);
    }
}

void _main(int h, int w) {
    Graph c(h, vector(w, 0));
    REP(i, h) REP(j, w) {
        cin >> c[i][j];
    }

    Graph seen(h, vector(w, 0));
    int ans = 0;
    REP(i, h) REP(j, w) {
        if (c[i][j] == 0) continue;
        if (seen[i][j] == 1) continue;
        DEBUG(i, j);
        dfs(c, i, j, seen);
        ++ans;
    }
    cout << ans << endl;
}

int main() {
    while (true) {
        int h, w; cin >> w >> h;
        if (h == 0 && w == 0) break;
        _main(h, w);
    }
    return 0;
}

// AC 20.5
