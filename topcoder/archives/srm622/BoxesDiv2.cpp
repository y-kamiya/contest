// BEGIN CUT HERE
/* PROBLEM STATEMENT
// Today is Fox Ciel's birthday.
You want to give her a box of candies as a present.

You have candies of several different types.
You are given a vector <int> candyCounts.
Each element of candyCounts is the number of candies of one particular type.

For each non-negative integer i, you have an unlimited supply of boxes with volume 2^i.
That is, you have boxes with volume 1, 2, 4, 8, and so on.

You are going to pack the candies into boxes.
Each type of candies has to be packed into a single box, and you have to use different boxes for different types of candy.
The volume of a box must be greater than or equal to the number of candies it contains.

Once you have each type of candies in a box, you want to pack those boxes into larger boxes, until only one box remains.
You can only pack two boxes at a time.
That is, you can take any two boxes you currently have, get a new box, and put the two old boxes into the new box.
This is possible if and only if the volume of the new box is greater than or equal to the sum of volumes of the two old boxes.
You always get to choose which two boxes you want to pack together, and how large the new box should be.

To summarize:

First, you will pack all the candies into boxes.
Then, you will pack all those boxes into larger boxes, until you are left with a single box that contains everything.


Compute and return the smallest possible volume of the box obtained at the end of packing.


DEFINITION
Class:BoxesDiv2
Method:findSize
Parameters:vector <int>
Returns:int
Method signature:int findSize(vector <int> candyCounts)


NOTES
-You may assume that the return value always fits into a signed 32-bit integer variable.


CONSTRAINTS
-candyCounts will contain between 1 and 100 elements, inclusive.
-Each element of candyCounts will be between 1 and 1000, inclusive.


EXAMPLES

0)
{8,8}

Returns: 16

First, you pack each type of candies into a box with volume 8. Then, you pack the two boxes into a single box with volume 16.

1)
{5,6}

Returns: 16

Even though you have fewer candies than in Example 0, you still have to use boxes with volume 8 (or more) to store them.

2)
{1,7}

Returns: 16

Now you could pack the 1 candy into a smaller box, but it will not help: you still have to use a box with volume 16 to store the two boxes with candies.

3)
{1,1,13,1,1}

Returns: 32



4)
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32}

Returns: 1024


*/
// END CUT HERE
#line 88 "BoxesDiv2.cpp"
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


class BoxesDiv2 {
	public:
    int box (int num) {
        int y = 1;
        while (true) {
            if (num <= y) return y;
            y *= 2;
        }
    }
	int findSize (vector <int> candyCounts) {
        int i, n = SZ(candyCounts), sum = 0;
        vector<int> volumes;
        FOR(i,n) {
            sum += box(candyCounts[i]);
        }
        return box(sum);
	
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {8,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(0, Arg1, findSize(Arg0)); }
	void test_case_1() { int Arr0[] = {5,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(1, Arg1, findSize(Arg0)); }
	void test_case_2() { int Arr0[] = {1,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(2, Arg1, findSize(Arg0)); }
	void test_case_3() { int Arr0[] = {1,1,13,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 32; verify_case(3, Arg1, findSize(Arg0)); }
	void test_case_4() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1024; verify_case(4, Arg1, findSize(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BoxesDiv2 __test;
	__test.run_test(-1);
}
// END CUT HERE
