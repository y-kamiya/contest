// BEGIN CUT HERE
/* PROBLEM STATEMENT
// 
Shiny wants to give an award to one of the employees in her company.
However, all her employees are doing perfect work, so it's hard to pick the one that gets the award.
Therefore Shiny organized a game they will play to determine the winner.

At the beginning of the game, all N employees form a circle.
Then, they receive t-shirts with numbers 1 through N in clockwise order along the circle.
These numbers are never used in the game, we will just use them to identify the winner.

The game is played in turns.
The turns are numbered starting from 1.
In each turn, Shiny starts by standing in front of some employee (as specified below) and saying "one".
Then she moves clockwise along the circle to the next employee and says "two".
And so on, until the number she says reaches the threshold for that particular turn.
The threshold for turn number t is t^3.
(That is, the threshold is 1 for turn 1, 8 for turn 2, 27 for turn 3, and so on.)

At the end of each turn, the employee currently standing in front of Shiny (i.e., the one that received the number t^3) is eliminated.
In the very first round Shiny starts in front of the employee with the number 1 on their t-shirt.
In each of the following rounds, Shiny starts in front of the next employee clockwise from the one who just got eliminated.

When there is only one employee left in the game, the game ends and the employee wins the award.

You are given the int N.
Return the t-shirt number of the employee who gets the award.


DEFINITION
Class:ChooseTheBestOne
Method:countNumber
Parameters:int
Returns:int
Method signature:int countNumber(int N)


CONSTRAINTS
-N will between 1 and 5000, inclusive.


EXAMPLES

0)
3

Returns: 2

In the first round, Shiny stands in front of employee 1, says "one" and eliminates him.
In the second round, Shiny starts in front of employee 2. She says "one" to employee 2, "two" to
employee 3, "three" to employee 2 again, ..., and "eight" to employee 3. Thus, employee 3 
gets eliminated and employee 2 wins the award.


1)
6

Returns: 6



2)
10

Returns: 8



3)
1234

Returns: 341


*/
// END CUT HERE
#line 78 "ChooseTheBestOne.cpp"
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
#define SZ(x) (int)x.size()
#define FOR(i,n) for(i=0;i<(n);i++)

class ChooseTheBestOne {
	public:
	int countNumber (int N) {
        int i, sz, t = 1;
        vector<int> employees;
        FOR(i,N) {
            employees.push_back(i+1);
        }
        vector<int>::iterator it = employees.begin();
        while (true) {
            sz = SZ(employees);
            if (sz == 1) break;
            int a = (t * t * t -1) % sz;
            FOR(i,a) {
                if (it+1 == employees.end()) {
                    it = employees.begin();
                } else {
                    it++;
                }
            }
            it = employees.erase(it);
            if (it == employees.end()) {
                it = employees.begin();
            }
            t++;
        }
        return employees[0];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; verify_case(0, Arg1, countNumber(Arg0)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 6; verify_case(1, Arg1, countNumber(Arg0)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 8; verify_case(2, Arg1, countNumber(Arg0)); }
	void test_case_3() { int Arg0 = 1234; int Arg1 = 341; verify_case(3, Arg1, countNumber(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ChooseTheBestOne __test;
	__test.run_test(-1);
}
// END CUT HERE
