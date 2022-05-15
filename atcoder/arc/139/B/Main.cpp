#include <bits/stdc++.h>
#include <climits>
#include <queue>
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
    ll N, A, B, X, Y, Z;
    cin >> N >> A >> B >> X >> Y >> Z;

    if (X <= Y/A && X <= Z/B) {
        cout << X*N << endl;
        return;
    }

    if (Y/A > Z/B) {
        swap(Y, Z);
        swap(A, B);
    }

    ll ans = LLONG_MAX / 2;
    if (Z/B < X) {
        int max_a = N/A;
        REP(i, max_a+1) {
            int n_b = (N-A*i) / B;
            ans = min(ans, Y*i + Z*n_b + X*(N-A*i-B*n_b));
        }
        cout << ans << endl;
        return;
    }

    if (Y/A < X) {
        int max_a = N/A;
        REP(i, max_a+1) {
            ans = min(ans, Y*i + X*(N-i));
        }
        cout << ans << endl;
        return;
    }

    // using P = tuple<double, ll, ll>;
    // priority_queue<P, vector<P>, greater<P>> que;
    // que.emplace((double)X, 1, X );
    // que.emplace((double)Y / A, A, Y);
    // que.emplace((double)Z / B, B, Z);
    //
    // ll p = 0;
    // ll sum = 0; 
    // while (!que.empty()) {
    //     auto [cp, v, cost] = que.top();
    //     que.pop();
    //
    //     ll count = (N-p) / v;
    //     p += count * v;
    //     sum += count * cost;
    //     DEBUG(cp, v, cost, count, p, sum);
    //     if (p == N) break;
    // }
    // cout << sum << endl;
}

int main() {
    int T; cin >> T;
    REP(i, T) _main();
    return 0;
}

// 貪欲法の方針で実装完了まで18、sample以外はWA
// その後20min考えるも違うケースがわからなかったのでテストケース確認
// 貪欲法では最小にならないケースがあることにようやく気づく
// コスパ大小によらずうまく組み合わせて、最終的にコスト1を使う回数をへらす方が最小となるケースがある
