#include <bits/stdc++.h>
#include <ostream>
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

struct P {
    ll a, i;
    bool operator<(const P &p) const {
        return a < p.a;
    }
    friend ostream& operator<<(ostream& os, const P &p) {
        return os << "(" << p.a << "," << p.i << ")";
    }
};

void _main() {
    ll N, K;
    cin >> N >> K;

    vector<ll> A(N);
    vector<P> ps(N);
    REP(i, N) {
        cin >> A[i];
        ps[i].a = A[i];
        ps[i].i = i;
    }

    sort(ALL(ps));
    DEBUG(ps);

    ll sum = 0;
    ll rest = 0;
    ll m = 0;
    REP(i, N) {
        ll a = ps[i].a;
        if (i > 0) {
            m = A[ps[i-1].i];
            a -= m;
        }

        DEBUG("bbbbbbbbbb ", i, a);
        auto s = a * (N-i);
        if (sum+s < K) {
            DEBUG("aaaaaaaaa ", i, a, s);
            sum += s;
            ps[i].a = 0;
            continue;
        }

        ll d = K - sum;
        ll l = 0, r = a;
        DEBUG(i, l, r, N-i, d);
        while (r-l>1) {
            ll h = (r+l)/2;
            if (h * (N-i) > d) r = h;
            else l = h;
        }
        DEBUG(i, l, r, m);
        sum += l * (N-i);

        rest = K - sum;
        if (sum == 0) break;

        FOR(j, i, N) {
            ps[j].a -= (m + l);
        }
        break;
    }

    sort(ALL(ps), [](const P &p, const P &q) { return p.i < q.i; });

    REP(i, N) {
        if (rest == 0) break;
        if (ps[i].a == 0) continue;
        --ps[i].a;
        --rest;
    }

    DEBUG(ps);
    REP(i, N) {
        cout << ps[i].a << " ";
    }
    cout << endl;
}

int main() {
    _main();
    return 0;
}

