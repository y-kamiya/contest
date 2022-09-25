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

struct P {
    ll x, y;
    double a;
    P() {}
    P(ll x, ll y, double a): x(x), y(y), a(a) {}

    bool operator<(double _a) const {
        return a < _a;
    }
    bool operator<(const P &p) const {
        return a < p.a;
    }
};


void _main() {
    int N;
    cin >> N;

    vector<ll> x(N), y(N);
    REP(i, N) cin >> x[i] >> y[i];

    vector<P> ps(N);
    REP(i, N) {
        ps[i].x = x[i];
        ps[i].y = y[i];
        ps[i].a = atan2(y[i], x[i]);
    }
    sort(ALL(ps));
    REP(i, N) {
        P p(ps[i].x, ps[i].y, ps[i].a + 2*M_PI);
        ps.push_back(p);
    }

    double ans = 0;
    REP(i, N) {
        auto a = ps[i].a;
        auto itl = lower_bound(ALL(ps), a);
        auto itu = lower_bound(ALL(ps), a + M_PI);
        ll _x = 0, _y = 0;
        for (auto it = itl; it != itu; ++it) {
            auto p = *it;
            _x += p.x;
            _y += p.y;
        }
        ans = max(ans, sqrt(_x*_x + _y*_y));

        auto p = (*itl);
        _x -= p.x;
        _y -= p.y;
        ans = max(ans, sqrt(_x*_x + _y*_y));
    }

    PRINT_DOUBLE(11, ans);
}

int main() {
    _main();
    return 0;
}

