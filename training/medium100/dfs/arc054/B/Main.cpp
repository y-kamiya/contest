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


bool is_ok(double t, double P, double mx) {
    return mx + P / pow(2, mx/1.5) < t;
}

void _main() {
    double P;
    cin >> P;

    double mx = 1.5 * log2(2.0/3 * P * log(2));
    if (mx < 0) mx = 0;
    double l = 0;
    double r = P;
    while (abs(r-l) > 1e-9) {
        double mid = (l+r)/2;
        if (is_ok(mid, P, mx)) r = mid;
        else l = mid;
    }

    PRINT_DOUBLE(8, r);
}


// 別解: 3分探索であれば微分を手計算せずに済む
double f(double x, double P) {
    return x + P / pow(2, x/1.5);
}

void __main() {
    double P;
    cin >> P;

    double l = 0;
    double r = 1e9;
    int count = 0;
    while (count < 500) {
        ++count;
        double mid0 = l + abs(r-l)/3;
        double mid1 = l + abs(r-l)/3 * 2;
        if (f(mid0, P) < f(mid1, P)) r = mid1;
        else l = mid0;
    }

    PRINT_DOUBLE(8, f(r, P));
}

int main() {
    __main();
    return 0;
}

// AC 31.5
// 微分の手計算に時間がかかった
