// BEGIN CUT HERE
// PROBLEM STATEMENT
// You have a long thin cake. For simplicity, we can consider the cake to be one-dimensional. The length of the cake is n. 

You are expecting some friends. You are going to cut the cake into multiple pieces before the friends arrive.

When the friends arrive, you will divide the cake among them, using the following procedure: starting at the beginning of the cake, you will first give some consecutive pieces to your first friend, then some consecutive pieces to your second friend, and so on.

Of course, you want to be fair. That is, each of your friends should receive the same total amount of cake. (The number of pieces may be different for different friends, but the sum of their lengths must be the same.)

As we stated above, you want to cut the cake before your friends arrive. However, you don't know how many friends will actually come. You only know that their count will be a divisor of n smaller than n.

You are given the int n. You want to cut the cake in such a way that for each valid number of friends it will be possible to give each of them the same amount of cake when using the above procedure. Return the smallest possible number of pieces after you cut the cake.

DEFINITION
Class:MyVeryLongCake
Method:cut
Parameters:int
Returns:int
Method signature:int cut(int n)


CONSTRAINTS
-n will be between 2 and 1,000,000,000, inclusive.


EXAMPLES

0)
6

Returns: 4

The best possible solution is to cut the cake into 4 pieces. Let's call the pieces A, B, C, and D, in order. Their lengths will be 2, 1, 1, and 2.

As n=6, there will be 1, 2, or 3 friends. If there is just one friend, she gets all four pieces. If there are two friends, the first gets A+B and the second gets C+D. If there are three friends, the first gets A, the second gets B+C, and the third gets D.

Note that the order of parts matters. For example, dividing the cake into parts of length 2, 1, 2, and 1 is not a valid solution.

1)
3

Returns: 1

In this case, the only possible number of friends that will come to your house is 1. Hence, you don't even need to cut the cake, simply leave it in one piece.

2)
15

Returns: 7

You are expecting 1, 3, or 5 friends.

3)
1000000000

Returns: 600000000



4)
577007436

Returns: 384671628



// END CUT HERE
#line 70 "MyVeryLongCake.cpp"
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

class MyVeryLongCake {
	public:
	int cut (int n) {
	
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 4; verify_case(0, Arg1, cut(Arg0)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; verify_case(1, Arg1, cut(Arg0)); }
	void test_case_2() { int Arg0 = 15; int Arg1 = 7; verify_case(2, Arg1, cut(Arg0)); }
	void test_case_3() { int Arg0 = 1000000000; int Arg1 = 600000000; verify_case(3, Arg1, cut(Arg0)); }
	void test_case_4() { int Arg0 = 577007436; int Arg1 = 384671628; verify_case(4, Arg1, cut(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MyVeryLongCake __test;
	__test.run_test(-1);
}
// END CUT HERE
