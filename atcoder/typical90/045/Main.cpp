#include <bits/stdc++.h>
#include <climits>
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

ll distance(ll x1, ll x2, ll y1, ll y2) {
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

static const ll INF = LLONG_MAX;
void _main() {
    int N, K;
    cin >> N >> K;

    vector<ll> X(N), Y(N), dist(1<<N, 0);
    REP(i, N) cin >> X[i] >> Y[i];

    vector<vector<ll>> D(N, vector(N, 0ll)), dp(1<<N, vector(N, INF));
    REP(i, N) REP(j, N) D[i][j] = distance(X[i], X[j], Y[i], Y[j]);

    REP(i, 1<<N) {
        REP(j, N) {
            REP(k, j) {
                if (i&(1<<j) &&  i&(1<<k)) {
                    dist[i] = max(dist[i], D[j][k]);
                }
            }
        }
    }

    REP(i, N) DEBUG(D[i]);
    DEBUG(dist);

    dp[0][0] = 0;
    FOR(i, 0, 1<<N) {
        FOR(cnt, 1, K+1) {
            for (int j=i; j>0; j=(j-1)&i) {
                dp[i][cnt] = min(dp[i][cnt], max(dp[i-j][cnt-1], dist[j]));
                DEBUG("jjj", j, i-j, cnt-1, dp[i-j][cnt-1], dist[j]);
            }
            DEBUG(i, cnt, dp[i][cnt]);
        }
    }

    osf << dp[(1<<N)-1][K] << endl;

}

int main() {
    _main();
    return 0;
}

