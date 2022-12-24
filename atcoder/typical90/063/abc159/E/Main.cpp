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
#define DEBUG(...) {print(__VA_ARGS__); cout << endl;}
#else
#define DEBUG(...)
#endif
 

ofstream file("_output.txt");
ostreamFork osf(file, cout);


void _main() {
    int H,W,K;
    cin >> H >> W >> K;

    vector<vector<int>> S(H, vector(W, 0));
    REP(i, H) REP(j, W) {
        char c; cin >> c;
        S[i][j] = c - '0';
    }

    // vector<vector<int>> ccum = S;
    // REP(j, W) REP(i, H) {
    //     if (i == 0) continue;
    //     ccum[i][j] += ccum[i-1][j];
    // }
    //
    // REP(i,H) DEBUG(S[i]);
    // REP(i,H) DEBUG(ccum[i]);

    int ans = INT_MAX;
    REP(i, 1<<(H-1)) {
        bool is_ok = true;
        int n = 0;
        REP(j, H-1) if (i&(1<<j)) ++n;
        int a = n;

        vector<int> count(n+1, 0);
        REP(j, W) {
            vector<int> cs(n+1, 0);
            int cnt = 0;
            REP(k, H) {
                if (S[k][j] == 1) ++cs[cnt];
                if (i&(1<<k)) ++cnt;
            }

            int m = *max_element(ALL(cs));
            if (m > K) {
                is_ok = false;
                break;
            }

            REP(k, n+1) {
                count[k] += cs[k];
                if (count[k] > K) {
                    count = cs;
                    ++a;
                    break;
                }
            }
            DEBUG("aaaaaaaaaa", i, j, cs, count, a, ans);
        }
        if (is_ok) {
            ans = min(ans, a);
        }
    }
    osf << ans << endl;
}

int main() {
    _main();
    return 0;
}

