// BEGIN CUT HERE
// PROBLEM STATEMENT
// In this problem, some test cases have more than one correct output. We are using a special checker to verify that the output of your program is correct.

A positive integer x is called composite if there are positive integers y > 1 and z > 1 such that x = yz.
In other words, a composite positive integer has a positive integer divisor other than 1 and itself.
For example, 48 is composite because 48 = 4*12.
The smallest few composite integers are 4, 6, 8, 9, and 10.

You are given an int n.
Return a vector <int> with two elements.
Both elements of the returned vector <int> must be positive composite integers, and their sum must be n.

For the given constraints on n at least one such pair always exists.
Note that if there are many such pairs, your solution can return any one of them.

DEFINITION
Class:SilverbachConjecture
Method:solve
Parameters:int
Returns:vector <int>
Method signature:vector <int> solve(int n)


CONSTRAINTS
-n will be between 20 and 2000, inclusive.


EXAMPLES

0)
20

Returns: {8, 12 }

For n=20 there are seven correct answers: {4,16}, {6,14}, {8,12}, {10,10}, {12,8}, {14,6}, and {16,4}. Your program must return one of these seven answers.

1)
30

Returns: {15, 15 }

You may return two identical numbers.

2)
999

Returns: {699, 300 }



3)
45

Returns: {15, 30 }



// END CUT HERE
#line 61 "SilverbachConjecture.cpp"
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

string itos(int a) {
    stringstream ss;
    ss << a;
    return ss.str();
}

class SilverbachConjecture {
	public:
	vector <int> solve (int n) {
	
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 20; int Arr1[] = {8, 12 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { int Arg0 = 30; int Arr1[] = {15, 15 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { int Arg0 = 999; int Arr1[] = {699, 300 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { int Arg0 = 45; int Arr1[] = {15, 30 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, solve(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SilverbachConjecture __test;
	__test.run_test(-1);
}
// END CUT HERE
