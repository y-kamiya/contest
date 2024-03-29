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

bool isOk(const vector<int> &A, int K, int L, int a) {
    int n = A.size();
    int k = 0;
    int last = 0;
    REP(i, n) {
        if (A[i] - last >= a) {
            ++k;
            last = A[i];
        }
        if (k == K) {
            return a <= (L - last);
        }
    }
    return false;
}

void _main() {
    int N, L, K;
    cin >> N >> L >> K;

    vector<int> A(N), B(N);
    REP(i, N) cin >> A[i];
    REP(i, N) {
        if (i == 0) B[i] = A[i];
        else B[i] = A[i] - A[i-1];
    }

    int l = -1;
    int r = L+1;
    while (r-l > 1) {
        int mid = (l+r)/2;
        DEBUG(l, r, mid);
        if (isOk(A, K, L, mid)) l = mid;
        else r = mid;
    }

    cout << l << endl;
}

int main() {
    _main();
    return 0;
}

// 30minほど考えて計算量の収まる解法は思いつかず
// 公式解答のstep1を読んで二分法を使うことがわかる
// 答えを先にに決めてそれが正しいか否かを調べていくという方法は目からウロコな感じ
// そこから20minほどでAC
