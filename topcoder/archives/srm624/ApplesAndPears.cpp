// BEGIN CUT HERE
/* PROBLEM STATEMENT
// A square board is divided into N rows by N columns of unit square cells.
Some cells of the board are empty.
Each of the other cells contains either an apple or a pear.
You are given the current state of the board as a vector <string> board.
In board, the character '.' denotes an empty cell, 'A' denotes an apple, and 'P' denotes a pear.

You are allowed to perform at most K moves.
In each move, you can pick up one fruit (an apple or a pear) and place it onto any empty cell.
(The new cell doesn't have to be adjacent to the old one.)
Note that you cannot remove fruit from the board, you are only allowed to move it onto different cells.

A rectangular section of the board is called uniform if all cells in the rectangle are the same:
that is, either all those cells contain apples, or they all contain pears, or all of them are empty.
After you are done moving the fruit, you want to have a uniform rectangle that is as large as possible somewhere on the board.
Return the largest possible area of such a rectangle.

DEFINITION
Class:ApplesAndPears
Method:getArea
Parameters:vector <string>, int
Returns:int
Method signature:int getArea(vector <string> board, int K)


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-board will contain exactly N elements.
-Each element of board will contain exactly N characters.
-Each character in board will be '.', 'A', or 'P'.
-K will be between 0 and 1000, inclusive.


EXAMPLES

0)
{".A",
 "P."}
0

Returns: 1

As K=0, you are not allowed to make any moves.
Currently, the largest uniform rectangle is just a single cell.

1)
{".A",
 "P."}
1

Returns: 2

Move any piece of fruit onto any of the two currently empty cells.
After the move, there will be two adjacent empty cells.
These form a 2x1 uniform rectangle.

2)
{".PP", 
 "PPA", 
 "PAP"}
3

Returns: 6

In three moves, you can create a 3x2 rectangle of cells that contain pears.

3)
{"A.P.PAAPPA",
 "PPP..P.PPP",
 "AAP.A.PAPA",
 "P.PA.AAA.A",
 "...PA.P.PA",
 "P..A.A.P..",
 "PAAP..A.A.",
 "PAAPPA.APA",
 ".P.AP.P.AA",
 "..APAPAA.."}
10

Returns: 21


*/
// END CUT HERE
#line 87 "ApplesAndPears.cpp"
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
#define FOR(i,m,n) for(i=(m);i<(n);i++)
#define INF 1<<20

typedef long long ll;

class ApplesAndPears {
	public:
    void countChars (vector<string> board, int count[], int i, int j, int x, int y) {
        int a, b;
        FOR(a,0,3) count[a] = 0;
        FOR(a,x,x+i) {
            FOR(b,y,y+j) {
                if (board[a][b] == 'A') count[0]++;
                else if (board[a][b] == 'P') count[1]++;
                else count[2]++;
            }
        }
    }
	int getArea (vector <string> board, int K) {
        int s, n = SZ(board);
        int all[3];
        int res = 0;
        countChars(board, all, n, n, 0, 0);

        for (int i = n; i >= 1; i--) {
            for (int j = n; j >= 1; j--) {
                int count[3];
                for (int x = 0; x + i - 1 < n; x++) {
                    for (int y = 0; y + j - 1 < n; y++) {
                        countChars(board, count, i, j, x, y);
                        FOR(s,0,3) {
                            int s1 = (s+1)%3, s2 = (s+2)%3;
                            int inner = count[s1] + count[s2];
                            int outer = all[s] - count[s];
                            if (inner > outer) continue;
                            int k = 0;
                            if (s1 == 2) {
                                k = count[s1] + count[s2] * 2;
                            } else if (s2 == 2) {
                                k = count[s2] + count[s1] * 2;
                            } else {
                                k = count[s1] + count[s2];
                            }
                            if (k <= K) {
                                res = max(res, i * j);
                            }
                        }
                    }
                }
            }
        }
        return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".A",
 "P."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; verify_case(0, Arg2, getArea(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {".A",
 "P."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(1, Arg2, getArea(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {".PP", 
 "PPA", 
 "PAP"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 6; verify_case(2, Arg2, getArea(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"A.P.PAAPPA",
 "PPP..P.PPP",
 "AAP.A.PAPA",
 "P.PA.AAA.A",
 "...PA.P.PA",
 "P..A.A.P..",
 "PAAP..A.A.",
 "PAAPPA.APA",
 ".P.AP.P.AA",
 "..APAPAA.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 21; verify_case(3, Arg2, getArea(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ApplesAndPears __test;
	__test.run_test(-1);
}
// END CUT HERE
