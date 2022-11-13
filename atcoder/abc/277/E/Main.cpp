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

using Graph = vector<vector<int>>;
static const int INF = INT_MAX/2;
void _main() {
    int N, M, K;
    cin >> N >> M >> K;

    Graph G0(N) ,G1(N);
    REP(i, M) {
        int u,v,a; cin >> u >> v >> a; --u; --v;
        if (a == 0) {
            G0[u].push_back(v);
            G0[v].push_back(u);
        } else {
            G1[u].push_back(v);
            G1[v].push_back(u);
        }
    }

    vector<bool> S(N, false);
    REP(i, K) {
        int s; cin >> s; --s;
        S[s] = true;
    }
    
    vector<int> count(N, INF);
    vector<vector<bool>> used(N, vector(2, false));
    deque<tuple<int,int,int>> que;
    que.push_back({0, 1, 0});
    if (S[0]) que.push_back({0, 0, 0});

    while (!que.empty()) {
        auto [v, a, c] = que.front();
        que.pop_front();
        used[v][a] = true;
        count[v] = min(count[v], c);
        DEBUG(v, a, c);

        const Graph &G = a == 0 ? G0 : G1;
        for (auto nv : G[v]) {
            if (used[nv][a]) continue;
            que.push_back({nv, a, c+1});
            used[nv][a] = true;
        }

        if (S[v]) {
            a = 1-a;
            const Graph &G = a == 0 ? G0 : G1;
            for (auto nv : G[v]) {
                if (used[nv][a]) continue;
                que.push_back({nv, a, c+1});
                used[nv][a] = true;
            }
        }
    }

    int ans = -1;
    if (count[N-1] != INF) {
        ans = count[N-1];
    }
    osf << ans << endl;
}

int main() {
    _main();
    return 0;
}

