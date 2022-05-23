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

    vector<int> x(N), y(N);
    REP(i, N) cin >> x[i] >> y[i];

    vector<int> city(N);
    REP(i, N) city[i] = i;

    vector<double> len;
    do {
        DEBUG(city);
        double sum = 0;
        FOR(i, 1, N) {
            int c0 = city[i-1];
            int c1 = city[i];
            sum += sqrt((x[c1]-x[c0])*(x[c1]-x[c0]) + (y[c1]-y[c0])*(y[c1]-y[c0]));
        }
        len.push_back(sum);
    } while (next_permutation(ALL(city)));

    int size = len.size();
    double ans = 0;
    REP(i, size) {
        ans += len[i];
    }
    ans /= size;

    PRINT_DOUBLE(7, ans);
}

int main() {
    _main();
    return 0;
}


// AC 15
// 12で実装done
