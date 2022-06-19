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
    int N;
    cin >> N;

    vector<vector<int>> dist(3, vector(N+1, 0));
    int res = 0;

    FOR(i, 3, N+1) {
        cout << "? 1 " << i << endl;
        cin >> res;
        if (res == -1) return;
        dist[1][i] = res;
    }
    FOR(i, 3, N+1) {
        cout << "? 2 " << i << endl;
        cin >> res;
        if (res == -1) return;
        dist[2][i] = res;
    }

    REP(i, 3) DEBUG(dist[i]);

    int ans = INT_MAX/2;
    FOR(k, 3, N+1) {
        auto a = dist[1][k] + dist[2][k];
        if (a > N) {
            cout << "! " << abs(dist[1][k]-dist[2][k]) << endl;
            return;
        }
        ans = min(ans, a);
    }
    cout << "! " << ans << endl;
}

int main() {
    _main();
    return 0;
}

