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
    int M, N, K;
    cin >> M >> N >> K;

    vector<vector<int>> field(M, vector(N, 0));
    REP(i, M) {
        REP(j, N) {
            char c; cin >> c;
            int k = 0;
            if (c == 'O') k = 1;
            if (c == 'I') k = 2;
            field[i][j] = k;
        }
    }
    REP(i, M) DEBUG(field[i]);

    vector<vector<vector<int>>> s(3, vector(M+1, vector(N+1, 0)));
    REP(i, M) REP(j, N) REP(k, 3) {
        s[k][i+1][j+1] = s[k][i+1][j];
        if (field[i][j] == k) {
            ++s[k][i+1][j+1];
        }
    }
    REP(j, N) REP(i, M) REP(k, 3) {
        s[k][i+1][j+1] += s[k][i][j+1];
    }

    REP(i, M+1) DEBUG(s[0][i]);

    REP(_, K) {
        int a,b,c,d; cin >> a >> b >> c >> d;
        REP(k, 3) {
            cout << s[k][c][d] - s[k][c][b-1] - s[k][a-1][d] + s[k][a-1][b-1];
            if (k != 2) cout << " ";
        }
        cout << endl;
    }
}

int main() {
    _main();
    return 0;
}

