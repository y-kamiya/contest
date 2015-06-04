// BEGIN CUT HERE
// PROBLEM STATEMENT
// Fox Ciel likes all the words that have the following properties:

Each letter of the word is an uppercase English letter.
Equal letters are never consecutive.
There is no subsequence of the form xyxy, where x and y are (not necessarily distinct) letters. Note that a subsequence doesn't have to be contiguous.

Examples:

Ciel does not like "ABBA" because there are two consecutive 'B's.
Ciel does not like "THETOPCODER" because it contains the subsequence "TETE".
Ciel does not like "ABACADA" because it contains the subsequence "AAAA". (Note that here x=y='A'.)
Ciel likes "A", "ABA", and also "ABCBA".

Given a string word, return "Likes" (quotes for clarity) if Ciel likes word and "Dislikes" if she does not.


DEFINITION
Class:LongWordsDiv2
Method:find
Parameters:string
Returns:string
Method signature:string find(string word)


CONSTRAINTS
-word will contain between 1 and 100 characters, inclusive.
-Each character of word will be an uppercase English letter ('A'-'Z').


EXAMPLES

0)
"AAA"

Returns: "Dislikes"



1)
"ABCBA"

Returns: "Likes"



2)
"ABCBAC"

Returns: "Dislikes"



3)
"TOPCODER"

Returns: "Likes"



4)
"VAMOSGIMNASIA"

Returns: "Dislikes"



5)
"SINGLEROUNDMATCH"

Returns: "Likes"



6)
"DALELOBO"

Returns: "Likes"



// END CUT HERE
#line 85 "LongWordsDiv2.cpp"
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

class LongWordsDiv2 {
	public:
	string find (string word) {
	
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AAA"; string Arg1 = "Dislikes"; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { string Arg0 = "ABCBA"; string Arg1 = "Likes"; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { string Arg0 = "ABCBAC"; string Arg1 = "Dislikes"; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { string Arg0 = "TOPCODER"; string Arg1 = "Likes"; verify_case(3, Arg1, find(Arg0)); }
	void test_case_4() { string Arg0 = "VAMOSGIMNASIA"; string Arg1 = "Dislikes"; verify_case(4, Arg1, find(Arg0)); }
	void test_case_5() { string Arg0 = "SINGLEROUNDMATCH"; string Arg1 = "Likes"; verify_case(5, Arg1, find(Arg0)); }
	void test_case_6() { string Arg0 = "DALELOBO"; string Arg1 = "Likes"; verify_case(6, Arg1, find(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LongWordsDiv2 __test;
	__test.run_test(-1);
}
// END CUT HERE
