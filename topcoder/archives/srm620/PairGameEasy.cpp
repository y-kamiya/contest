// BEGIN CUT HERE
/* PROBLEM STATEMENT
// You have an ordered pair of integers.
You can now make zero or more steps.
In each step, you can change your pair into a new pair of integers by adding one of them to the other.
That is, if your current pair is (x, y), then your next pair will be either (x+y, y), or (x, x+y).



For example, you can start with (1, 2), change it to (3, 2), change that to (3, 5), and then change that again to (3, 8).



You are given four ints: a, b, c, and d.
Return "Able to generate" (quotes for clarity) if it is possible to start with the pair (a, b) and end with the pair (c, d).
Otherwise, return "Not able to generate".

DEFINITION
Class:PairGameEasy
Method:able
Parameters:int, int, int, int
Returns:string
Method signature:string able(int a, int b, int c, int d)


CONSTRAINTS
-a will be between 1 and 1,000, inclusive.
-b will be between 1 and 1,000, inclusive.
-c will be between 1 and 1,000, inclusive.
-d will be between 1 and 1,000, inclusive.


EXAMPLES

0)
1
2
3
5

Returns: "Able to generate"

(1, 2) -> (3, 2) -> (3, 5).

1)
1
2
2
1

Returns: "Not able to generate"

Note that order matters: (1, 2) and (2, 1) are two different pairs.

2)
2
2
2
999

Returns: "Not able to generate"



3)
2
2
2
1000

Returns: "Able to generate"



4)
47
58
384
221

Returns: "Able to generate"



5)
1000
1000
1000
1000

Returns: "Able to generate"


*/
// END CUT HERE
#line 97 "PairGameEasy.cpp"
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
class PairGameEasy {
	public:
    bool dfs(int a, int b, int c, int d) {
        if (a > c || b > d) return false;
        if (a == c && b == d) return true;
        if (dfs(a+b, b, c, d)) return true;
        if (dfs(a, a+b, c, d)) return true;
        return false;
    }

	string able (int a, int b, int c, int d) {
        if (dfs(a,b,c,d)) {
            return "Able to generate";
        } else {
            return "Not able to generate";
        }
	
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 3; int Arg3 = 5; string Arg4 = "Able to generate"; verify_case(0, Arg4, able(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 2; int Arg3 = 1; string Arg4 = "Not able to generate"; verify_case(1, Arg4, able(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 999; string Arg4 = "Not able to generate"; verify_case(2, Arg4, able(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 1000; string Arg4 = "Able to generate"; verify_case(3, Arg4, able(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 47; int Arg1 = 58; int Arg2 = 384; int Arg3 = 221; string Arg4 = "Able to generate"; verify_case(4, Arg4, able(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 1000; int Arg1 = 1000; int Arg2 = 1000; int Arg3 = 1000; string Arg4 = "Able to generate"; verify_case(5, Arg4, able(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PairGameEasy __test;
	__test.run_test(-1);
}
// END CUT HERE
