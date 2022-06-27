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
    int N, M;
    cin >> N >> M;

    vector<vector<int>> s(N, vector(N, 0));
    REP(_, M) {
        int a,b,x;
        cin >> a >> b >> x;
        --a; --b;
        ++s[a][b];
        if (b+1 < N) --s[a][b+1];
        if (a+x+1 < N) {
            --s[a+x+1][b];
            if (b+x+2 < N) ++s[a+x+1][b+x+2];
        }
        if (a+x+2 < N) {
            ++s[a+x+2][b+1];
            if (b+x+2 < N) --s[a+x+2][b+x+2];
        }
    }
    REP(i, N) DEBUG(s[i]);

    REP(i, N) {
        REP(j, N-1) {
            if (i < j) break;
            s[i][j+1] += s[i][j];
        }
    }
    REP(j, N) {
        FOR(i, j, N-1) {
            s[i+1][j] += s[i][j];
        }
    }

    REP(i, N) {
        REP(j, N) {
            if (i < j) break;
            if (i == N-1) break;
            DEBUG(i, j, s[i][j]);
            s[i+1][j+1] += s[i][j];
        }
    }

    REP(i, N) DEBUG(s[i]);

    int ans = 0;
    REP(i, N) {
        REP(j, N) {
            if (i < j) break;
            if (s[i][j] > 0) ++ans;
        }
    }
    cout << ans << endl;

}

int main() {
    _main();
    return 0;
}

