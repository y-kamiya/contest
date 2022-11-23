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


static const int INF = INT_MAX/2;
static const vector<pair<int,int>> ds = {{1,0},{0,1},{-1,0},{0,-1}};
void _main() {
    int H,W,rs,cs,rt,ct;
    cin >> H >> W >> rs >> cs >> rt >> ct;
    --rs;--cs;--rt;--ct;

    vector<string> F(H);
    REP(i, H) cin >> F[i];

    vector<vector<int>> C(H, vector(W, INF));
    C[rs][cs] = 0;

    deque<tuple<int,int,int>> que;
    que.emplace_back(rs,cs,0);

    while (!que.empty()) {
        auto [y,x,c] = que.front(); que.pop_front();

        for (auto [dy,dx] : ds) {
            FOR(s, 1, 1001) {
                auto ny = y + s * dy;
                auto nx = x + s * dx;
                if (ny < 0 || H <= ny) break;
                if (nx < 0 || W <= nx) break;
                if (ny == rt && nx == ct) {
                    osf << c << endl;
                    return;
                }
                if (F[ny][nx] == '#') break;
                if (C[ny][nx] < c) break;
                C[ny][nx] = c;
                que.emplace_back(ny,nx,c+1);
            }
        }
    }
}

int main() {
    _main();
    return 0;
}

