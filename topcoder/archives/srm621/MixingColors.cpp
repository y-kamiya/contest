// BEGIN CUT HERE
/* PROBLEM STATEMENT
// 
	Danica is an artist. She would like to paint a picture, but currently she has no colors at all.



	For the purpose of this problem, colors are represented by positive integers. You are given a vector <int> colors. The elements of colors are the colors Danica needs to paint her picture.



	There is a store that sells colors. The store has an unlimited supply of all possible colors, including colors that Danica doesn't need. Danica will buy some colors in the store. Then, she will produce other colors by mixing the colors she bought.



	Danica can only mix two colors at a time. Mixing two different colors A and B produces the color (A XOR B). Colors obtained by mixing can later be used to produce other colors.



	Danica wants to buy as few distinct colors as possible. Note that she is allowed to buy colors she does not need for the picture.



	Return the smallest number of distinct colors Danica has to buy in order to be able to obtain all the colors she needs.


DEFINITION
Class:MixingColors
Method:minColors
Parameters:vector <int>
Returns:int
Method signature:int minColors(vector <int> colors)


NOTES
-XOR (exclusive or) is a binary operation, performed on two numbers in binary notation. First, the shorter number is prepended with leading zeroes until both numbers have the same number of digits (in binary). Then, the result is calculated as follows: for each bit where the numbers differ the result has 1 in its binary representation. It has 0 in all other positions.
-For example 15 XOR 55 is performed as follows. First, the numbers are converted to binary: 15 is 1111 and 55 is 110111. Then the shorter number is prepended with leading zeros until both numbers have the same number of digits. This means 15 becomes 001111. Then 001111 XOR 110111 = 111000 (the result has ones only in the positions where the two numbers differ). Then the result can be converted back to decimal notation. In this case 111000 = 56, so 15 XOR 55 = 56.


CONSTRAINTS
-colors will contain between 1 and 50 elements, inclusive.
-Each element of colors will be between 1 and 1,000,000,000, inclusive.
-All elements of colors will be distinct.


EXAMPLES

0)
{1, 7, 3}

Returns: 3

Obviously, Danica can just buy the three colors she needs. However, there are also other optimal solutions. For example, she could buy colors 1, 2, and 4 instead. Then, she can mix these colors as follows:

She already has color 1.
She can obtain color 3 by mixing colors 1 and 2: we have 1 XOR 2 = 3.
She can obtain color 7 by first mixing colors 1 and 4 to produce color 5 (as 1 XOR 4 = 5), and then mixing colors 5 and 2 (as 5 XOR 2 = 7).


1)
{10}

Returns: 1

Danica should buy color 10 only.

2)
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}

Returns: 4

Danica can, for instance, buy colors 11, 13, 14, and 15.

3)
{534, 251, 76, 468, 909, 410, 264, 387, 102, 982, 199, 111, 659, 386, 151}

Returns: 10



4)
{4, 8, 16, 32, 64, 128, 256, 512, 1024}

Returns: 9


*/
// END CUT HERE
#line 90 "MixingColors.cpp"
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

class MixingColors {
	public:
    int rank(vector<int> &V) {
        int i, j;
        int n = SZ(V);
        FOR(i,n) {
            sort(V.begin() + i, V.end(), greater<int>());
            if (V[i] == 0) break;
            int b = 1;
            while (b << 1 <= V[i]) {
                b <<= 1;
            }
            for (j = i + 1; j < n; j++) {
                if (b & V[j]) V[j] ^= V[i];
            }
        }
        return n - count(V.begin(), V.end(), 0);
    }
	int minColors (vector <int> colors) {
        return rank(colors);
	
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 7, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, minColors(Arg0)); }
	void test_case_1() { int Arr0[] = {10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, minColors(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, minColors(Arg0)); }
	void test_case_3() { int Arr0[] = {534, 251, 76, 468, 909, 410, 264, 387, 102, 982, 199, 111, 659, 386, 151}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(3, Arg1, minColors(Arg0)); }
	void test_case_4() { int Arr0[] = {4, 8, 16, 32, 64, 128, 256, 512, 1024}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(4, Arg1, minColors(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MixingColors __test;
	__test.run_test(-1);
}
// END CUT HERE
