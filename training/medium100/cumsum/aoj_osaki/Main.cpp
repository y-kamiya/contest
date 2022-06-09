#include <algorithm>
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


static const int M = 60 + 60*60 + 24*60*60;
int to_sec(string t) {
    auto h = t.substr(0,2);
    auto m = t.substr(3,2);
    auto s = t.substr(6,2);
    return stoi(s) + stoi(m)*60 + stoi(h)*60*60;
}

void _main(int n) {
    vector<int> a(M+1, 0);
    REP(i, n) {
        string s, t; cin >> s >> t;
        auto si = to_sec(s);
        auto ti = to_sec(t);
        DEBUG(si, ti);
        ++a[si];
        --a[ti];
    }

    REP(i, M) a[i+1] += a[i];

    auto it = max_element(ALL(a));
    cout << *it << endl;
}

int main() {
    while (true) {
        int n; cin >> n;
        if (n == 0) break;
        _main(n);
    }
    return 0;
}

// AC 21
