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


static const int MOD = 1000000007;
using mint = Modint<MOD>;

void _main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    string tgt = "atcoder";
    int n_tgt = tgt.size();
    vector<vector<mint>> dp(N+1, vector<mint>(n_tgt+1, 0));
    REP(i, N) dp[i][0] = 1;

    REP(i, N) {
        REP(j, n_tgt) {
            dp[i+1][j+1] += dp[i][j+1];
            if (S[i] == tgt[j]) dp[i+1][j+1] += dp[i][j];
        }
    }

    REP(i, N+1) DEBUG(dp[i]);
    cout << dp[N][n_tgt] << endl;
}

int main() {
    _main();
    return 0;
}

// AC 46min
// dpを使う方針はすぐに立ったのだが添字の扱いに混乱して時間がかかった
// あと初期化しておく部分
// tgtのようにまとめて扱わずに素直に各charをifで判定する書き方をすれば混乱せずにできたかも
