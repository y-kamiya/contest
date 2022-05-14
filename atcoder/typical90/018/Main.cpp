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
    ll T, L, X, Y, Q;
    cin >> T >> L >> X >> Y >> Q;

    REP(t, Q) {
        int e;
        cin >> e;

        double y = L/2.0 * cos(-2*M_PI/T * e - 0.5*M_PI);
        double z = L/2.0 * sin(-2*M_PI/T * e - 0.5*M_PI) + L/2.0;
        DEBUG(y, z);

        double dist = sqrt(X*X + (Y-y)*(Y-y));
        DEBUG(dist);
        double rad = atan2(z, dist);

        PRINT_DOUBLE(8, rad / M_PI * 180);
    }
}

int main() {
    _main();
    return 0;
}

// 割り算がintになっていることに気づかず時間がかかった
// また、計算として正しい形を考えるのにもかなり時間かかった
