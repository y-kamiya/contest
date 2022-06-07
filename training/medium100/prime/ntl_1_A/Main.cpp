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
    int n;
    cin >> n;

    vector<int> divs, primes, ans;
    int sqrtn = sqrt(n);
    FOR(i, 2, sqrtn+1) {
        if (n % i == 0) {
            divs.push_back(i);
            divs.push_back(n/i);
        }
    }

    sort(ALL(divs));

    REP(i, divs.size()) {
        int d = divs[i];
        bool is_prime = true;
        FOR(j, 2, d) {
            if (d % j == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) primes.push_back(d);
    }

    DEBUG(primes);

    int N = n;
    REP(i, primes.size()) {
        int p = primes[i];
        while (n % p == 0) {
            ans.push_back(p);
            n /= p;
        }
    }

    DEBUG(ans);

    cout << N << ": ";
    if (ans.size() == 0) {
        cout << N << endl;
        return;
    }
    REP(i, ans.size()) {
        cout << ans[i];
        if (i != ans.size()-1) cout << " ";
    }
    cout << endl;

}

int main() {
    _main();
    return 0;
}

// AC 32
// 18くらいでprime判定だけのナイーブな実装done
// ただし、約数をとってからprime判定をする必要があったためそこから修正
