// BEGIN CUT HERE
/* PROBLEM STATEMENT
// Your friend Lucas gave you a sequence S of positive integers.

For a while, you two played a simple game with S:
Lucas would pick a number, and you had to select some elements of S such that the sum of all numbers you selected is the number chosen by Lucas.
For example, if S={2,1,2,7} and Lucas chose the number 11, you would answer that 2+2+7 = 11.

Lucas now wants to trick you by choosing a number X such that there will be no valid answer.
For example, if S={2,1,2,7}, it is not possible to select elements of S that sum up to 6.

You are given the vector <int> S.
Find the smallest positive integer X that cannot be obtained as the sum of some (possibly all) elements of S.

DEFINITION
Class:NumbersChallenge
Method:MinNumber
Parameters:vector <int>
Returns:int
Method signature:int MinNumber(vector <int> S)


CONSTRAINTS
-S will contain between 1 and 20 elements, inclusive.
-Each element of S will be between 1 and 100,000, inclusive.


EXAMPLES

0)
{5, 1, 2}

Returns: 4

These are all the positive integers that can be obtained: 1, 2, 3, 5, 6, 7, and 8.
(We can obtain 3 as 1+2, 6 as 1+5, 7 as 2+5, and 8 as 1+2+5.)
The smallest positive integer not present in the above list is 4.

1)
{2, 1, 4}

Returns: 8

We can obtain each of the sums from 1 to 7, inclusive. The smallest impossible sum is 8.

2)
{2, 1, 2, 7}

Returns: 6

The example given in the problem statement.

3)
{94512, 2, 87654, 81316, 6, 5, 6, 37151, 6, 139, 1, 36, 307, 1, 377, 101, 8, 37, 58, 1}

Returns: 1092



4)
{883, 66392, 3531, 28257, 1, 14131, 57, 1, 25, 88474, 4, 1, 110, 6, 1769, 220, 442, 7064, 7, 13}

Returns: 56523


*/
// END CUT HERE
#line 69 "NumbersChallenge.cpp"
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
#define INF 1<<20

class NumbersChallenge {
	public:
    void dfs(set<int> &s, int sum, int index, vector<int> S) {
        int a = sum + S[index];
        s.insert(a);
        if (SZ(S) - 1 > index) {
            dfs(s, sum, index+1, S);
            dfs(s, a, index+1, S);
        }
    }
	int MinNumber (vector <int> S) {
        set<int> s;
        dfs(s, 0, 0, S);
        for (int i = 1; i < INF; i++) {
            set<int>::iterator it = s.find(i);
            if (it == s.end()) return i;
        }
        return 0;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, MinNumber(Arg0)); }
	void test_case_1() { int Arr0[] = {2, 1, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(1, Arg1, MinNumber(Arg0)); }
	void test_case_2() { int Arr0[] = {2, 1, 2, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(2, Arg1, MinNumber(Arg0)); }
	void test_case_3() { int Arr0[] = {94512, 2, 87654, 81316, 6, 5, 6, 37151, 6, 139, 1, 36, 307, 1, 377, 101, 8, 37, 58, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1092; verify_case(3, Arg1, MinNumber(Arg0)); }
	void test_case_4() { int Arr0[] = {883, 66392, 3531, 28257, 1, 14131, 57, 1, 25, 88474, 4, 1, 110, 6, 1769, 220, 442, 7064, 7, 13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 56523; verify_case(4, Arg1, MinNumber(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	NumbersChallenge __test;
	__test.run_test(-1);
}
// END CUT HERE
