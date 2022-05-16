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


ll f(string s) {
    int n = s.size();
    set<string> ss;
    ss.insert(s);
    REP(i, n) {
        auto s0 = s.substr(0, i+1);
        auto s1 = s.substr(i+1);
        ss.insert(s1 + s0);
    }
    return ss.size();
}

void _main() {
    int N, K;
    string S;
    cin >> N >> K >> S;

    int n = S.size();
    REP(i, n) {
        f(S);
    }

}

int main() {
    _main();
    return 0;
}

// 45minで断念
// 計算量を満たす解法が見つからず
// 最後の5minで考えた際、Nを等分に分割できる約数を考えればよさそうなところまで思いつく
//
