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

static const int MAX = 10000;

void _main() {
    ll N, A, B, C;
    cin >> N >> A >> B >> C;

    ll ans = MAX;
    REP(i, MAX) REP(j, MAX-i) {
        ll sum = i * A + j * B;
        if (N-sum < 0) continue;
        if ((N-sum) % C == 0) {
            ans = min(ans, i+j+(N-sum)/C);
        }
    }

    cout << ans << endl;
}

int main() {
    _main();
    return 0;
}

// AC 36min
// 最初20minほどでdpを使う方針で考えたがうまくいかず
// そこでdpなど使わなくとも問題ないことに気づき30minまでに実装
// 和がintを超える場合に対応してなくてWA
