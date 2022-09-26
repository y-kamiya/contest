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


void _main() {
    string S;
    cin >> S;

    int sz = S.size();
    vector<vector<int>> dp(sz, vector(sz, 0));
    FOR(i, 0, sz-2) {
        if (S.substr(i, 3) != "iwi") continue;
        dp[i][i+2] = 1;
    }
    REP(i, sz) DEBUG(dp[i]);

    FOR(i, 3, sz) {
        FOR(j, 0, sz) {
            auto l = j;
            auto r = j + i;
            if (r >= sz) break;

            FOR(k, l, r) {
                dp[l][r] = max(dp[l][r], max(dp[l][k], dp[k+1][r]));
            }


            if (S[l] == 'i' && S[r] == 'i') {
                FOR(k, l+1, r) {
                    if (S[k] != 'w') continue;
                    auto a = dp[l+1][k-1];
                    auto b = dp[k+1][r-1];
                    auto sign = 0;
                    if (k-l-1 == 3*a && r-k-1 == 3*b) {
                        sign = 1;
                    }
                    dp[l][r] = max(dp[l][r], sign + a + b);
                }
            }
        }
    }

    REP(i, sz) DEBUG(dp[i]);

    cout << dp[0][sz-1] << endl;
}

int main() {
    _main();
    _main();
    _main();
    return 0;
}

