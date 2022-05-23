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

void _main() {
    int n;
    cin >> n;

    Graph G(n);
    REP(i, n) {
        int u, k; cin >> u >> k;
        --u;
        REP(j, k) {
            int v; cin >> v;
            --v;
            G[u].push_back(v);
        }
    }

    deque<int> que;
    vector<int> dist(n, -1);
    que.push_back(0);
    dist[0] = 0;

    while (!que.empty()) {
        int v = que.front();
        que.pop_front();
        
        for (auto nv : G[v]) {
            if (dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            que.push_back(nv);
        }
    }

    REP(i, n) {
        cout << i+1 << " " << dist[i] << endl;
    }
}

int main() {
    _main();
    return 0;
}

// AC 7
