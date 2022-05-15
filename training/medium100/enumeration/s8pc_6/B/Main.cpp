#include <bits/stdc++.h>
#include <climits>
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

    vector<int> A(N), B(N);
    REP(i, N) cin >> A[i] >> B[i];

    ll ans = LLONG_MAX / 2;

    REP(i, N) REP(j, N) {
        int entr = A[i];
        int exit = B[j];
        // if (exit < entr) swap(entr, exit);

        ll sum = 0;
        REP(k, N) {
            sum += abs(A[k] - entr);
            sum += abs(B[k] - A[k]);
            sum += abs(B[k] - exit);
            // if (A[i] < entr) sum += 2 * (entr - A[i]);
            // if (exit < B[i]) sum += 2 * (B[i] - exit);
            // sum += exit - entr;
            DEBUG(k, sum);
        }
        DEBUG(i, j, sum);
        ans = min(ans, sum);
    }

    cout << ans << endl;
}

int main() {
    _main();
    return 0;
}

// AC 30
// 方針決定まで17
// A,Bのどこかに設置すればよさそうというのは7くらいにわかったが、本当にそれでいいのか考えるのに10くらい使ってしまった
// 23実装done
// ここで客はAの後Bにいくという順番は確定という条件であることに気づく
