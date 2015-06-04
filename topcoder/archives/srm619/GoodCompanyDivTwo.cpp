// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
Shiny has a company.
There are N employees in her company.
The employees are numbered 0 through N-1 in order in which they joined the company.



Employee 0 is the only employee with no boss.
Every other employee has precisely one direct boss in the company.
You are given a vector <int> superior with N elements.
Element 0 of superior will be -1 to denote that employee 0 has no boss.
For each i between 1 and N-1, inclusive, element i of superior will be the number of the boss of employee i.



For each employee, their boss joined the company before them.
Formally, for each i between 1 and N-1, inclusive, superior[i] will be between 0 and i-1, inclusive.



Each employee only does one type of work.
You are given a vector <int> workType with N elements.
(Different integers represent different types of work.)



Each employee of the company has their own department.
The department of employee x is formed by employee x and all the employees such that x is their boss.
Formally, for any y different from x, employee y belongs into the department of employee x if and only if superior[y]=x.
Note that if superior[z]=y and superior[y]=x, employee z does not belong into the department of employee x.



A department is called diverse if no two employees in the department do the same type of work.
Compute and return the number of diverse departments in Shiny's company.


DEFINITION
Class:GoodCompanyDivTwo
Method:countGood
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int countGood(vector <int> superior, vector <int> workType)


CONSTRAINTS
-superior will contain between 1 and 100 elements, inclusive.
-workType will contain the same number of elements as superior.
-Each element of workType will be between 1 and 100, inclusive.
-superior[0] will be -1.
-For each valid i>0, superior[i] will be between 0 and i-1, inclusive.


EXAMPLES

0)
{-1, 0}
{1, 2}

Returns: 2

The department of employee 0 contains employees 0 and 1.
The department of employee 1 contains employee 1 only.
Both departments are diverse.

1)
{-1, 0}
{1, 1}

Returns: 1

The departments are the same as in Example 0.
However, now the department of employee 0 is not diverse: it contains two employees who do the same type of work.
Only the department of employee 1 is now diverse.

2)
{-1, 0, 1, 1}
{1, 4, 3, 2}

Returns: 4

Note that in this test case the department of employee 0 contains only employees 0 and 1. Employees 2 and 3 do not belong into the department of employee 0.

3)
{-1, 0, 1, 0, 0}
{3, 3, 5, 2, 2}

Returns: 4



4)
{-1, 0, 1, 1, 1, 0, 2, 5}
{1, 1, 2, 3, 4, 5, 3, 3}

Returns: 7



5)
{-1, 0, 0, 1, 1, 3, 0, 2, 0, 5, 2, 5, 5, 6, 1, 2, 11, 12, 10, 4, 7, 16, 10, 9, 12, 18, 15, 23, 20, 7, 4}
{4, 6, 4, 7, 7, 1, 2, 8, 1, 7, 2, 4, 2, 9, 11, 1, 10, 11, 4, 6, 11, 7, 2, 8, 9, 9, 10, 10, 9, 8, 8}

Returns: 27



// END CUT HERE
#line 112 "GoodCompanyDivTwo.cpp"
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

class GoodCompanyDivTwo {
	public:
	int countGood (vector <int> superior, vector <int> workType) {
	
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-1, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, countGood(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {-1, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, countGood(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-1, 0, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 4, 3, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(2, Arg2, countGood(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {-1, 0, 1, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 3, 5, 2, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(3, Arg2, countGood(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {-1, 0, 1, 1, 1, 0, 2, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 2, 3, 4, 5, 3, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(4, Arg2, countGood(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {-1, 0, 0, 1, 1, 3, 0, 2, 0, 5, 2, 5, 5, 6, 1, 2, 11, 12, 10, 4, 7, 16, 10, 9, 12, 18, 15, 23, 20, 7, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 6, 4, 7, 7, 1, 2, 8, 1, 7, 2, 4, 2, 9, 11, 1, 10, 11, 4, 6, 11, 7, 2, 8, 9, 9, 10, 10, 9, 8, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 27; verify_case(5, Arg2, countGood(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GoodCompanyDivTwo __test;
	__test.run_test(-1);
}
// END CUT HERE
