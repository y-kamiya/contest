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

    int M = 1000;
    vector<vector<int>> s(M+1, vector(M+1, 0));
    REP(i, N) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        s[ly][lx]++;
        s[ly][rx]--;
        s[ry][lx]--;
        s[ry][rx]++;
    }

    DEBUG("-------------");
    REP(i, M) DEBUG(s[i]);
    REP(i, M) {
        REP(j, M) {
            s[i][j+1] += s[i][j];
        }
    }

    DEBUG("-------------");
    REP(i, M) DEBUG(s[i]);

    REP(j, M) {
        REP(i, M) {
            s[i+1][j] += s[i][j];
        }
    }

    DEBUG("-------------");
    REP(i, M) DEBUG(s[i]);

    vector<int> cnt(N+1, 0);
    REP(i, M) REP(j, M) {
        cnt[s[i][j]]++;
    }

    FOR(i, 1, N+1) cout << cnt[i] << endl;
}

int main() {
    _main();
    return 0;
}

