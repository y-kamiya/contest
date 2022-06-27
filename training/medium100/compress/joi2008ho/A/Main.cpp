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
    int n;
    cin >> n;

    vector<P> a;
    FOR(i, 1, n+1) {
        int c; cin >> c;
        if (a.size() == 0) {
            a.emplace_back(c, 1);
            continue;
        }
        auto &p = a[a.size()-1];
        if (i % 2 == 1) {
            if (p.first == c) ++p.second;
            else a.emplace_back(c, 1);
        } else {
            if (p.first == c) ++p.second;
            else {
                if (a.size() < 2) {
                    p.first = 1 - p.first;;
                    ++p.second;    
                } else {
                    auto count = p.second+1;
                    a.pop_back();
                    auto &pp = a[a.size()-1];
                    pp.second += count;
                }
            }
        }
        // REP(j, a.size()) cout << "(" << a[j].first << "," << a[j].second << ") ";
        // cout << endl;
    }

    int ans = 0;
    REP(i, a.size()) {
        if (a[i].first == 0) ans += a[i].second;
    }

    cout << ans << endl;
}

int main() {
    _main();
    return 0;
}

// AC 24
