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

struct UnionFind {
    int n;
    vector<int> par;

    UnionFind(int n): n(n) {
        par.resize(n);
        REP(i, n) par[i] = i;
    }

    int root(int a) {
        if (par[a] == a) return a;
        return par[a] = root(par[a]);
    }

    int same(int a, int b) {
        return root(a) == root(b);
    }

    void merge(int a, int b) {
        auto x = root(a);
        auto y = root(b);
        if (x == y) return;
        par[x] = y;
    }
};

using SP = tuple<double,double,double,double>;
using P = pair<double, pair<int, int>>;

double f(const SP &sp1, const SP &sp2) {
    auto [x1,y1,z1,r1] = sp1;
    auto [x2,y2,z2,r2] = sp2;
    auto dx = abs(x1-x2);
    auto dy = abs(y1-y2);
    auto dz = abs(z1-z2);
    auto dist = sqrt(dx*dx + dy*dy + dz*dz);
    return max(0.0, dist-r1-r2);
}

int _main() {
    int N;
    cin >> N;
    if (N == 0) return 1;

    vector<SP> sp(N);
    REP(i, N) {
        double x,y,z,r;
        cin >> x >> y >> z >> r;
        sp[i] = {x,y,z,r};
    }

    UnionFind uf(N);
    priority_queue<P, vector<P>, greater<P>> que;
    REP(i, N) {
        FOR(j, i+1, N) {
            pair<int,int> e{i, j};
            auto w = f(sp[i], sp[j]);
            DEBUG("sp", i, j, w);
            que.emplace(w, e);
        }
    }

    double ans = 0;
    while (!que.empty()) {
        P p = que.top();
        que.pop();

        auto w = p.first;
        auto s = p.second.first;
        auto t = p.second.second;
        DEBUG("mst", s, t, w);

        if (uf.same(s,t)) continue;
        ans += w;
        uf.merge(s,t);
    }
    PRINT_DOUBLE(3, ans);

    return 0;
}

// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1127
int main() {
    while (true) {
        auto ret = _main();
        if (ret == 1) break;
    }
    return 0;
}

// AC 31
