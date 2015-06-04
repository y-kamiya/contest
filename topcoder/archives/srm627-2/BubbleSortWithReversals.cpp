// BEGIN CUT HERE
// PROBLEM STATEMENT
/* The pseudocode shown below is an implementation of BubbleSort.
Note that the array A used in the implementation is 0-based.
That is, elements of A have indices 0 through Length(A)-1, inclusive.


BubbleSort(A):
        Repeat Length(A)-1 times:
               For every i from 0 to Length(A)-2, inclusive:
                      If A[i] > A[i+1] then:
                               Swap A[i] and A[i+1]


We are going to sort the array A using the above algorithm.
However, before we do that, you are allowed to reverse at most K disjoint subarrays of A.

For example, suppose that A={10, 20, 30, 40, 50, 60, 70} and that K=1.
In this case you may, for example, reverse the subarray [2,5] - that is, the elements at (0-based) indices 2 through 5.
This would produce the array {10, 20, 60, 50, 40, 30, 70}.

We are interested in minimizing the number of swaps executed by our BubbleSort.
You are given the vector <int> A and the int K.
Return the smallest possible number of swaps performed by our BubbleSort after you reverse at most K disjoint subarrays of A.


DEFINITION
Class:BubbleSortWithReversals
Method:getMinSwaps
Parameters:vector <int>, int
Returns:int
Method signature:int getMinSwaps(vector <int> A, int K)


CONSTRAINTS
-A will contain between 2 and 50 elements.
-K will be between 1 and 50.
-Each element of A will be between 1 and 1000, inclusive.


EXAMPLES

0)
{6,8,8,7,7}
1

Returns: 0

By reversing the subarray [1,4] we obtain a new array {6,7,7,8,8}. This array is already sorted and we can easily verify that our BubbleSort never swaps anything.


1)
{7,2,2,13,5,5,2}
2

Returns: 3



2)
{12,5,1,10,12,6,6,10,6,8}
2

Returns: 12



3)
{2,3,1}
2

Returns: 1

Note that the subarrays we are reversing must all be disjoint. For example, it is not allowed to reverse first the subarray [0,1] and then the subarray [0,2].


4)
{482,619,619,601,660,660,691,691,77,77,96,77}
9

Returns: 22


*/
// END CUT HERE
#line 87 "BubbleSortWithReversals.cpp"
#include<cstdio>
#include<cstdlib>
#include<cstring>
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
#define FOR(i,n) for(i=0;i<(n);i++)
#define INF 1<<20

typedef long long ll;

class BubbleSortWithReversals {
	public:
    int countInversions(const vector<int> &B, int x) {
        int c = 0;
        for (int i = x; i < SZ(B); i++) {
            for (int j = 0; j < i; j++) {
                if (B[j] > B[i]) {
                    c++;
                }
            }
        }
        return c;
    }
	int getMinSwaps (vector <int> A, int K) {
        int dp[51][51];
        int n = SZ(A);

        for (int k = 0; k <= K; k++) {
            dp[n][k] = 0;
        }

        for (int x = n - 1; x >= 0; x--) {
            for (int k = 0; k <= K; k++) {
                vector<int> B(A.begin(), A.begin() + x + 1);
                dp[x][k] = countInversions(B, x) + dp[x+1][k];

                if (k >= 1) {
                    for (int y = x + 1; y < n; y++) {
                        vector<int> B(A.begin(), A.begin() + y + 1);
                        reverse(B.begin() + x, B.begin() + y + 1);
                        dp[x][k] = min(dp[x][k], countInversions(B, x) + dp[y+1][k-1]);
                    }
                }
            }
        }
        return dp[0][K];
	
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
