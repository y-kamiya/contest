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
using P = pair<int,int>;

ll bfs(const Graph &G, vector<int> &dist, int x, int k) {
    deque<P> que;
    que.push_back({0, x});

    dist[x] = 0;

    vector<int> vs{x};
    int count = 0;
    while (!que.empty()) {
        const auto &p = que.front();
        que.pop_front();

        int d = p.first;
        int v = p.second;

        if (d >= k) break;

        for (auto nv : G[v]) {
            DEBUG(v+1, nv+1);
            ++count;
            if (dist[nv] != -1) continue;
            dist[nv] = d+1;
            vs.push_back(nv);
            que.emplace_back(d+1, nv);
        }
    }
    DEBUG(x+1, k, count);

    ll ret = 0;
    REP(i, vs.size()) {
        ret += vs[i]+1;
        dist[vs[i]] = -1;
    }
    return ret;
}

void _main() {
    int N, M;
    cin >> N >> M;

    Graph G(N);
    REP(i, M) {
        int a, b; cin >> a >> b;
        --a; --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> dist(N, -1);
    int Q;
    cin >> Q;
    REP(i, Q) {
        int x, k; cin >> x >> k;
        --x;
        cout << bfs(G, dist, x, k) << endl;
    }

}

int main() {
    _main();
    return 0;
}

