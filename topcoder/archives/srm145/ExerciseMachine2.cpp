// BEGIN CUT HERE
// PROBLEM STATEMENT
/* 
You are writing firmware for an exercise machine.  Each second, a routine in your firmware is called which decides whether it should display the percentage of the workout completed.  The display does not have any ability to show decimal points, so the routine should only display a percentage if the second it is called results in a whole percentage of the total workout.



Given a string time representing how long the workout lasts, in the format "hours:minutes:seconds", return the number of times a percentage will be displayed by the routine.  The machine should never display 0% or 100%.


DEFINITION
Class:ExerciseMachine
Method:getPercentages
Parameters:string
Returns:int
Method signature:int getPercentages(string time)


CONSTRAINTS
-time will be a string formatted as "HH:MM:SS", HH = hours, MM = minutes, SS = seconds.
-The hours portion of time will be an integer with exactly two digits, with a value between 00 and 23, inclusive.
-The minutes portion of time will be an integer with exactly two digits, with a value between 00 and 59, inclusive.
-The seconds portion of time will be an integer with exactly two digits, with a value between 00 and 59, inclusive
-time will not be "00:00:00".


EXAMPLES

0)
"00:30:00"

Returns: 99

The standard 30 minute workout.  Each one percent increment can be displayed every 18 seconds.

1)
"00:28:00"

Returns: 19

The 28 minute workout.  The user completes 5 percent of the workout every 1 minute, 24 seconds.

2)
"23:59:59"

Returns: 0

This is the longest workout possible, given the constraints.  No percentages are ever displayed on the screen.

3)
"00:14:10"

Returns: 49

4)
"00:19:16"

Returns: 3

*/
// END CUT HERE
#line 62 "ExerciseMachine.cpp"
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

// BEGIN CUT HERE
#define CLR(x,a) memset(x,a,sizeof(x))
#define SZ(x) (int)x.size()
#define REP(i,n) for(i=0;i<(n);i++)
#define INF 1<<20

typedef long long ll;
// END CUT HERE

class ExerciseMachine {
	public:
	int getPercentages (string time) {
        string hour = time.substr(0,2);
        string min = time.substr(3,2);
        string sec = time.substr(6,2);
        int h = 0, m = 0, s = 0;
        sscanf(hour.c_str(), "%d", &h);
        sscanf(min.c_str(), "%d", &m);
        sscanf(sec.c_str(), "%d", &s);
        int total = h * 3600 + m * 60 + s;
        double one = (double)total / 100;

        int c = 0;
        for (int i = 1; i <= 99; i++) {
            double t = one * i;
            cout << t << "   " << floor(t) << "  " << ceil(t) << endl;
            if (floor(t) == ceil(t)) {
                c++;
            } 
        }

        return c;
	
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5();}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "00:30:00"; int Arg1 = 99; verify_case(0, Arg1, getPercentages(Arg0)); }
	void test_case_1() { string Arg0 = "00:28:00"; int Arg1 = 19; verify_case(1, Arg1, getPercentages(Arg0)); }
	void test_case_2() { string Arg0 = "23:59:59"; int Arg1 = 0; verify_case(2, Arg1, getPercentages(Arg0)); }
	void test_case_3() { string Arg0 = "00:14:10"; int Arg1 = 49; verify_case(3, Arg1, getPercentages(Arg0)); }
	void test_case_4() { string Arg0 = "00:19:16"; int Arg1 = 3; verify_case(4, Arg1, getPercentages(Arg0)); }
	void test_case_5() { string Arg0 = "16:37:22"; int Arg1 = 1; verify_case(5, Arg1, getPercentages(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ExerciseMachine __test;
	__test.run_test(-1);
}
// END CUT HERE
