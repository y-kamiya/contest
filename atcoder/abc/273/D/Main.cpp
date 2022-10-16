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
template<typename T0, typename T1, typename... Tail>
void print(pair<T0,T1> p, Tail... t) {
    cout << "(" << p.first << "," << p.second << ")";
    print(t...);
}
template<typename T, typename... Tail>
void print(vector<T> vec, Tail... t) {
    cout << "["; for (const auto &e : vec) { cout << e << ", "; } cout << "] ";
    print(t...);
}
#ifdef _DEBUG
#define DEBUG(...) print(__VA_ARGS__)
#else
#define DEBUG(...)
#endif


void _main() {
    int H,W,r,c,N;
    cin >> H >> W >> r >> c >> N;

    map<int,set<int>> br, bc;
    REP(i, N) {
        int r,c; cin >> r >> c;
        br[r].insert(c);
        bc[c].insert(r);
    }

    int Q; cin >> Q;
    REP(i, Q) {
        char d; int l; cin >> d >> l;
        if (d == 'D') {
            auto it = bc[c].lower_bound(r);
            if (it == bc[c].end()) {
                r = min(r+l, H);
            } else {
                r = min(*it-1, r+l);
            }
        }
        if (d == 'U') {
            auto it = bc[c].lower_bound(r);
            if (it == bc[c].begin()) {
                r = max(r-l, 1);
            } else {
                r = max(*(--it)+1, r-l);
            }
        }
        if (d == 'R') {
            auto it = br[r].lower_bound(c);
            if (it == br[r].end()) {
                c = min(c+l, W);
            } else {
                c = min(*it-1, c+l);
            }
        }
        if (d == 'L') {
            auto it = br[r].lower_bound(c);
            if (it == br[r].begin()) {
                c = max(c-l, 1);
            } else {
                c = max(*(--it)+1, c-l);
            }
        }

        cout << r << " " << c << endl;
    }

}

int main() {
    _main();
    return 0;
}

