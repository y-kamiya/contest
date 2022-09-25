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
    int N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    vector<vector<int>> pos(N, vector(26, N));
    FORR(i, N-1, 0) {
        if (i < N-1) {
            REP(j, 26) pos[i][j] = pos[i+1][j];
        }
        auto c = S[i] - 'a';
        pos[i][c] = i;
    }

    REP(i, N) DEBUG(pos[i]);

    string s = "";
    int i = 0;
    while (i < N) {
        auto len = s.length();
        REP(j, 26) {
            auto p = pos[i][j];
            if (p > N-K+len) continue;
            s.push_back('a'+j);
            DEBUG(p, s);
            i = p+1;
            break;
        }
        if (len+1 == K) break;
    }

    cout << s << endl;
}

int main() {
    _main();
    return 0;
}

