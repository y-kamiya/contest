// BEGIN CUT HERE
// PROBLEM STATEMENT
/* Rijél is a very wise teacher. He loves mathematics, especially games and geometry problems. Recently one of his students challenged him to the following game:

Initially, there is a polygon with N vertices drawn in the plane. The polygon is strictly convex, i.e., each internal angle is strictly smaller than 180 degrees. The vertices of the polygon are numbered 1 through N, in clockwise order.

Two players play the game on this polygon. The players take alternating turns. In each turn, the current player chooses a diagonal or a side of the polygon and draws it as a straight line segment. (A diagonal of the polygon is a line segment that connects any two non-adjacent vertices of the polygon.) The player is only allowed to choose a diagonal or a side that does not intersect any of the previously drawn segments (it must not share endpoints with any of them either). The player who cannot draw a diagonal or a side according to the above rules loses the game.

You are given the int N.

We assume that both players play the game optimally. Return 1 if the first player wins and 2 otherwise.

DEFINITION
Class:GameOfSegments
Method:winner
Parameters:int
Returns:int
Method signature:int winner(int N)


CONSTRAINTS
-N will be between 3 and 1,000, inclusive.


EXAMPLES

0)
3

Returns: 1

This polygon has zero diagonals and three sides. The first player will always win no matter which side he picks.

1)
4

Returns: 1

This polygon has four sides and two diagonals. The first player wins the game if he takes one of the diagonals, because he will leave no choice for the second player.

2)
15

Returns: 2



3)
191

Returns: 2


*/
// END CUT HERE
#line 57 "GameOfSegments.cpp"
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

int dp[1001];

class GameOfSegments {
	public:
	int winner (int N) {
        dp[0] = dp[1] = 0;
        int tmp[1001];
        for (int i = 2; i <= N; i++) {
            CLR(tmp,0);
            for (int j = 0; j <= (i-2) / 2; j++) {
                int g = dp[j] ^ dp[i - 2 - j];
                tmp[g]++;
            }
            while (tmp[dp[i]]) dp[i]++;
        }
        return dp[N] ? 1 : 2;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; verify_case(0, Arg1, winner(Arg0)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 1; verify_case(1, Arg1, winner(Arg0)); }
	void test_case_2() { int Arg0 = 15; int Arg1 = 2; verify_case(2, Arg1, winner(Arg0)); }
	void test_case_3() { int Arg0 = 191; int Arg1 = 2; verify_case(3, Arg1, winner(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GameOfSegments __test;
	__test.run_test(-1);
}
// END CUT HERE
