#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <iterator>
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


static const double EPS = 1e-10;

void _main() {
    ll N;
    cin >> N;

    vector<int> X(N), Y(N);
    REP(i, N) cin >> X[i] >> Y[i];

    ll c0 = 0;
    ll c1 = 0;
    REP(i, N) {
        vector<double> as;
        REP(j, N) {
            if (i == j) continue;
            auto x = X[j] - X[i];
            auto y = Y[j] - Y[i];
            auto a = atan2(y, x);
            as.push_back(a);
        }
        sort(ALL(as));
        REP(j, as.size()) {
            as.push_back(as[j] + 2*M_PI);
        }
        DEBUG(as);

        REP(j, N-1) {
            auto itl = lower_bound(ALL(as), as[j] + M_PI/2 - EPS);
            auto itu = upper_bound(ALL(as), as[j] + M_PI/2 + EPS);
            c0 += itu - itl;
            c1 += lower_bound(ALL(as), as[j] + M_PI) - itu;
            DEBUG(i, j, c0, c1);
        }

    }

    ll c2 = N * (N-1) * (N-2) / 6 - c0 - c1;
    cout << c2 << " " << c0 << " " << c1 << endl;
}

int main() {
    _main();
    return 0;
}

