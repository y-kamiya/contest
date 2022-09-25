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


void _main() {
    string S, T;
    cin >> S >> T;

    reverse(ALL(S));
    reverse(ALL(T));

    string s = "";
    int ns = S.length();
    int nt = T.length();
    if (ns < nt) {
        cout << "UNRESTORABLE" << endl;
        return;
    }

    auto i = 0;
    while (i <= ns-nt) {
        auto match = true;
        REP(j, nt) {
            if (S[i+j] == '?') continue;
            if (S[i+j] == T[j]) continue;
            match = false;
            break;
        }
        if (match) {
            s += T;
            i += nt;
            break;
        } else {
            if (S[i] == '?') s.push_back('a');
            else s.push_back(S[i]);
            ++i;
        }

        if (i == ns-nt) {
            cout << "UNRESTORABLE" << endl;
            return;
        }
    }

    DEBUG(i, s);
    while (i < ns) {
        if (S[i] == '?') s.push_back('a');
        else s.push_back(S[i]);
        ++i;
    }

    reverse(ALL(s));

    cout << s << endl;
}

int main() {
    _main();
    return 0;
}

// WA ns < nt忘れ
// AC 27
