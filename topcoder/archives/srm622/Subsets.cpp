// BEGIN CUT HERE
/* PROBLEM STATEMENT
// You have a bag with some balls.
There is a positive integer written on each of the balls.
Balls with the same integer are identical.

A bag with balls is nice if the sum of numbers on all balls is strictly greater than the product of those numbers.
For example, if the numbers on balls are {1,1,2,3}, the bag is nice because 1+1+2+3 > 1*1*2*3.

You are given a vector <int> numbers.
Each element of numbers is a number written on one of the balls in your bag.
You are going to remove some (possibly none, but not all) balls from the bag.
After you do so, the bag must be nice.

Return the number of different nice bags you can obtain.

DEFINITION
Class:Subsets
Method:findSubset
Parameters:vector <int>
Returns:int
Method signature:int findSubset(vector <int> numbers)


NOTES
-You may assume that the return value always fits into a signed 32-bit integer variable.


CONSTRAINTS
-numbers will contain between 1 and 1000 elements, inclusive.
-Each element of numbers will be between 1 and 1000, inclusive.


EXAMPLES

0)
{1,1,1}

Returns: 2

The bag contains three identical balls, each with the number 1.
We can produce a nice bag in two ways:

Keep all three balls. The bag is nice because 1+1+1 > 1*1*1.
Throw away one ball. The bag is nice because 1+1 > 1*1.


1)
{1,1,1,1,2,2,2,2}

Returns: 13

Our bag contains 8 balls: four with a 1 and four with a 2.
All possible nice bags that can be produced by removing some of these balls are listed below, one per row.

1,1
1,1,1
1,1,1,1
1,2
1,1,2
1,1,1,2
1,1,1,1,2
1,2,2
1,1,2,2
1,1,1,2,2
1,1,1,1,2,2
1,1,1,2,2,2
1,1,1,1,2,2,2

2)
{1,2,3,4}

Returns: 3



3)
{1,1,1,1,1,1,1,1,1,1,1,1,1,10,20,30,40,50}

Returns: 77



4)
{1,1,1,1,1,1,1,1,1,1,1,2,3,4,2,2,2}

Returns: 100



5)
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,2,2,2,3,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22}

Returns: 8050



6)
{5,3}

Returns: 0


*/
// END CUT HERE
#line 109 "Subsets.cpp"
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

class Subsets {
	public:
	int findSubset (vector <int> numbers) {
        int i, c1 = 0;
        int n = SZ(numbers);
        vector<int> nums;
        sort(numbers.begin(), numbers.end());
        FOR(i,n) {
            if (numbers[i] == 1) c1++;
            else nums.push_back(numbers[i]);
        }
        if (c1 == 0) return 0;

        int m = SZ(nums), res = 0;
        bool used[1001];
        CLR(used, false);
        FOR(i,m) {
            if (used[nums[i]]) continue;
            cout << nums[i] << endl;
            used[nums[i]] = true;
            for (int j = i; j < m; j++) {
                int sum = 0, pro = 1;
                for (int k = i; k <= j; k++) {
                    sum += nums[k];
                    pro *= nums[k];
                }
                int sub = pro - sum;
                if (c1 > sub) res += c1 - sub;
                else break;
            }
        }
        return res + c1 - 1;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, findSubset(Arg0)); }
	void test_case_1() { int Arr0[] = {1,1,1,1,2,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(1, Arg1, findSubset(Arg0)); }
	void test_case_2() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, findSubset(Arg0)); }
	void test_case_3() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,10,20,30,40,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 77; verify_case(3, Arg1, findSubset(Arg0)); }
	void test_case_4() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,2,3,4,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; verify_case(4, Arg1, findSubset(Arg0)); }
	void test_case_5() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,2,2,2,3,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8050; verify_case(5, Arg1, findSubset(Arg0)); }
	void test_case_6() { int Arr0[] = {5,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(6, Arg1, findSubset(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Subsets __test;
	__test.run_test(-1);
}
// END CUT HERE
