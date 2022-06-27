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


using P = pair<int,int>;
void _main() {
    int N;
    cin >> N;

    vector<P> a;
    REP(i, N) {
        int c; cin >> c;
        if (a.size() == 0) {
            a.emplace_back(c, 1);
            continue;
        }
        auto &p = a.back();
        if ((p.first == c && p.second % 2 == 1)
         || (p.first != c && p.second % 2 == 0)) {
            a.emplace_back(c, 1);
        } else {
            ++p.second;
        }

        // REP(i, a.size()) {
        //     cout << "(" << a[i].first << "," << a[i].second << ") ";
        // }
        // cout << endl;
    }

    if (a.size() == 1) {
        cout << a[0].second << endl;
        return;
    }
    if (a.size() == 2) {
        cout << a[0].second + a[1].second << endl;
        return;
    }

    int ans = 0;
    FOR(i, 1, a.size()-1) {
        ans = max(ans, a[i-1].second + a[i].second + a[i+1].second);
    }
    cout << ans << endl;

}

int main() {
    _main();
    return 0;
}

// AC 20

