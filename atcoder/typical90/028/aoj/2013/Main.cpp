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

int to_sec(string s) {
    vector<string> ss;
    string str = "";
    REP(i, s.size()) {
        if (s[i] == ':') {
            ss.push_back(str);
            str = "";
        } else {
            str += s[i];
        }
    }
    ss.push_back(str);

    auto H = stoi(ss[0]);
    auto M = stoi(ss[1]);
    auto S = stoi(ss[2]);
    return H*60*60 + M*60 + S;
}

void _main(int N) {
    int M = 24*60*60;
    vector<int> s(M+1, 0);
    REP(i, N) {
        string s0, s1; cin >> s0 >> s1;
        auto t0 = to_sec(s0);
        auto t1 = to_sec(s1);
        s[t0]++;
        s[t1]--;
    }

    REP(i, M) {
        s[i+1] += s[i];
    }

    cout << *max_element(ALL(s)) << endl;
    
}

int main() {
    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;
        _main(N);
    }
    return 0;
}

