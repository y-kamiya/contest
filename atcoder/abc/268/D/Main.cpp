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

bool dfs(const vector<string> &S, const vector<string> &T, int nbar, int i, string s) {
    s += S[i];

    if (nbar < 0) return false;
    if (s.size() > 16) return false;
    if (i == S.size()-1) {
        if (s.size() < 3) return false;
        auto e = binary_search(ALL(T), s);
        if (!e) {
            cout << s << endl;
        }
        return !e;
    }

    auto bar = nbar;
    FOR(k, 0, nbar) {
        s += "_";
        --bar;
        auto ok = dfs(S, T, bar, i+1, s);
        if (ok) return true;
    }
    return false;
}

void _main() {
    int N, M;
    cin >> N >> M;

    vector<string> S(N), T(M);
    REP(i, N) cin >> S[i];
    REP(i, M) cin >> T[i];

    sort(ALL(T));

    int ns = 0;
    REP(i, N) ns += S[i].size();
    if (ns + N-1 < 3) {
        cout << -1 << endl;
        return;
    }

    int nbar = 16 - ns;
    if (nbar-N+1 < 0) {
        cout << -1 << endl;
        return;
    }

    do {
        DEBUG(S);
        string s = "";
        auto ok = dfs(S, T, nbar, 0, s);
        if (ok) {
            return;
        }

    } while (next_permutation(ALL(S)));

    cout << -1 << endl;
}

int main() {
    _main();
    return 0;
}

