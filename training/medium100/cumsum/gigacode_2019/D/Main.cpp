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
    ll H,W,K,V;
    cin >> H >> W >> K >> V;

    vector<vector<ll>> A(H+1, vector(W+1, 0ll));
    FOR(i, 1, H+1) FOR(j, 1, W+1) cin >> A[i][j];

    DEBUG("------------------------------");
    REP(i,  H+1) DEBUG(A[i]);

    REP(i, H) REP(j, W+1) A[i+1][j] += A[i][j];
    REP(i, H+1) REP(j, W) A[i][j+1] += A[i][j];

    DEBUG("------");
    REP(i,  H+1) DEBUG(A[i]);

    int ans = 0;
    FOR(i, 1, H+1) FOR(j, 1, W+1) {
        FORR(h, H, 1) FORR(w, W, 1) {
            if (ans >= h*w) break;
            auto t = i-1;
            auto b = i+h-1;
            auto l = j-1;
            auto r = j+w-1;
            if (b > H || r > W) continue;
            auto v = A[b][r] - A[b][l] - A[t][r] + A[t][l] + h*w*K;
            if (v <= V) {
                DEBUG(i,j,h,w,v);
                ans = max(ans, h*w);
            }
        }
    }

    cout << ans << endl;

}

int main() {
    _main();
    return 0;
}

// AC 44
// 二次元になるとややこしく添字の確認など時間がかかる
// 計算量チェックにも時間かかった
