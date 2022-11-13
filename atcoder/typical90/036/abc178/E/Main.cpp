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


void _main() {
    int N;
    cin >> N;

    vector<ll> x(N), y(N);
    REP(i, N) {
        int a,b; cin >> a >> b;
        x[i] = a-b;
        y[i] = a+b;
    }

    auto xmin = *min_element(ALL(x));
    auto ymin = *min_element(ALL(y));
    auto xmax = *max_element(ALL(x));
    auto ymax = *max_element(ALL(y));

    ll ans = 0;
    REP(i, N) {
        auto a = abs(x[i]-xmin);
        auto b = abs(x[i]-xmax);
        auto c = abs(y[i]-ymin);
        auto d = abs(y[i]-ymax);
        auto m = max(a, max(b, max(c, d)));
        ans = max(ans, m);
    }
    osf << ans << endl;
}

int main() {
    _main();
    return 0;
}

