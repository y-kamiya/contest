#include <bits/stdc++.h>
using namespace std;

class ostreamFork {
public:
    ostream &os1,&os2;
    ostreamFork(ostream& os1, ostream& os2) : os1(os1), os2(os2) {}
};
template <class Data>
ostreamFork& operator<<(ostreamFork& osf, Data d) {
    osf.os1 << d; osf.os2 << d; return osf;
}
ostreamFork& operator<<(ostreamFork& osf, ostream& (*f)(ostream&)) {
    osf.os1 << f; osf.os2 << f; return osf;
}
template <class ManipData>
ostreamFork& operator<<(ostreamFork& osf, ostream& (*f)(ostream&, ManipData)) {
    osf.os1 << f; osf.os2 << f; return osf;
}

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

ofstream file("_output.txt");
ostreamFork osf(file, cout);

struct State {
    int y,x,d;
    State(int y, int x, int d): y(y),x(x),d(d) {}
};
static const int INF = INT_MAX/2;
static const int D = 4;
static const vector<pair<int,int>> ds = {{1,0},{0,1},{-1,0},{0,-1}};

void _main() {
    int H,W,rs,cs,rt,ct;
    cin >> H >> W >> rs >> cs >> rt >> ct;
    --rs;--cs;--rt;--ct;

    vector<string> F(H);
    REP(i, H) cin >> F[i];

    vector<vector<vector<int>>> dist(H, vector(W, vector(D, INF)));
    deque<State> que;
    REP(d, D) {
        que.emplace_back(rs, cs, d);
        dist[rs][cs][d] = 0;
    }

    while (!que.empty()) {
        auto [y,x,d] = que.front(); que.pop_front();

        REP(i, D) {
            auto [dy,dx] = ds[i];
            auto ny = y + dy;
            auto nx = x + dx;
            if (ny < 0 || H <= ny) continue;
            if (nx < 0 || W <= nx) continue;
            if (F[ny][nx] == '#') continue;

            auto dc = d == i ? 0 : 1;
            auto cost = dist[y][x][d] + dc;
            if (dist[ny][nx][i] <= cost) continue;
            dist[ny][nx][i] = cost;
            if (dc == 0) que.emplace_front(ny, nx, i);
            else que.emplace_back(ny, nx, i);
        }
    }

    int ans = INF;
    REP(i, D) ans = min(ans, dist[rt][ct][i]);
    osf << ans << endl;
}

int main() {
    _main();
    return 0;
}

