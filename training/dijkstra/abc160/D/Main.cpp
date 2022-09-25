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


static const int INF = INT_MAX/2;
using P = pair<int, int>;
struct Edge { int to, cost; };
struct Graph {
    int n;
    vector<vector<Edge>> edges;
    vector<int> dist;

    Graph(int size) {
        n = size;
        edges.resize(n);
        dist.resize(n, INF);
    }

    void add_edge(int s, int t, int c) {
        Edge e{t, c};
        edges[s].push_back(e);
    }

    void dijkstra(int s) {
        REP(i, n) dist[i] = INF;
        dist[s] = 0;

        priority_queue<P, vector<P>, greater<P>> que;
        que.push({0, s});

        while (!que.empty()) {
            P p = que.top();
            que.pop();

            auto cost = p.first;
            auto v = p.second;

            if (dist[v] < cost) continue;

            for (const auto &e : edges[v]) {
                if (dist[e.to] > dist[v] + e.cost) {
                    dist[e.to] = dist[v] + e.cost;
                    que.push({dist[e.to], e.to});
                }
            }
        }
    }
};


void _main() {
    int N, X, Y;
    cin >> N >> X >> Y;
    --X; --Y;

    Graph G(N);
    REP(i, N-1) {
        G.add_edge(i, i+1, 1);
        G.add_edge(i+1, i, 1);
    }
    G.add_edge(X, Y, 1);
    G.add_edge(Y, X, 1);

    vector<int> ans(N, 0);
    REP(i, N-1) {
        G.dijkstra(i);
        FOR(j, i+1, N) {
            ++ans[G.dist[j]];
        }
    }

    FOR(i, 1, N) {
        cout << ans[i] << endl;
    }
}

int main() {
    _main();
    return 0;
}

