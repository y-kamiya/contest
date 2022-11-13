#include <algorithm>
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

    vector<int> a(N), two(N,0), thr(N,0), rest(N,0);
    REP(i, N) cin >> a[i];

    REP(i, N) {
        int b = a[i];
        while (b > 0) {
            if (b % 2 == 0) {
                b /= 2;
                two[i]++;
            } else break;
        }
        while (b > 0) {
            if (b % 3 == 0) {
                b /= 3;
                thr[i]++;
            } else break;
        }
        rest[i] = b;
    }

    bool same = true;
    REP(i, N) {
        if (rest[0] != rest[i]) {
            same = false;
            break;
        }
    }
    if (!same) {
        osf << -1 << endl;
        return;
    }

    int ans = 0;
    int min_two = *min_element(ALL(two));
    REP(i, N) {
        ans += two[i] - min_two;
    }
    int min_thr = *min_element(ALL(thr));
    REP(i, N) {
        ans += thr[i] - min_thr;
    }

    osf << ans << endl;
}

int main() {
    _main();
    return 0;
}

