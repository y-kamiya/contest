#include <algorithm>
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

using Graph = map<int,vector<int>>;

int dfs(const Graph &G, int v, map<int,bool> &used, int p = -1, int m = 1) {
    used[v] = true;
    m = max(m, v);

    if (G.count(v) == 0) {
        return m;
    }
    for (auto nv : G.at(v)) {
        if (nv == p) continue;
        if (used[nv]) continue;
        m = max(m, dfs(G, nv, used, v, m));
    }

    return m;
}

void _main() {
    int N;
    cin >> N;

    vector<int> A(N), B(N);
    REP(i, N) {
        cin >> A[i] >> B[i];
    }

    Graph G;
    REP(i, N) {
        if (G.count(A[i]) == 0) G[A[i]] = {};
        if (G.count(B[i]) == 0) G[B[i]] = {};
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    map<int,bool> used;
    int ans = dfs(G, 1, used);

    osf << ans << endl;
}

int main() {
    _main();
    return 0;
}

