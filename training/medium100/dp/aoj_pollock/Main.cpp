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

static const int MAX = 1e6;

void _main(int n) {
}

int f(int n) {
    return n * (n+1) * (n+2) / 6;
}

int main() {
    vector<int> a;
    FOR(i, 1, MAX+1) {
        int n = f(i);
        if (n > MAX) break;
        a.push_back(n);
    }
    int sz = a.size();

    vector<int> dp(MAX+1, MAX);
    vector<int> dp2(MAX+1, MAX);
    dp[0] = 0;
    dp2[0] = 0;

    FOR(i, 1, MAX+1) {
        DEBUG("i = ", i);
        REP(j, sz) {
            if (a[j] > i) break;
            dp[i] = min(dp[i], dp[i-a[j]] + 1);

            if (a[j] % 2 == 0) continue;
            dp2[i] = min(dp2[i], dp2[i-a[j]] + 1);
            DEBUG(j, dp2[i], a[j]);
        }
    }

    while (true) {
        int n; cin >> n;
        if (n == 0) break;
        cout << dp[n] << " " << dp2[n] << endl;
    }
    return 0;
}

// AC 37.5
// debug 12
// 奇数の正四面体数の意味を、奇数番目と勘違いして時間を無駄に(debugはすべてそれ)
