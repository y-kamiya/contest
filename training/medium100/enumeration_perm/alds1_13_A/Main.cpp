#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
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

using P = pair<int,int>;

void output(deque<P> Q) {
    vector<vector<char>> field(8, vector(8, '.'));
    REP(i, 8) {
        P p = Q.front();
        DEBUG(p.first, p.second);
        Q.pop_front();
        field[p.first][p.second] = 'Q';
    }
    REP(i, 8) {
        REP(j, 8) {
            cout << field[i][j];
        }
        cout << endl;
    }
}

vector<P> _next = {
    {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},
};

bool is_ok(const deque<P> &Q, const P &p) {
    REP(j, Q.size()) {
        if (Q[j] == p) return false;
    }

    FOR(i, 1, 8) {
        for (auto dp : _next) {
            P np = {p.first + i * dp.first, p.second + i * dp.second};;
            if (np.first < 0 || 8 <= np.first) continue;
            if (np.second < 0 || 8 <= np.second) continue;
            REP(j, Q.size()) {
                if (Q[j] == np) return false;
            }
        }
    }
    return true;
}

void _main() {
    int k;
    cin >> k;

    deque<P> Q;
    REP(i, k) {
        int r, c; cin >> r >> c;
        Q.emplace_back(r, c);
    }

    REP(r, 8) {
        REP(c, 8) {
            if (is_ok(Q, {r,c})) {
                DEBUG(r, c);
                Q.emplace_back(r, c);
            }
            if (Q.size() == 8) {
                output(Q);
                return;
            }
            if (r == 7 && c == 7) {
                auto p = Q.back();
                Q.pop_back();
                r = p.first;
                c = p.second;
                if (r == 7 && c == 7) {
                    auto p = Q.back();
                    Q.pop_back();
                    r = p.first;
                    c = p.second;
                }
                DEBUG("back", r, c);
            }
        }
    }
}



// 順列全探索の形での解答
// はじめから縦横の重複に対する制約を満たした状態で探索するのでシンプル
static const int N = 8;

void __main() {
    int k;
    cin >> k;

    vector<int> Q(N, -1);
    REP(i, k) {
        int r, c; cin >> r >> c;
        Q[r] = c;
    }

    vector<int> a(N);
    REP(i, N) a[i] = i;
    do {
        bool is_fixed = true;
        REP(i, N) {
            if (Q[i] == -1) continue;
            if (a[i] != Q[i]) is_fixed = false;
        }
        if (!is_fixed) continue;

        bool is_ok = true;
        REP(i, N) {
            FOR(j, i+1, N) {
                auto c0 = a[i];
                auto c1 = a[j];
                if (abs(i-j) == abs(c0-c1)) is_ok = false;
            }
        }
        if (is_ok) {
            REP(i, N) {
                REP(j, N) {
                    auto c = '.';
                    if (a[i] == j) c = 'Q';
                    cout << c;
                }
                cout << endl;
            }
            return;
        }

    } while (next_permutation(ALL(a)));

}

int main() {
    __main();
    return 0;
}

