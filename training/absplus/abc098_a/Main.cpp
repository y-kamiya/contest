#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl

int N;
string S;

int main() {
    cin >> N;
    cin >> S;

    int left = 0;
    int right = 0;
    FOR(i, 1, N) {
        if (S[i] == 'E') ++right;
    }
    int cnt = right;

    FOR(i, 1, N) {
        if (S[i-1] == 'W') ++left;
        if (S[i] == 'E') --right;
        cnt = min(cnt, left + right);
    }

    cout << cnt << endl;

    return 0;
}



