#include <bits/stdc++.h>
#include <climits>
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

#define REP(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(ll i=n;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define FORR(i,a,b) for(ll i=(a);i>=(b);--i)
#define ALL(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define PRINT_DOUBLE(n, x) cout << std::fixed << std::setprecision(n) << x << endl;

void print() {};
void print(string s) { cout << s; }
template<typename Head> void print(Head h) { cout << h; }
template<typename Head, typename... Tail> void print(Head h, Tail... t);
template<typename... Tail> void print(string s, Tail... t);
template<typename T0, typename T1, typename... Tail> void print(pair<T0,T1> p, Tail... t);
template<template<class...> class Cont, typename... Ts, typename... Tail> void print(Cont<Ts...> ts, Tail... t);

template<typename... Tail>
void printnext(Tail... t) { cout << " "; print(t...); }

template<typename Head, typename... Tail>
void print(Head h, Tail... t) {
    cout << h; printnext(t...);
}
template<typename... Tail>
void print(string s, Tail... t) {
    cout << s; printnext(t...);
}
template<typename T0, typename T1, typename... Tail>
void print(pair<T0,T1> p, Tail... t) {
    cout << "(" << p.first << "," << p.second << ")";
    printnext(t...);
}
template<size_t N = 0, typename T>
void print_tuple(const T &t) {
    auto d = ", "; if constexpr(N == 0) d = "";
    if constexpr(N < tuple_size<T>::value) { cout << d << get<N>(t); print_tuple<N+1>(t);}
}
template<typename... Ts, typename... Tail>
void print(tuple<Ts...> h, Tail... t) {
    cout << "("; print_tuple(h); cout << ")";
}
template<template<class...> class Cont, typename... Ts, typename... Tail>
void print(Cont<Ts...> ts, Tail... t) {
    cout << "[";  for (const auto &e : ts) {print(e); cout << " ";} cout << "] ";
    printnext(t...);
}
#ifdef _DEBUG
#define DEBUG(...) { print(__VA_ARGS__); cout << endl; }
#else
#define DEBUG(...)
#endif
 

ofstream file("_output.txt");
ostreamFork osf(file, cout);

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

using Graph = vector<vector<pair<ll,ll>>>;
static const ll INF = LLONG_MAX/2;

void _main() {
    ll N, M, Q;
    cin >> N >> M >> Q;

    UnionFind uf(N);
    Graph G(N);
    REP(i, M) {
        ll a,b,c; cin >> a >> b >> c;
        --a; --b;
        G[a].emplace_back(b, c);
        G[b].emplace_back(a, -c);
        uf.merge(a, b);
    }

    vector<bool> has_loop(N);
    vector<ll> dist(N, -INF);
    REP(i, N) {
        if (uf.root(i) != i) continue;
        dist[i] = 0;
        deque<pair<ll,ll>> que;
        que.emplace_back(i, 0);
        while (!que.empty()) {
            auto [v, d] = que.front(); que.pop_front();
            for (auto [nv, c] : G[v]) {
                if (dist[nv] == -INF) {
                    dist[nv] = dist[v] + c;
                    que.emplace_back(nv, dist[nv]);
                } else {
                    if (dist[nv] == dist[v] + c) continue;
                    has_loop[i] = true;
                }
            }
        }
    }

    REP(i, Q) {
        ll x,y; cin >> x >> y;
        --x; --y;
        if (!uf.same(x, y)) {
            osf << "nan" << endl;
            continue;
        }

        auto root = uf.root(x);
        if (has_loop[root]) {
            osf << "inf" << endl;
            continue;
        }

        osf << dist[y] - dist[x] << endl;
    }

    

}

int main() {
    _main();
    return 0;
}

