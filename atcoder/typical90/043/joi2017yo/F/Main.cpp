#include <bits/stdc++.h>
#include <climits>
#include <functional>
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

struct Edge {
    int to, d;
    Edge(int t, int d): to(t), d(d) {}
};
using Graph = vector<vector<Edge>>;

struct State {
    int v, d, t, x;
    State(int v, int d, int t, int x): v(v), d(d), t(t), x(x) {}
    bool operator<(const State &s) const {
        return d < s.d;
    }
    bool operator>(const State &s) const {
        return d > s.d;
    }
    friend ostream& operator<<(ostream& os, const State &p) {
        return os << "(" << p.v << "," << p.d << "," << p.t << "," << p.x << ")";
    }
};

static const int Mode = 3;
static const int INF = INT_MAX/2;

void _main() {
    int N,M,X;
    cin >> N >> M >> X;
    DEBUG(N,M,X);

    vector<int> T(N);
    REP(i, N) cin >> T[i];

    Graph G(N);
    REP(i, M) {
        int a,b,d; cin >> a >> b >> d;
        --a;--b;
        G[a].emplace_back(b, d);
        G[b].emplace_back(a, d);
    }

    vector<vector<vector<int>>> dist(N, vector(Mode, vector(X+1, INF)));
    priority_queue<State, vector<State>, greater<State>> que;
    que.emplace(0, 0, 0, X);
    dist[0][0][X] = 0;

    while (!que.empty()) {
        auto [v, d, t, x] = que.top(); que.pop();
        if (dist[v][t][x] < d) continue;

        for (const auto &e : G[v]) {
            auto nv = e.to;
            if (abs(t-T[nv]) == 2 && e.d < x) continue;

            auto nt = T[nv];
            if (T[nv] == 1) {
                nt = x <= e.d ? 1 : t;
            }
            auto nx = T[nv] == 1 ? max(0, x-e.d) : X;

            if (dist[nv][nt][nx] > d + e.d) {
                dist[nv][nt][nx] = d + e.d;
                que.emplace(nv, dist[nv][nt][nx], nt, nx);
            }
        }
    }

    REP(i, Mode) DEBUG(dist[N-1][i]);

    int ans = INF;
    REP(i, Mode) REP(j, X+1) ans = min(ans, dist[N-1][i][j]);
    osf << ans << endl;

}

int main() {
    _main();
    _main();
    return 0;
}

