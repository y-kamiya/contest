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
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    REP(i, N) cin >> a[i];

    deque<int> que;
    set<int> s;
    int ans = 0;
    REP(i, N) {
        if (s.size() < K || s.find(a[i]) != s.end()) {
            que.push_back(a[i]);
            s.insert(a[i]);
            ans = max(ans, (int)que.size());
            continue;
        }

        while (s.size() == K) {
            auto f = que.front();
            while (f == que.front()) {
                que.pop_front();
            }
            s.erase(f);
        }

        que.push_back(a[i]);
        s.insert(a[i]);
        ans = max(ans, (int)que.size());
    }

    cout << ans << endl;
}

int main() {
    _main();
    return 0;
}

