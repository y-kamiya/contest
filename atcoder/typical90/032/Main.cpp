#include <algorithm>
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


static const int INF = INT_MAX/2;
void _main() {
    int N, M;
    cin >> N;

    vector<vector<int>> A(N, vector(N, 0));
    REP(i, N) REP(j, N) cin >> A[i][j];

    cin >> M;
    vector<vector<int>> B(N, vector(N, 0));
    REP(i, M) {
        int x,y; cin >> x >> y;
        --x; --y;
        B[x][y] = 1;
        B[y][x] = 1;
    }

    vector<int> a(N);
    REP(i, N) a[i] = i;

    int ans = INF;
    do {
        int time = 0;
        bool can_goal = true;
        REP(i, N-1) {
            if (B[a[i]][a[i+1]]) {
                can_goal = false;
                break;
            }
            time += A[a[i]][i];
        }
        if (can_goal) {
            time += A[a[N-1]][N-1];
            ans = min(ans, time);
        }
    } while (next_permutation(ALL(a)));

    if (ans == INF) ans = -1;
    cout << ans << endl;

}

int main() {
    _main();
    return 0;
}

