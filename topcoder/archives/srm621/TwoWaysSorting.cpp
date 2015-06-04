// BEGIN CUT HERE
/* PROBLEM STATEMENT
// 
	Sasha has a vector <string> stringList. No two elements of stringList have the same length.



	So far, Sasha has learned two ways of sorting strings:


	
		He can sort strings lexicographically. For example, "car" < "carriage" < "cats" < "doggies". (See Notes for a definition of the lexicographic order.)
	
	
		He can also sort strings according to their lengths in ascending order. For example, "car" < "cats" < "doggies" < "carriage".
	


	Sasha now wonders whether stringList is sorted in either of these two ways. Return "lexicographically" (quotes for clarity) if stringList is sorted lexicographically but not according to the string lengths. Return "lengths" if stringList is sorted according to the string lengths but not lexicographically. Return "both" if it is sorted in both ways. Otherwise, return "none".



DEFINITION
Class:TwoWaysSorting
Method:sortingMethod
Parameters:vector <string>
Returns:string
Method signature:string sortingMethod(vector <string> stringList)


NOTES
-String A is lexicographically smaller than string B if A contains a character with a smaller ASCII value in the first position where they differ. In case one of the strings ends before they have a different character, the shorter one is considered smaller.


CONSTRAINTS
-stringList will contain between 1 and 50 elements, inclusive.
-Each element of stringList will contain between 1 and 50 characters, inclusive.
-Each character of each element of stringList will be a lowercase English letter ('a'-'z').
-Every two elements of stringList will have different lengths.


EXAMPLES

0)
{"a", "aa", "bbb"}

Returns: "both"

These strings are sorted both lexicographically and according to their lengths.

1)
{"c", "bb", "aaa"}

Returns: "lengths"

The lengths of these strings are in ascending order. However, they are not sorted lexicographically as, for instance, "aaa" is lexicographically smaller than "c".

2)
{"etdfgfh", "aio"}

Returns: "none"

Here the first string is longer than the second one, so they are not sorted according to length. (Note that we require the lengths to be in ascending order.) Similarly, they are not sorted lexicographically: "aio" should come before "etdfgfh".

3)
{"aaa", "z"}

Returns: "lexicographically"

The input strings are sorted lexicographically only.

4)
{"z"}

Returns: "both"



5)
{"abcdef", "bcdef", "cdef", "def", "ef", "f", "topcoder"}

Returns: "lexicographically"


*/
// END CUT HERE
#line 88 "TwoWaysSorting.cpp"
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

class Short {
public:
    bool operator()(const string& l, const string& r) {
        return l.size() < r.size();
    }
};

class TwoWaysSorting {
	public:
	string sortingMethod (vector <string> stringList) {
        int n = SZ(stringList);
        vector<string> lex = stringList;
        vector<string> len = stringList;
        sort(lex.begin(), lex.end());
        bool islex = true;
        for (int i = 0; i < n; i++) {
            if (stringList[i] != lex[i]) {
                islex = false;
                break;
            }
        }
        sort(len.begin(), len.end(), Short());
        bool islen = true;
        for (int i = 0; i < n; i++) {
            if (stringList[i] != len[i]) {
                islen = false;
                break;
            }
        }
        string res;
        if (islex && islen) {
            res = "both";
        } else if (islex) {
            res = "lexicographically";
        } else if (islen) {
            res = "lengths";
        } else {
            res = "none";
        }
        return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"a", "aa", "bbb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "both"; verify_case(0, Arg1, sortingMethod(Arg0)); }
	void test_case_1() { string Arr0[] = {"c", "bb", "aaa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "lengths"; verify_case(1, Arg1, sortingMethod(Arg0)); }
	void test_case_2() { string Arr0[] = {"etdfgfh", "aio"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "none"; verify_case(2, Arg1, sortingMethod(Arg0)); }
	void test_case_3() { string Arr0[] = {"aaa", "z"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "lexicographically"; verify_case(3, Arg1, sortingMethod(Arg0)); }
	void test_case_4() { string Arr0[] = {"z"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "both"; verify_case(4, Arg1, sortingMethod(Arg0)); }
	void test_case_5() { string Arr0[] = {"abcdef", "bcdef", "cdef", "def", "ef", "f", "topcoder"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "lexicographically"; verify_case(5, Arg1, sortingMethod(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TwoWaysSorting __test;
	__test.run_test(-1);
}
// END CUT HERE
