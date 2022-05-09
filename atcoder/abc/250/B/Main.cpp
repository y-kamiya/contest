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
    int N, A, B;
    cin >> N >> A >> B;

    vector<vector<int>> field(N*A, vector(N*B, 0));
    int color = 0;
    REP(h, N) {
        color = h % 2 == 0 ? 0 : 1;
        REP(w, N) {
            REP(i, A) REP(j, B) {
                field[h*A+i][w*B+j] = color;
            }
            color = 1 - color;
        }
    }

    REP(i, N*A) {
        REP(j, N*B) {
            if (field[i][j] == 0) cout << '.';
            else cout << '#';
        }
        cout << endl;
    }
}

int main() {
    _main();
    return 0;
}

