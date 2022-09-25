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


ll count(ll a) {
    auto sa = to_string(a);
    auto na = sa.size();
    vector<vector<vector<ll>>> dp(na+1, vector(2, vector(2, 0ll)));
    dp[0][0][0] = 1;
    FOR(i, 0, na) REP(j, 2) REP(k, 2) {
        int D = sa[i] - '0';
        for(auto d=0; d <= (j ? 9 : D); ++d) {
            dp[i+1][j || d<D][k || d == 4 || d == 9] += dp[i][j][k];
            // DEBUG(i, j, k, d);
        }
        // DEBUG("------------------------");
        // DEBUG(dp[i+1][0][0], dp[i+1][0][1], dp[i+1][1][0], dp[i+1][1][1]);
        // DEBUG("------------------------");
    }

    REP(i, na+1) {
        DEBUG("i=", i, dp[i][0][0], dp[i][1][0]);
        DEBUG("i=", i, dp[i][0][1], dp[i][1][1]);
    }

    return dp[na][0][1] + dp[na][1][1];
}

void _main() {
    ll A,B;
    cin >> A >> B;

    // vector<ll> list;
    // FOR(i, A, B+1) {
    //     auto is = to_string(i);
    //     if (is.find('4') != string::npos || is.find('9') != string::npos) {
    //         list.push_back(i);
    //     }
    // }
    //
    // DEBUG(list.size());
    // DEBUG(list);

    cout << count(B) - count(A-1) << endl;
}

int main() {
    _main();
    return 0;
}
