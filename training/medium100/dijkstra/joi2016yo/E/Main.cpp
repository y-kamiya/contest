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


static const ll INF = LLONG_MAX/2;
struct Edge {
    ll to;
    ll cost;
};
using P = pair<ll, ll>;

struct Graph {
    ll num;
    vector<vector<Edge>> graph;
    vector<ll> dist;

    Graph(ll n) {
        num = n;
        graph.resize(n);
        dist.resize(n, INF);
    }

    void add_edge(ll s, ll t, ll cost) {
        Edge e{t, cost};
        graph[s].push_back(e);
    }

    void dijkstra(ll s) {
        REP(i, num) dist[i] = INF;
        dist[s] = 0;

        priority_queue<P, vector<P>, greater<P>> que;
        que.emplace(0, s);

        while (!que.empty()) {
            P p = que.top();
            que.pop();

            ll v = p.second;
            if (dist[v] < p.first) continue;

            for (auto &e : graph[v]) {
                ll d = dist[v] + e.cost;
                if (dist[e.to] > d) {
                    dist[e.to] = d;
                    que.emplace(d, e.to);
                }
            }

        }
    }

    vector<bool> is_out;
    void check_cost(const vector<int> &C, int S) {
        is_out.resize(num, false);

        deque<P> que;
        vector<int> dist(num, -1);

        REP(i, num) {
            if (C[i]) {
                is_out[i] = true;
                dist[i] = 0;
                que.emplace_back(0, i);
            }
        }

        while(!que.empty()) {
            P p = que.front();
            que.pop_front();

            int d = p.first;
            int v = p.second;

            if (d > S) break;

            dist[v] = d;
            for (auto &e : graph[v]) {
                if (dist[e.to] == -1) que.emplace_back(d+1, e.to);
            }
        }

        REP(i, num) {
            if (0 <= dist[i] && dist[i] <= S) is_out[i] = true;
        }
    }

    void fix_cost(const vector<int> &C, int P, int Q) {
        REP(i, num) {
            for (auto &e : graph[i]) {
                if (is_out[e.to]) e.cost = Q;
                else e.cost = P;

                if (e.to == num-1) e.cost = 0;

                if (C[e.to]) e.cost = INF;
                DEBUG(i+1, e.to+1, e.cost);
            }
        }
    }
};


void _main() {
    int N, M, K, S, P, Q;
    cin >> N >> M >> K >> S >> P >> Q;

    vector<int> C(N, 0);
    REP(i, K) {
        int c; cin >> c;
        --c;
        C[c] = 1;
    }

    Graph G(N);
    REP(i, M) {
        int a, b; cin >> a >> b;
        --a; --b;
        G.add_edge(a, b, 1);
        G.add_edge(b, a, 1);
    }

    G.check_cost(C, S);
    G.fix_cost(C, P, Q);

    G.dijkstra(0);
    DEBUG(G.dist);

    cout << G.dist[N-1] << endl;
}

int main() {
    _main();
    return 0;
}

