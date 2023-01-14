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

template <typename T>
std::vector<std::tuple<T, int, int>> manhattan_mst(std::vector<T> xs, std::vector<T> ys) {
    const int n = xs.size();
    std::vector<int> idx(n);
    std::iota(idx.begin(), idx.end(), 0);
    std::vector<std::tuple<T, int, int>> ret;
    for (int s = 0; s < 2; s++) {
        for (int t = 0; t < 2; t++) {
            auto cmp = [&](int i, int j) { return xs[i] + ys[i] < xs[j] + ys[j]; };
            std::sort(idx.begin(), idx.end(), cmp);
            std::map<T, int> sweep;
            for (int i : idx) {
                for (auto it = sweep.lower_bound(-ys[i]); it != sweep.end(); it = sweep.erase(it)) {
                    int j = it->second;
                    if (xs[i] - xs[j] < ys[i] - ys[j]) break;
                    ret.emplace_back(std::abs(xs[i] - xs[j]) + std::abs(ys[i] - ys[j]), i, j);
                }
                sweep[-ys[i]] = i;
            }
            std::swap(xs, ys);
        }
        for (auto &x : xs) x = -x;
    }
    std::sort(ret.begin(), ret.end());
    return ret;
}

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

void _main() {
    int N;
    cin >> N;

    vector<int> x(N), y(N);
    REP(i, N) {
        cin >> x[i];
        y[i] = i;
    }

    auto vec = manhattan_mst(x, y);
    DEBUG(vec);

    UnionFind uf(N);
    vector<int> dist(N, INT_MAX);
    for (auto [w,i,j] : vec) {
        if (uf.same(i,j)) continue;
        uf.merge(i,j);
        dist[i] = min(dist[i], w);
        dist[j] = min(dist[j], w);
    }
    DEBUG(dist);

    for (auto d : dist) {
        osf << d << " ";
    }
    osf << endl;
}

int main() {
    _main();
    return 0;
}

