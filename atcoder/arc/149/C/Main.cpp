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
template<typename... Tail>
void print(pair<int,int> p, Tail... t) {
    cout << "(" << p.first << "," << p.second << ")";
    print(t...);
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



void _main() {
    int N;
    cin >> N;

    int M = 2*N*N;
    vector<bool> is_prime(M+1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    FOR(i, 2, M+1) {
        int j = 2;
        while (i * j <= M) {
            is_prime[i*j] = false;
            ++j;
        }
    }

    vector<vector<int>> s(N, vector(N, 0));
    map<int,int> os;
    map<int,int> es;
    FOR(i, 1, N*N+1) {
        if (i % 2 == 1) os[i] = 1;
        else es[i] = 1;
    }

    vector<pair<int,int>> ps;
    for(auto &o : os) {
        for(auto &e : es) {
            // DEBUG(o.first, e.first);
            if (!e.second) continue;
            if (is_prime[o.first+e.first]) continue;
            o.second = 0;
            e.second = 0;
            ps.emplace_back(o.first, e.first);
            break;
        }
        if (ps.size() == N) break;
    }

    vector<int> ov, ev;
    for(auto &o : os) if (o.second) ov.push_back(o.first);
    for(auto &e : es) if (e.second) ev.push_back(e.first);
    
    REP(i, N) DEBUG(ps[i]);

    if (N % 2 == 0) {
        int n = N/2 - 1;
        REP(i, N) {
            s[n][i] = ps[i].first;
            s[n+1][i] = ps[i].second;
        }

        REP(i, n) REP(j, N) s[i][j] = ov[i*N+j];
        FOR(i, n+2, N) REP(j, N) s[i][j] = ev[(i-n-2)*N+j];

    } else {
        int n = N/2;
        DEBUG("------------");
        REP(i, N) DEBUG(ps[i]);
        REP(i, N) REP(j, N) {
            if (i == j) continue;
            if (!is_prime[ps[i].first + ps[j].second]) {
                swap(ps[i], ps[n]);
                swap(ps[j], ps[n+1]);
                break;
            }
        }
        DEBUG("------------");
        REP(i, N) DEBUG(ps[i]);
        REP(i, N) {
            if (i <= n) {
                s[n][i] = ps[i].first;
                s[n+1][i] = ps[i].second;
            } else {
                s[n-1][i] = ps[i].first;
                s[n][i] = ps[i].second;
            }
        }

        REP(i, n) REP(j, N) {
            int index = i*N+j;
            if (index == ov.size()) break;
            s[i][j] = ov[index];
        }
        int c = 0;
        FOR(i, n+1, N) FOR(j, 0, N) {
            if (i == n+1 && j < 3) continue;
            s[i][j] = ev[c];
            ++c;
        }
    }

    REP(i, N) {
        REP(j, N) {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    _main();
    return 0;
}

