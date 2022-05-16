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
    int N;
    string S;
    cin >> N >> S;

    deque<int> odd;
    deque<int> even;
    int n = S.size();
    for(int i=0; i+2<n; ++i) {
        if (S.substr(i, 3) == "ARC") {
            int s = i;
            int e = i+2;
            int count = 1;
            while(0<=i && i<n) {
                if (S[--s] == 'A' && S[++e] == 'C') ++count;
                else break;
            }
            if (count > 1) odd.push_back(count-1);
            else even.push_back(count);
        }
    }
    // while(!odd.empty()) {
    //     DEBUG("odd", odd.front());
    //     odd.pop_front();
    // }
    // while(!even.empty()) {
    //     DEBUG("even", even.front());
    //     even.pop_front();
    // }

    sort(ALL(odd));

    int ans = 0;
    while (!odd.empty() || !even.empty()) {
        if ((ans+1) % 2 == 0) {
            if (even.empty()) {
                odd.pop_front();
            } else {
                even.pop_front();
            }
        } else {
            if (odd.empty()) {
                even.pop_front();
            } else {
                int &count = odd.back();
                if (count == 1) {
                    odd.pop_back();
                    even.push_back(1);
                } else {
                    --count;
                    // sort(ALL(odd));
                }
            }
        }
        ++ans;
    }

    cout << ans << endl;
}

int main() {
    _main();
    return 0;
}

// 解答によると、実際に操作を行う部分の処理はやらなくてよい
// ARCを含むブロック数またはAAARCCCなどのによる重複回数の和の小さい方は必ず操作可能なことが示せる
// 必ずその条件を満たせるのでは？、という検証をした方がよい
