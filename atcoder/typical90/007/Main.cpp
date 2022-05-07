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


bool isOk(int a, int b) {
    if (a - b >= 0) return true;
    else return false;
}

void _main() {
    int N;
    cin >> N;

    vector<int> A(N);
    REP(i, N) cin >> A[i];

    int Q;
    cin >> Q;
    vector<int> B(Q);
    REP(i, Q) cin >> B[i];

    sort(ALL(A));
    DEBUG(A);

    REP(i, Q) {
        auto it = lower_bound(ALL(A), B[i]);
        if (it != A.end()) DEBUG("it =", *(--it), B[i], *(++it));
        int score;
        if (it == A.end()) score = abs(A[N-1] - B[i]);
        else if (it == A.begin()) score = abs(A[0] - B[i]);
        else score = min(abs(*it - B[i]), abs(*(it-1) - B[i]));
        cout << score << endl;
    }

    // REP(i, Q) {
    //     int l = 0;
    //     int r = N-1;
    //     while (r-l > 1) {
    //         int mid = (l+r)/2;
    //         if (isOk(A[mid], B[i])) r = mid;
    //         else l = mid;
    //     }
    //
    //     cout << min(abs(B[i]-A[l]), abs(B[i]-A[r])) << endl;
    // }
}

int main() {
    _main();
    return 0;
}

// AC 15min
// 目視だと出力例のチェックに時間がかかってしまうタイプの問題
// assertを使ったテストの形をそろそろ作った方がいいかも
