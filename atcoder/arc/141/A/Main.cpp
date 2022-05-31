#include <bits/stdc++.h>
#include <string>
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

string repeat(string s, int i) {
    string ret = "";
    REP(_, i) {
        ret += s;
    }
    return ret;
}

ll f(ll n) {
    auto sn = to_string(n);
    auto n_digit = sn.size();
    DEBUG(sn, n_digit);

    ll ans = 0;
    FOR(i, 1, n_digit) {
        if (n_digit % i != 0) continue;
        auto sm = sn.substr(0, i);
        auto s = repeat(sm, n_digit/i);
        DEBUG("aaa", s, i);

        auto p = stoll(s);
        if (p > n) {
            sm = to_string(stoll(sm) - 1);
            if (sm.size() != i) continue;

            s = repeat(sm, n_digit/i);
            p = stoll(s);
            assert(p <= n);
            DEBUG("bbb", s, i);
        }

        ans = max(ans, p);
    }
    return ans;
}

void _main(ll n) {
    auto ans = f(n);

    if (ans == 0) {
        auto sn = to_string(n);
        auto n_digit = sn.size();
        string s = "";
        REP(i, n_digit-1) s += "9";
        ans = f(stoll(s));
    }

    cout << ans << endl;
}

int main() {
    ll N;
    cin >> N;

    REP(i, N) {
        ll n; cin >> n;
        _main(n);
    }
    return 0;
}

// AC 50
