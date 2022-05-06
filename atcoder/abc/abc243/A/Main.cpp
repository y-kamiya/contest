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


void _main() {
    int V, A, B, C;
    cin >> V >> A >> B >> C;

    while (true) {
        if (V < A) {
            cout << "F" << endl;
            return;
        }
        V -= A;

        if (V < B) {
            cout << "M" << endl;
            return;
        }
        V -= B;

        if (V < C) {
            cout << "T" << endl;
            return;
        }
        V -= C;
    }
}

int main() {
    _main();
    return 0;
}

