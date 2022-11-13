#include <bits/stdc++.h>
using namespace std;

class ostreamFork {
public:
    ostream &os1,&os2;
    ostreamFork(ostream& os1, ostream& os2) : os1(os1), os2(os2) {}
};
template <class Data>
ostreamFork& operator<<(ostreamFork& osf, Data d) {
    osf.os1 << d; osf.os2 << d; return osf;
}
ostreamFork& operator<<(ostreamFork& osf, ostream& (*f)(ostream&)) {
    osf.os1 << f; osf.os2 << f; return osf;
}
template <class ManipData>
ostreamFork& operator<<(ostreamFork& osf, ostream& (*f)(ostream&, ManipData)) {
    osf.os1 << f; osf.os2 << f; return osf;
}

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

ofstream file("_output.txt");
ostreamFork osf(file, cout);

struct P {
    int x,y;
    P(int x, int y): x(x), y(y){};
    P operator+(const P &p) {
        return {x+p.x, y+p.y};
    }
    bool operator<(const P& p) const {
        if (x == p.x) return y < p.y;
        return x < p.x;
    }
    friend ostream& operator<<(ostream& os, const P& e) {
        return os << "(" << e.x << "," << e.y << ")";
    }
};

static const vector<P> ns = {{0,1},{1,0},{0,-1},{-1,0}};

void _main() {
    int H,W;
    cin >> H >> W;

    vector<string> G(H);
    REP(i, H) cin >> G[i];

    vector<vector<bool>> done(H, vector(W, false));
    deque<tuple<P,set<P>>> que;
    REP(i, H) REP(j, W) {
        if (G[i][j] == 'S') {
            que.push_back({{j,i},{}});
        }
    }

    while (!que.empty()) {
        auto [p, s] = que.front();
        que.pop_front();
        s.insert(p);
        DEBUG(p);

        for (const auto &_p : ns) {
            P np = p + _p;
            DEBUG("bbbbbb", p, _p, np);
            if (np.y < 0 || H <= np.y) continue;
            if (np.x < 0 || W <= np.x) continue;
            if (G[np.y][np.x] == '#') continue;
            if (G[np.y][np.x] == 'S') {
                if (s.size() < 4) continue;
                Yes(1);
                return;
            }
            if (s.find(np) != s.end()) continue;
            DEBUG("aaaaaa", np);
            que.push_back({np, s});
        }
    }
    
    Yes(0);
}

int main() {
    _main();
    _main();
    _main();
    return 0;
}

