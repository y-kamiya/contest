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

static const int MOD = 998244353;

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
    // constexpr Modint &operator/=(Modint rhs) noexcept {
    //     u64 exp = Mod - 2;
    //     while (exp) {
    //       if (exp % 2) {
    //         *this *= rhs;
    //       }
    //       rhs *= rhs;
    //       exp /= 2;
    //     }
    //     return *this;
    // }
    constexpr Modint &operator/=(Modint rhs) noexcept {
        ll a = rhs.val, b = Mod, u = 1, v = 0;
        while (b) {
            ll t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        if (u < 0) u += Mod;
        val = val * u % Mod;
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

    constexpr Modint modpow(const Modint &mi) noexcept {
        u64 ret = 1;
        u64 n = mi.value();
        while (n > 0) {
            if (n & 1) ret = ret * val % Mod;
            val = val * val % Mod;
            n >>= 1;
        }
        val = ret;
        return *this;
    }
};

using mint = Modint<MOD>;

void _main() {
    int N;
    cin >> N;

    int M = N*N;
    vector<mint> fac(M+1);
    fac[0] = fac[1] = 1;
    FOR(i, 2, M+1) {
        fac[i] = fac[i-1] * i;
    }
    DEBUG(fac);

    mint ans = 0;
    auto ns = N - 1;
    auto nr = (N-1)*(N-1);
    FOR(i, 1, M+1) {
        auto nl = i - 1;
        auto nh = M - i;
        if (nl-ns < 0 || nh-ns < 0) continue;
        DEBUG(fac[nl] * fac[nh] * M * fac[nr],  fac[nl-ns]);
        mint a = (fac[nl] * fac[nh] * M * fac[nr]) / (fac[nl-ns] * fac[nh-ns]);
        ans += a;
        DEBUG(i, nl, nh, a, ans, "|", fac[nl], fac[nh], fac[nr], ns);
    }

    cout << fac[M] - ans << endl;
}

int main() {
    _main();
    return 0;
}

