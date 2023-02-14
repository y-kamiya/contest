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
 
static const vector<pair<int,int>> nps = {{0,1},{1,0},{0,-1},{-1,0}};
static const int INF = INT_MAX/2;

ofstream file("_output.txt");
ostreamFork osf(file, cout);


void _main() {
    int H,W;
    cin >> H >> W;

    vector<vector<int>> A(H, vector(W, 0));
    REP(i, H) REP(j, W) cin >> A[i][j];

    vector<vector<vector<int>>> dp(H+1, vector(2, vector(2, INF)));
    dp[0][0][0] = 0;
    dp[0][1][0] = 1;

    FOR(i, 1, H+1) {
        REP(j, 2) {
            REP(k, 2) {
                REP(l, 2) {
                    vector<vector<int>> x(3, vector(W, -1));
                    if (i != 1) x[0] = A[i-2];
                    if (k) REP(m, W) x[0][m] = 1-x[0][m];

                    x[1] = A[i-1];
                    if (j) REP(m, W) x[1][m] = 1-x[1][m];

                    if (i != H) x[2] = A[i];
                    if (l) REP(m, W) x[2][m] = 1-x[2][m];

                    bool alone = false;
                    REP(w, W) {
                        vector<bool> b;
                        for (auto [s,t] : nps) {
                            auto nh = 1+t;
                            auto nw = w+s;
                            if (nw < 0 || W <= nw) continue;
                            b.push_back(x[1][w] == x[nh][nw]);
                        }
                        if (!any_of(ALL(b), [](bool x) {return x;})) {
                            alone = true;
                            break;
                        }
                    }
                    if (!alone) {
                        dp[i][j][k] = min(dp[i][l][j], dp[i-1][j][k] + (int)l);
                    }
                }
            }
        }
    }
    DEBUG(dp);
    auto ans = INF;
    REP(j, 2) REP(k, 2) ans = min(ans, dp[H][j][k]);
    if (ans == INF) ans = -1;
    osf << ans << endl;
}

int main() {
    _main();
    return 0;
}

