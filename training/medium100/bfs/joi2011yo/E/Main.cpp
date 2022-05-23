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
using P = pair<int,int>;

int bfs(const Field &F, const P &s, const P &t, int H, int W) {
    vector<P> _next = {
        {0,1},{1,0},{0,-1},{-1,0}
    };
    vector<vector<int>> dist(H, vector(W, -1));
    deque<P> que;
    que.push_back(s);
    dist[s.first][s.second] = 0;

    // REP(i, 4) DEBUG(_next[i].first, _next[i].second);
    while (!que.empty()) {
        P p = que.front();
        que.pop_front();

        if (p == t) break;

        for (auto [dh, dw]: _next) {
            int h = dh + p.first;
            int w = dw + p.second;
            if (h < 0 || H <= h) continue;
            if (w < 0 || W <= w) continue;
            if (F[h][w] == 'X') continue;
            if (dist[h][w] != -1) continue;
            que.emplace_back(h, w);
            dist[h][w] = dist[p.first][p.second] + 1;
            DEBUG(h, w, dist[h][w]);
        }
    }

    REP(i, H) DEBUG(dist[i]);
    return dist[t.first][t.second];
}

void _main() {
    int H, W, N;
    cin >> H >> W >> N;

    Field F(H, vector<char>(W));

    vector<P> ss(N+1);
    REP(i, H) REP(j, W) {
        char c; cin >> c;
        if (c == 'S') {
            ss[0] = {i,j};
            c = '.';
        } else {
            int n = c - '0';
            if (n <= N) {
                ss[n] = {i,j};
                c = '.';
            }
        }
        if (i == 4) DEBUG(c);
        F[i][j] = c;
    }

    int ans = 0;
    REP(i, N) {
        ans += bfs(F, ss[i], ss[i+1], H, W);
        DEBUG("ans", ans);
    }

    cout << ans << endl;
}

int main() {
    _main();
    _main();
    _main();
    return 0;
}

// Ac 46
// 手元の環境だけでFiledやvectorの値がおかしくなる不明な状態になった
// 提出してみたらACだったが手元では計算結果合わない
