// BEGIN CUT HERE
// PROBLEM STATEMENT
/* Once upon a time, N people sat around a circle. They were numbered 0 through N-1 in counter-clockwise order. Each person was either a honest person or a liar. A honest person always tells the truth, a liar always lies. You asked some of them (possibly all or none) whether the person sitting to the right of them is a liar. You are given their answers in a string answers with N characters. For each i, character i of answers is one of the following:


'L' if person i said that person (i+1) is a liar,
'H' if person i said that person (i+1) is a honest person,
'?' if you didn't ask person i.

(Above, (i+1) is considered modulo N. That is, person N-1 is talking about person 0.)

You are given the string answers. If there is at least one possible combination of honest people and liars that is consistent with answers, return the smallest possible number of liars. Else return -1.

DEFINITION
Class:ConundrumReloaded
Method:minimumLiars
Parameters:string
Returns:int
Method signature:int minimumLiars(string answers)


CONSTRAINTS
-answers will contain between 2 and 50 characters, inclusive.
-Each character in answers will be 'L', 'H' or '?'.


EXAMPLES

0)
"LLH"

Returns: 1

According to the input:

Person 0 says that person 1 is a liar.
Person 1 says that person 2 is a liar.
Person 2 says that person 0 is a honest person.

Clearly, they cannot all be honest, so there is at least one liar. It is possible that person 1 is liar and the other two are honest. Hence, the smallest possible number of liars is one.

(Note that it is also possible that person 1 is honest and the other two are liars.)

1)
"?????"

Returns: 0

Nobody told us anything. It is possible that everybody is honest.

2)
"LHLH?"

Returns: 2

If person #1 and person #2 are liars, then the answers would be "LHLHH". This is consistent with the answers we received.

3)
"??LLLLLL??"

Returns: 3



4)
"LLL"

Returns: -1

Each of the 8 possible combinations of (liar / honest person) will lead to a contradiction.
*/
// END CUT HERE
#line 74 "ConundrumReloaded.cpp"
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
#define FOR(i,n) for(i=0;i<(n);i++)
#define INF 1<<20

typedef long long ll;

class ConundrumReloaded {
	public:

    int dp[52][2];
    int minimumLiars(string answers) {
        int N=answers.size();
        int fa,i,x,ma=100;
        
        FOR(fa,2) {
            FOR(x,N+1) dp[x][0]=dp[x][1]=100;
            dp[0][fa]=0;
            FOR(i,N) {
                if(answers[i]=='L' || answers[i]=='?') {
                    dp[i+1][1]=min(dp[i+1][1],dp[i][0]+1);
                    dp[i+1][0]=min(dp[i+1][0],dp[i][1]);
                }
                if(answers[i]=='H' || answers[i]=='?') {
                    dp[i+1][1]=min(dp[i+1][1],dp[i][1]+1);
                    dp[i+1][0]=min(dp[i+1][0],dp[i][0]);
                }
            }
            ma=min(ma,dp[N][fa]);
        }
        if(ma>=100) return -1;
        return ma;
    }
// BEGIN CUT HERE
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "LLH"; int Arg1 = 1; verify_case(0, Arg1, minimumLiars(Arg0)); }
	void test_case_1() { string Arg0 = "?????"; int Arg1 = 0; verify_case(1, Arg1, minimumLiars(Arg0)); }
	void test_case_2() { string Arg0 = "LHLH?"; int Arg1 = 2; verify_case(2, Arg1, minimumLiars(Arg0)); }
	void test_case_3() { string Arg0 = "??LLLLLL??"; int Arg1 = 3; verify_case(3, Arg1, minimumLiars(Arg0)); }
	void test_case_4() { string Arg0 = "LLL"; int Arg1 = -1; verify_case(4, Arg1, minimumLiars(Arg0)); }

// END CUT HERE
        
};

// BEGIN CUT HERE
int main() {
	ConundrumReloaded __test;
	__test.run_test(-1);
}
// END CUT HERE
