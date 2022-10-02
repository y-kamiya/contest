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


using B = bitset<100>;
using P = pair<bool, B>;

void _main() {
    int N, S;
    cin >> N >> S;

    vector<int> a(N), b(N);
    REP(i, N) {
        cin >> a[i] >> b[i];
    }

    vector<vector<P>> dp(N+1, vector<P>(10005));
    DEBUG(dp[0][0].first, dp[0][0].second);
    dp[1][a[0]] = {true, B(0).set(0, false)};
    dp[1][b[0]] = {true, B(0).set(0, true)};

    FOR(i, 1, N) {
        FOR(j, 1, S) {
            if (!dp[i][j].first) continue;
            auto e = dp[i][j];
            dp[i+1][j+a[i]] = {true, e.second.set(i, false)};
            dp[i+1][j+b[i]] = {true, e.second.set(i, true)};
        }
    }

    if (dp[N][S].first) {
        Yes(1);
        auto bits = dp[N][S].second; 
        REP(i, N) {
            if (bits[i]) cout << "T";
            else cout << "H";
        }
        cout << endl;
    } else {
        Yes(0);
    }
}

int main() {
    _main();
    return 0;
}

