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


bool is_ok(const vector<int> &H, const vector<int> &S, ll h) {
    int n = H.size();
    vector<int> t(n);
    REP(i, n) {
        ll l = -1;
        ll r = n+1;
        while (abs(r-l) > 1) {
            ll mid = (l+r)/2;
            if (H[i] + mid * S[i] > h) r = mid;
            else l = mid;
        }
        t[i] = r;
    }

    sort(ALL(t));
    REP(i, n) {
        if (t[i] <= i) return false;
    }
    return true;
}

void _main() {
    int N;
    cin >> N;
    vector<int> H(N), S(N);
    REP(i, N) cin >> H[i] >> S[i];

    ll ng = -1;
    ll ok = 1e15;
    while (abs(ok-ng) > 1) {
        ll mid = (ng+ok)/2;
        if (is_ok(H, S, mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}

int main() {
    _main();
    return 0;
}

// AC 35.5
// 解くのは2回目だが、解法に確信が持てるまで25程度かかった
// 超えてしまう時刻を照準に並べて、時刻より小さな値が存在すれば成り立たない
