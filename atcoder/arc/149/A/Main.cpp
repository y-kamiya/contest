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

vector<pair<ll,ll> > factorize(ll N) {
    vector<pair<ll,ll> > res;
    for (ll a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        ll ex = 0;

        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        res.push_back({a, ex});
    }

    if (N != 1) res.push_back({N, 1});
    return res;
}

vector<int> carry_and_fix(vector<int> digit) {
    int N = digit.size();
    for(int i = 0; i < N - 1; ++i) {
        // 繰り上がり処理 (K は繰り上がりの回数)
        if(digit[i] >= 10) {
            int K = digit[i] / 10;
            digit[i] -= K * 10;
            digit[i + 1] += K;
        }
        // 繰り下がり処理 (K は繰り下がりの回数)
        if(digit[i] < 0) {
            int K = (-digit[i] - 1) / 10 + 1;
            digit[i] += K * 10;
            digit[i + 1] -= K;
        }
    }
    // 一番上の桁が 10 以上なら、桁数を増やすことを繰り返す
    while(digit.back() >= 10) {
        int K = digit.back() / 10;
        digit.back() -= K * 10;
        digit.push_back(K);
    }
    // 1 桁の「0」以外なら、一番上の桁の 0 (リーディング・ゼロ) を消す
    while(digit.size() >= 2 && digit.back() == 0) {
        digit.pop_back();
    }
    return digit;
}

vector<int> subtraction(vector<int> digit_a, vector<int> digit_b) {
    int N = max(digit_a.size(), digit_b.size()); // a と b の大きい方
    vector<int> digit_ans(N); // 長さ N の配列 digit_ans を作る
    for(int i = 0; i < N; ++i) {
        digit_ans[i] = (i < digit_a.size() ? digit_a[i] : 0) - (i < digit_b.size() ? digit_b[i] : 0);
        // digit_ans[i] を digit_a[i] - digit_b[i] にする (範囲外の場合は 0)
    }
    return carry_and_fix(digit_ans); // 2-4 節「繰り上がり計算」の関数です
}

int compare_bigint(vector<int> digit_a, vector<int> digit_b) {
    int NA = digit_a.size(); // A の桁数
    int NB = digit_b.size(); // B の桁数
    if(NA > NB) return +1; // 左が大きい
    if(NA < NB) return -1; // 右が大きい
    for(int i = NA - 1; i >= 0; --i) {
        if(digit_a[i] > digit_b[i]) return +1; // 左が大きい
        if(digit_a[i] < digit_b[i]) return -1; // 右が大きい
    }
    return 0;
}

vector<int> multiplication(vector<int> digit_a, vector<int> digit_b) {
    int NA = digit_a.size(); // A の桁数
    int NB = digit_b.size(); // B の桁数
    vector<int> res(NA + NB - 1);
    for(int i = 0; i < NA; ++i) {
        for(int j = 0; j < NB; ++j) {
            res[i+j] += digit_a[i] * digit_b[j];
            // 答えの i+j の位に digit_a[i] * digit_b[j] を足す
        }
    }
    return carry_and_fix(res);
}

vector<int> division(vector<int> digit_a, vector<int> digit_b) {
    int NA = digit_a.size(), NB = digit_b.size();
    if(NA < NB) return { 0 };
    // ----- ステップ 1. A ÷ B の桁数を求める ----- //
    int D = NA - NB;
    // digit_a_partial : A の上 NB 桁を取り出したもの
    vector<int> digit_a_partial(digit_a.begin() + (NA - NB), digit_a.end());
    if(compare_bigint(digit_a_partial, digit_b) >= 0) {
        // (A の上 NB 桁) が B 以上だったら...？
        D = NA - NB + 1;
    }
    // ----- ステップ 2. A ÷ B を筆算で求める ----- //
    if(D == 0) return { 0 };
    vector<int> remain(digit_a.begin() + (D - 1), digit_a.end());
    vector<int> digit_ans(D);
    for(int i = D - 1; i >= 0; --i) {
        digit_ans[i] = 9;
        for(int j = 1; j <= 9; ++j) {
            vector<int> x = multiplication(digit_b, { j });
            if(compare_bigint(x, remain) == 1) {
                digit_ans[i] = j - 1;
                break;
            }
        }
        vector<int> x_result = multiplication(digit_b, { digit_ans[i] });
        remain = subtraction(remain, x_result);
        if(i >= 1) {
            // 新しく 10^(i-1) の位が降りてくる
            remain.insert(remain.begin(), digit_a[i - 1]);
        }
    }
    return digit_ans;
}

void _main() {
    int N, M;
    cin >> N >> M;

    vector<int> a = {1,1,1,1,1,1,1};
    vector<int> b = {4,6,4,9};
    
    DEBUG(division(a, b));
    /*
    string s = "";
    REP(i, 18) {
        s += "1";
        ll n = stoll(s);
        DEBUG("----- ", n);
        const auto &res = factorize(n);
        for (auto p : res) {
            DEBUG(p.first, p.second);
        }
    }
    */

    ll ans = 0;
    string s = "";
    REP(i, 18) {
        s += "1";
        FOR(j, 1, 10) {
            ll n = stoll(s) * j;
            if (n % M == 0) {
                ans = n;
            }
        }
    }

    cout << ans << endl;

}

int main() {
    _main();
    return 0;
}

