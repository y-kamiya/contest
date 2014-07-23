// BEGIN CUT HERE
// END CUT HERE
#line 4 "BubbleSortWithReversals.cpp"
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<utility>
#include<string>
#include<sstream>
using namespace std;
#define CLR(x,a) memset(x,a,sizeof(x))
#define SZ(x) (int)x.size()
#define FOR(i,m,n) for(i=m;i<(n);i++)
#define INF 1<<20

typedef long long ll;

class BinaryIndexedTree
{
    vector<int> bit;
    int n;

public:
    BinaryIndexedTree(int _n)
    {
        int i;
        this->n = _n;
        FOR (i,0,_n) {
            bit.push_back(0);
        }
    }

    int sum(int i) 
    {
        int s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    void add(int i, int x)
    {
        while (i <= n) {
            bit[i] += x;
            i += i & -i;
        }
    }
}

class BubbleSortWithReversals {
	public:
	int getMinSwaps (vector <int> A, int K) {
        const int N = A.size();
        vector<vector<int> >  dp[N+1];
	
        int i, j;
        FOR (i,0,N+1) FOR (j,0,K+2) dp[i].push_back(INF);
        dp[0][0] = 0;
        BinaryIndexedTree bit(1001);
        FOR (i,0,N) {
            FOR (j,0,K+1) {
                dp[i+1][j] = min(dp[i+1][j], dp[i][j] + bit.sum(1000) - bit.sum(A[i]));
                FOR (k,i,N) {
                    int d = 0;
                    BinaryIndexedTree bit2 = bit;
                    for (int l = k; i <= l; --l) {
                        d += bit2.sum(1000) - bit2.sum(A[i]);
                        bit2.add(A[i], 1);
                    }
                    dp[K+1][j+1] = min(dp[K+1][j+1], dp[i][j] + d);
                }
            }
            bit.add(A[i], 1);
        }
        return *min_element(dp.back().begin(), dp.back().end() - 1);

	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {6,8,8,7,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; verify_case(0, Arg2, getMinSwaps(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {7,2,2,13,5,5,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(1, Arg2, getMinSwaps(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {12,5,1,10,12,6,6,10,6,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 12; verify_case(2, Arg2, getMinSwaps(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2,3,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 1; verify_case(3, Arg2, getMinSwaps(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {482,619,619,601,660,660,691,691,77,77,96,77}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arg2 = 22; verify_case(4, Arg2, getMinSwaps(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BubbleSortWithReversals __test;
	__test.run_test(-1);
}
// END CUT HERE
