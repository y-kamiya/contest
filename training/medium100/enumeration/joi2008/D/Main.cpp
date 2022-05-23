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


struct P {
    int x, y;
    P(int _x=0, int _y=0): x(_x), y(_y) {}
    P operator+(const P &p) const {
        return P(x+p.x, y+p.y);
    }
    P operator-(const P &p) const {
        return P(x-p.x, y-p.y);
    }
    bool operator<(const P &p) const {
        return x < p.x || y < p.y;
    }
    bool operator==(const P &p) const {
        return x == p.x && y == p.y;
    }

    struct Hash {
        size_t operator()(const P &p) const {
            return ((size_t)(p.x) << 32ul) | (size_t)(p.y);
        }
    };
};


void _main() {
    int m, n;
    cin >> m;
    vector<P> pm(m);
    REP(i, m) cin >> pm[i].x >> pm[i].y;
    cin >> n;
    vector<P> pn(n);
    REP(i, n) cin >> pn[i].x >> pn[i].y;

    unordered_map<P, bool, P::Hash> exist;
    REP(i, n) {
        exist[pn[i]] = true;
    }
     

    REP(i, n) {
        auto p = pn[i];
        P ans;
        FOR(j, 1, m) {
            if (j == 1) {
                ans = p - pm[0];
                DEBUG(ans.x, ans.y);
            }
            auto dp = pm[j] - pm[j-1];
            p = p + dp;
            DEBUG(i, j, p.x, p.y);
            if (exist.count(p) == 0) break;
            DEBUG(i, j, p.x, p.y);
            if (j == m-1) {
                cout << ans.x << " " << ans.y << endl;
                return;
            }
        }
    }

}

int main() {
    _main();
    return 0;
}

