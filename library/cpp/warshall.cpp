#include <bits/stdc++.h>
#include <climits>
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

static const ll INF = LLONG_MAX/2;

vector<int> get_path(const vector<vector<ll>> &prev, int s, int t) {
    vector<int> path;
    for (int cur = t; cur != s; cur = prev[s][cur]) {
        path.push_back(cur);
    }
    path.push_back(s);
    reverse(ALL(path));
    return path;
}

void _main() {
    int V, E;
    cin >> V >> E;

    vector<vector<ll>> dp(V, vector(V, INF));
    REP(i, V) dp[i][i] = 0;

    REP(i, E) {
        int s,t,d;
        cin >> s >> t >> d;
        dp[s][t] = d;
    }

    vector<vector<ll>> prev(V, vector(V, -1ll));
    REP(i, V) prev[i][i] = i;
    REP(i, V) REP(j, V) if (dp[i][j] != INF) {
        prev[i][j] = i;
    }

    REP(k, V) {
        REP(i, V) {
            REP(j, V) {
                if (dp[i][j] > dp[i][k] + dp[k][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                    prev[i][j] = prev[k][j];
                }
            }
        }
    }

    REP(i, V) DEBUG(prev[i]);
    DEBUG(get_path(prev, 1, 3));

    REP(i, V) {
        if (dp[i][i] < 0) {
            cout << "NEGATIVE CYCLE" << endl;
            return;
        }
    }

    REP(i, V) {
        REP(j, V) {
            if (dp[i][j] > 2e9) cout << "INF";
            else cout << dp[i][j];
            if (j != V-1) cout << " ";
        }
        cout << endl;
    }
}

int main() {
    _main();
    return 0;
}


