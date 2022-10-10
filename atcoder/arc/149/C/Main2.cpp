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

void output(const vector<int> &vec, int N) {
    int count = 0;
    for (auto n : vec) {
        ++count;
        cout << n << " ";
        if (count % N == 0) cout << endl;
    }
}

void _main() {
    int N;
    cin >> N;

    if (N == 3) {
        output({9,5,1,3,7,8,6,2,4}, N);
        return;
    }
    if (N == 4) {
        output({15,11,16,12 ,13,3,6,9 ,14,7,8,1 ,4,2,10,5}, N);
        return;
    }
    if (N == 5) {
        output({11,13,15,17,19,21,23,25,1,3,9,5,7,8,6,12,4,2,10,14,16,18,20,22,24}, N);
        return;
    }

    int N2 = N*N;
    vector<int> odd_3, odd_n3, even_3, even_n3;
    FOR(i, 1, N2+1) {
        if (i % 2 == 0) {
            if (i % 3 == 0) even_3.push_back(i);
            else even_n3.push_back(i);
        } else {
            if (i % 3 == 0) odd_3.push_back(i);
            else odd_n3.push_back(i);
        }
    }

    vector<int> ans;
    for (auto n : odd_n3) ans.push_back(n);
    for (auto n : odd_3) ans.push_back(n);
    for (auto n : even_3) ans.push_back(n);
    for (auto n : even_n3) ans.push_back(n);

    output(ans, N);
}

int main() {
    _main();
    return 0;
}

