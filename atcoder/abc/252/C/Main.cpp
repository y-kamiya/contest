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

    vector<string> S(N);
    REP(i, N) cin >> S[i];

    int ans = INT_MAX;
    REP(i, 10) {
        vector<int> a(10, 0);
        REP(j, N) {
            REP(k, 10) {
                if(i == S[j][k] - '0') ++a[k];
            }
        }
        DEBUG(a);
        int n = 0;
        int t = 0;
        while (n < N) {
            int index = t % 10;
            if (a[index] > 0) {
                DEBUG(index, a[index], n, t);
                --a[index];
                ++n;
            }
            ++t;
        }
        ans = min(ans, t);
    }

    cout << ans-1 << endl;
}

int main() {
    _main();
    return 0;
}

// AC 21:32

