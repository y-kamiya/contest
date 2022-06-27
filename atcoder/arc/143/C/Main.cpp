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

void Nimk(int N, int K, vector<int>& pile) {
	vector< vector<int> > bin(N, vector<int>(30, 0)); // 2次元配列

	for (int i = 0; i < N; i++) { //pile[i]について、2進数に展開する
		int twopow = 1; // 2のべき乗
		for (int x = 0; x < 30; x++) {
			if (twopow & pile[i])// 2^xにくっつく数は0か1か
				bin[i][x] = 1;
			else
				bin[i][x] = 0;
			twopow = twopow * 2;
		}
	}

	vector<int> digitsum(N, 0); // 桁ごとの和

	for (int x = 0; x < 30; x++) {// 桁xについて
		for (int i = 0; i < N; i++) {
			digitsum[x] = digitsum[x] + bin[i][x];
		}
	}

	int win = 0; // 負けを0、勝ちを1とする
	for (int x = 0; x < 30; x++) {
		if (digitsum[x] % (K + 1) != 0) {
			// 桁の値が0ではないときは勝ちのポジション、grundy数が0でないことが確定する
			win = 1;
		}
	}

	if (win == 1) { // 先手の勝ち
		cout << "First" << endl;
	}
	else { // 先手の負け
		cout << "Second" << endl;
	}

}

void _main() {
    int N, X, Y;
    cin >> N >> X >> Y;

    vector<int> A(N);
    REP(i, N) cin >> A[i];

    Nimk(N, 1, A);
}

int main() {
    _main();
    return 0;
}

