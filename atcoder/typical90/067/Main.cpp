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

string calc(string N) {
    ll n = 0;
    int sz = N.size();
    REP(i, sz) {
        ll a = (N[i]-'0') * pow(8, sz-1-i);
        n += a;
    }
    DEBUG(n);

    string ans = "";
    ll q = n;
    while (q != 0) {
        auto r = q % 9;
        if (r == 8) r = 5;
        ans += r + '0';
        q /= 9;
        DEBUG(q, r, ans);
    }
    reverse(ALL(ans));
    return ans;
}

void _main() {
    string N;
    int K;
    cin >> N >> K;

    if (N == "0") {
        osf << 0 << endl;
        return;
    }
    REP(i, K) {
        N = calc(N);
    }
    osf << N << endl;
}

int main() {
    _main();
    return 0;
}

