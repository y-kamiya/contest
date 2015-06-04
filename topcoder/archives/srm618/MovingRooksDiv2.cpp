// BEGIN CUT HERE
// PROBLEM STATEMENT
// This problem is about chessboards with rooks.
A rook is a chess piece that moves arbitrarily far, either horizontally or vertically.
Both rows and columns of chessboards in our problem are numbered starting from 0.

An n times n chessboard is called peaceful if it contains exactly n rooks and no two rooks attack each other.
In other words, there cannot be two rooks in the same row or in the same column of the chessboard.
A peaceful chessboard can be described by a vector <int> Y with n elements: for each row r, the rook in row r is in column Y[r].

You are given two vector <int>s Y1 and Y2 with n elements each.
Each of them represents one peaceful chessboard.

You want to change the first chessboard into the second one.
There is only one type of moves you are allowed to make:
On the first chessboard, you can choose two rooks in positions (r1,c1) and (r2,c2) such that r1 < r2 and c1 > c2, and move them to (r1,c2) and (r2,c1).
Note that the new chessboard is peaceful again.

Return "Possible" (quotes for clarity) if it is possible to change the first chessboard into the second one. Otherwise, return "Impossible".

DEFINITION
Class:MovingRooksDiv2
Method:move
Parameters:vector <int>, vector <int>
Returns:string
Method signature:string move(vector <int> Y1, vector <int> Y2)


CONSTRAINTS
-Y1 will contain between 1 and 8 elements, inclusive.
-Y2 will contain the same number of elements as Y1.
-Each element of Y1 will be between 0 and n-1, inclusive, where n is the number of elements of Y1.
-Each element of Y2 will be between 0 and n-1, inclusive, where n is the number of elements of Y2.
-All elements of Y1 will be distinct.
-All elements of Y2 will be distinct.


EXAMPLES

0)
{0}
{0}

Returns: "Possible"

Both boards are already equal, we don't even have to make any moves.

1)
{1,0}
{0,1}

Returns: "Possible"

Initially, the rooks on the first chessboard are on the cells (0,1) and (1,0).
There is one valid move: moving these two rooks to (0,0) and (1,1).
After this move, the first chessboard is identical to the second one.

2)
{0,1}
{1,0}

Returns: "Impossible"

There are no valid moves so there's no way to reach the goal.

3)
{3,1,2,0}
{0,2,1,3}

Returns: "Possible"



4)
{3,1,2,0}
{3,2,0,1}

Returns: "Impossible"



// END CUT HERE
#line 84 "MovingRooksDiv2.cpp"
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

class MovingRooksDiv2 {
	public:
	string move (vector <int> Y1, vector <int> Y2) {
	
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(0, Arg2, move(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(1, Arg2, move(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Impossible"; verify_case(2, Arg2, move(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {3,1,2,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,2,1,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(3, Arg2, move(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {3,1,2,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,2,0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Impossible"; verify_case(4, Arg2, move(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MovingRooksDiv2 __test;
	__test.run_test(-1);
}
// END CUT HERE
