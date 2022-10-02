#include <algorithm>
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
    cout << "["; for (const auto &e : vec) cout << e << ", "; cout << "] ";
    print(t...);
}
template<typename T, typename... Tail>
void print(set<T> vec, Tail... t) {
    cout << "["; for (const auto &e : vec) cout << e << ", "; cout << "] ";
    print(t...);
}
#ifdef _DEBUG
#define DEBUG(...) print(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

struct P {
    int x1,x2,y1,y2;
};

pair<map<int,int>,int> index_map(int M, const vector<int> &a, const vector<int> &b) {
    int N = a.size();
    auto all = set(ALL(a));
    REP(i, N) all.insert(b[i]);
    all.insert(0);
    all.insert(M);

    auto vec = vector(ALL(all));
    map<int,int> index;
    REP(i, vec.size()) index[vec[i]] = i;

    return {index, vec.size()-1};
}

static const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};

void dfs(vector<vector<int>> &s, int i, int j) {
    s[i][j] = 1;

    auto hm = s.size();
    auto wm = s[0].size();

    for (const auto &e : dir) {
        auto ni = i + e.second;
        auto nj = j + e.first;
        if (ni < 0 || hm <= ni) continue;
        if (nj < 0 || wm <= nj) continue;
        if (s[ni][nj] > 0) continue;
        dfs(s, ni, nj);
    }
}

void bfs(vector<vector<int>> &s, int i, int j) {
    int hm = s.size()-1;
    int wm = s[0].size()-1;

    queue<pair<int,int>> que;
    que.push({i,j});
    s[i][j] = 1;

    DEBUG("-------------");
    while(!que.empty()) {
        auto [y,x] = que.front();
        que.pop();
        DEBUG(y,x);
        for (const auto &e : dir) {
            auto ni = y + e.second;
            auto nj = x + e.first;
            if (ni < 0 || hm <= ni) continue;
            if (nj < 0 || wm <= nj) continue;
            if (s[ni][nj] > 0) continue;
            que.push({ni,nj});
            s[ni][nj] = 1;
        }
    }
}

void _main() {
    int W,H,N;
    cin >> W >> H >> N;

    vector<int> x1(N), x2(N), y1(N), y2(N);
    REP(i, N) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    }

    auto [xmap, wm] = index_map(W, x1, x2);
    auto [ymap, hm] = index_map(H, y1, y2);
    DEBUG(x1);
    DEBUG(x2);

    DEBUG(hm, wm);
    vector<vector<int>> s(hm+1, vector(wm+1, 0));
    REP(i, N) {
        auto w1 = xmap[x1[i]];
        auto w2 = xmap[x2[i]];
        auto h1 = ymap[y1[i]];
        auto h2 = ymap[y2[i]];
        s[h1][w1]++;
        s[h2][w1]--;
        s[h1][w2]--;
        s[h2][w2]++;
    }

    REP(i, hm) REP(j, wm) s[i][j+1] += s[i][j];
    REP(j, wm) REP(i, hm) s[i+1][j] += s[i][j];

    REP(i, hm+1) DEBUG(s[i]);

    int ans = 0;
    REP(i, hm) REP(j, wm) {
        if (s[i][j] > 0) continue;
        bfs(s, i, j);
        ++ans;
    }
    cout << ans << endl;


}

int main() {
    _main();
    return 0;
}

