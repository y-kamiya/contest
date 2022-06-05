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

using u64 = std::uint_fast64_t;
template<u64 Mod> struct Modint {
    u64 val;
    constexpr Modint(const u64 x = 0) noexcept : val(x % Mod) {}
    constexpr u64 &value() noexcept { return val; }
    constexpr const u64 &value() const noexcept { return val; }
    constexpr Modint operator+(const Modint rhs) const noexcept {
        return Modint(*this) += rhs;
    }
    constexpr Modint operator-(const Modint rhs) const noexcept {
        return Modint(*this) -= rhs;
    }
    constexpr Modint operator*(const Modint rhs) const noexcept {
        return Modint(*this) *= rhs;
    }
    constexpr Modint operator/(const Modint rhs) const noexcept {
        return Modint(*this) /= rhs;
    }
    constexpr Modint &operator+=(const Modint rhs) noexcept {
        val += rhs.val;
        if (Mod <= val) val -= Mod;
        return *this;
    }
    constexpr Modint &operator-=(const Modint rhs) noexcept {
        if (val < rhs.val) val += Mod;
        val -= rhs.val;
        return *this;
    }
    constexpr Modint &operator*=(const Modint rhs) noexcept {
        val = val * rhs.val % Mod;
        return *this;
    }
    constexpr Modint &operator/=(Modint rhs) noexcept {
        ll a = rhs.val, b = Mod, u = 1, v = 0;
        while (b) {
            ll t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % Mod;
        if (u < 0) val += Mod;
        return *this;
    }
    constexpr bool operator == (const Modint& rhs) const noexcept {
        return this->val == rhs.val;
    }
    constexpr bool operator != (const Modint& rhs) const noexcept {
        return this->val != rhs.val;
    }
    friend constexpr ostream& operator << (ostream &os, const Modint<Mod>& x) noexcept {
        return os << x.value();
    }
};

static const int MOD = 998244353;
using mint = Modint<MOD>;


void _main() {
    ll N, M;
    cin >> N >> M;

    int m = 0;
    while ((1ll<<m) <= M) ++m;

    if (N > m) {
        cout << 0 << endl;
        return;
    }

    vector<ll> c(m+1, 0);
    FOR(i, 1, m+1) c[i] = 1ll<<(i-1);

    c[m] = M - (1ll<<(m-1)) + 1;
    DEBUG(m);
    DEBUG(pow(2,m-1));
    DEBUG(c[m]);
    DEBUG(c);

    vector<vector<mint>> dp(m+1, vector<mint>(N+1, 0));
    FOR(i, 1, m+1) dp[i][1] = c[i];
    // dp[1][1] = c[1];
    // dp[2][1] = c[2];
    // dp[3][1] = c[3];
    // dp[2][2] = c[1] * c[2];
    // dp[3][2] = c[3] * (c[2] + c[1]);
    // dp[3][3] = c[1] * c[2] * c[3];
    // dp[4][2] = c[4] * (c[3] + c[2] * c[1]);
    // dp[4][3] = c[4] * c[3] * (c[2] + c[1]) + c[4] * c[2] * c[1];

    FOR(i, 1, m) {
        FOR(j, 1, i+1) {
            if (j >= N) break;
            FORR(k, i, j) {
                DEBUG(i+1, j+1, k, j, i+1);
                dp[i+1][j+1] += dp[k][j] * c[i+1];
            }
        }
    }

    REP(i, m+1) DEBUG(dp[i]);

    DEBUG(m, N);
    mint ans = 0;
    REP(i, m+1) ans += dp[i][N];
    cout << ans << endl;
}

int main() {
    _main();
    return 0;
}

