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

using Field = vector<vector<char>>;

vector<pair<int,int>> _next = {
    {0,1},{1,0},{0,-1},{-1,0}
};

void _main() {
    int R, C;
    cin >> R >> C;

    int sy, sx, gy, gx;
    cin >> sy >> sx >> gy >> gx;
    --sy; --sx; --gy; --gx;

    Field F(R, vector<char>(C));
    REP(i, R) REP(j, C) {
        cin >> F[i][j];
    }
    F[sy][sx] = 'S';
    F[gy][gx] = 'G';

    vector<vector<int>> dist(R, vector(C, -1));
    deque<pair<int, int>> que;
    que.emplace_back(sy, sx);
    dist[sy][sx] = 0;

    while (!que.empty()) {
        auto [y, x] = que.front();
        que.pop_front();

        for (auto [dx, dy] : _next) {
            auto ny = y + dy;
            auto nx = x + dx;
            if (ny < 0 || R <= ny) continue;
            if (nx < 0 || C <= nx) continue;
            if (F[ny][nx] == '#') continue;
            if (dist[ny][nx] != -1) continue;
            que.emplace_back(ny, nx);
            dist[ny][nx] = dist[y][x] + 1;
        }
    }

    cout << dist[gy][gx] << endl;

}

int main() {
    _main();
    return 0;
}

// AC 14.5
