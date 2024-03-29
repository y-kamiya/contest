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


void _main() {
    int N;
    cin >> N;

    vector<int> P(N), p, q;
    REP(i, N) cin >> P[i];

    int last = INT_MAX;
    FORR(i, N-1, 0) {
        p.push_back(P[i]);
        if (P[i] < last) {
            last = P[i];
        } else {
            break;
        }
    }

    int t = p.back();
    int s = 0;
    REP(i, p.size()) {
        if (p[i] < t) s = max(s, p[i]);
    }

    REP(i, p.size()) {
        if (p[i] != s) q.push_back(p[i]);
    }
    sort(ALL(q));
    reverse(ALL(q));

    REP(i, N) {
        if (i < N-(q.size()+1)) osf << P[i] << " ";
        else break;
    }

    osf << s << " ";
    REP(i, q.size()) {
        osf << q[i] << " ";
    }
    osf << endl;
        
}

int main() {
    _main();
    return 0;
}

