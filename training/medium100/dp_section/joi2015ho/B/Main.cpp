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

int norm(int n, int N) {
    return (n+N) % N;
}

pair<int,int> f(const vector<int> &A, int i, int s, int t) {
    int N = A.size();
    int a, b;
    if (i == 0) {
        a = s+1;
        b = t-1;
    } else {
        a = s;
        b = t-2;
    }
    a = norm(a, N);
    b = norm(b, N);

    DEBUG("IOI", A[a], A[b]);
    if (A[a] < A[b]) {
        return {norm(a, N), norm(b-1, N)};
    } else {
        return {norm(a+1, N), norm(b, N)};
    }
}

ll dfs(vector<vector<ll>> &dp, const vector<int> &A, int s, int t) {
    if (dp[s][t] != 0) return dp[s][t];
    if (abs(s-t) == 1) return dp[s][t] = A[s];

    int N = dp.size();

    DEBUG(s, t);
    auto [s0,t0] = f(A, 0, s, t);
    DEBUG("i=0", s0, t0);
    int a = A[s] + dfs(dp, A, s0, t0);

    int n1 = norm(t-1, N);
    auto [s1,t1] = f(A, 1, s, t);
    DEBUG("i=1", s1, t1);
    int b = A[n1] + dfs(dp, A, s1, t1);

    return dp[s][t] = max(a, b);
}

void _main() {
    int N;
    cin >> N;

    vector<int> A(N);
    REP(i, N) cin >> A[i];

    vector<vector<ll>> dp(N+1, vector(N+1, 0ll));
    ll ans = 0;
    REP(i, N) {
        auto [s,t] = f(A, i, 0, N);
        ans = max(ans, A[i] + dfs(dp, A, s, t));
    }
    cout << ans << endl;
}

int main() {
    _main();
    return 0;
}

