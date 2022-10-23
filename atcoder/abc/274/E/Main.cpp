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

static const double INF = DBL_MAX/2;
static constexpr int NN = 5;

void _main() {
    int N,M;
    cin >> N >> M;

    int n = N+M+1;
    vector<double> X(n, 0), Y(n, 0);
    FOR(i, 1, n) cin >> X[i] >> Y[i];

    vector<vector<double>> cost(n, vector(n, 0.0));
    REP(i, n) REP(j, n) {
        cost[i][j] = sqrt(pow(X[j]-X[i], 2) + pow(Y[j]-Y[i], 2));
    }
    REP(i, n) DEBUG(cost[i]);

    vector<vector<double>> dp(1<<n, vector(n, INF));
    REP(i, n) dp[i][i] = cost[0][i];

    int booster = 0;
    int city = 0;
    REP(i, n) {
        if (i > N) booster += 1<<i;
        else city += 1<<i;
    }

    REP(i, 1<<n) {
        int c = __builtin_popcount(i&booster);
        double scale = 1.0/pow(2, c);
        DEBUG(bitset<NN>(i), scale);
        REP(j, n) {
            if ((i&1<<j) > 0) continue;
            REP(k, n) {
                if (i!=0 && (i&1<<k) == 0) continue;
                dp[i|1<<j][j] = min(dp[i|1<<j][j], dp[i][k] + cost[k][j] * scale);
                DEBUG("aaaaaaaaaaaaaaa", bitset<NN>(i), bitset<NN>(1<<j), bitset<NN>(1<<k), dp[i|1<<j][j], dp[i][k], cost[k][j]);
            }
        }
    }

    REP(i, 1<<n) DEBUG(dp[i]);

    double ans = INF;
    REP(i, 1<<n) {
        if ((i&city) != city) continue;
        ans = min(ans, dp[i][0]);
    }
    PRINT_DOUBLE(6, ans);
}

int main() {
    _main();
    return 0;
}

