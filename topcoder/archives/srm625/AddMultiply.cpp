// BEGIN CUT HERE
// PROBLEM STATEMENT
/* You are given an int y.
We are looking for any vector <int> x that satisfies the following constraints:

x has exactly three elements
( x[0] * x[1] ) + x[2] = y
Each x[i] must be between -1000 and 1000, inclusive.
No x[i] can be equal to 0 or 1.

Find and return one such x.

If there are multiple valid solutions, you may return any of them.
You may assume that for our constraints on y (specified below) at least one valid x always exists.

DEFINITION
Class:AddMultiply
Method:makeExpression
Parameters:int
Returns:vector <int>
Method signature:vector <int> makeExpression(int y)


CONSTRAINTS
-y will be between 0 and 500, inclusive.


EXAMPLES

0)
6

Returns: {2, 2, 2 }

2*2 + 2 = 6

Note that this is one of many possible solutions. Another solution is:

3*3 + (-3) = 6


1)
11

Returns: {2, 3, 5 }



2)
0

Returns: {7, 10, -70 }

Note that 0 and 1 are not allowed, thus a result like 0 * 0 + 0 would be incorrect.

3)
500

Returns: {-400, -3, -700 }

Some or all of the returned numbers may be negative.

4)
2

Returns: {2, 2, -2 }



5)
5

Returns: {5, 2, -5 }


*/
// END CUT HERE
#line 79 "AddMultiply.cpp"
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

#define X_MIN -1000
#define X_MAX 1000


class AddMultiply {
	public:
	vector <int> makeExpression (int y) {
        vector<int> res;
        for (int i = X_MIN; i <= X_MAX; i++) {
            if (i == 0 || i == 1) continue;
            for (int j = X_MIN; j <= X_MAX; j++) {
                if (j == 0 || j == 1) continue;
                int a = (y - i) / j;
                if ((y - i) % j == 0 && X_MIN <= a && a <= X_MAX) {
                    res.push_back((y - i) / j);
                    res.push_back(j);
                    res.push_back(i);
                    return res;
                }
            }
        }
        return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 6; int Arr1[] = {2, 2, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, makeExpression(Arg0)); }
	void test_case_1() { int Arg0 = 11; int Arr1[] = {2, 3, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, makeExpression(Arg0)); }
	void test_case_2() { int Arg0 = 0; int Arr1[] = {7, 10, -70 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, makeExpression(Arg0)); }
	void test_case_3() { int Arg0 = 500; int Arr1[] = {-400, -3, -700 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, makeExpression(Arg0)); }
	void test_case_4() { int Arg0 = 2; int Arr1[] = {2, 2, -2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, makeExpression(Arg0)); }
	void test_case_5() { int Arg0 = 5; int Arr1[] = {5, 2, -5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, makeExpression(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AddMultiply __test;
	__test.run_test(-1);
}
// END CUT HERE
