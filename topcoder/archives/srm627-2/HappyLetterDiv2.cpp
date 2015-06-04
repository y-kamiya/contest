// BEGIN CUT HERE
// PROBLEM STATEMENT
/* The Happy Letter game is played as follows:
At the beginning, several players enter the field.
Each player has a lowercase English letter on their back.
The game is played in turns.
In each turn, you select two players with different letters, and both selected players leave the field.
The game ends once it is impossible to take another turn.

If there are some players left in the field at the end of the game, they must all have the same letter.
That letter is called the winning letter.
If there are no players left in the field at the end of the game, there is no winning letter.

In general, there may be many different ways how to play the game, and these may lead to different outcomes of the game.
However, sometimes we can look at the initial players and determine that each possible sequence of turns leads to the same winning letter.
That winning letter is then called a happy letter.

You are given a string letters.
The characters in letters are the characters carried by the players at the beginning of the game.
Return a string with one character: either the happy letter (if it exists), or a period ('.') if there is no happy letter.


DEFINITION
Class:HappyLetterDiv2
Method:getHappyLetter
Parameters:string
Returns:char
Method signature:char getHappyLetter(string letters)


CONSTRAINTS
-letters will contain between 1 and 50 elements.
-Each element of letters will be a lowercase English letter ('a'-'z').


EXAMPLES

0)
"aacaaa"

Returns: 'a'

In the first turn we send away the player with the 'c' and one of the players with an 'a'. All remaining players have an 'a', hence the game ends and 'a' is the winning letter.


1)
"dcdjx"

Returns: '.'

Each of the letters 'c', 'd', 'j', and 'x' can be the winning letter. Thus there is no happy letter.


2)
"bcbbbbba"

Returns: 'b'



3)
"aabc"

Returns: '.'

Here, only 'a' can be the winning letter. However, it is also possible that there is no winning letter at the end of the game. Therefore 'a' is not considered to be the happy letter.

*/
// END CUT HERE
#line 71 "HappyLetterDiv2.cpp"
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


class HappyLetterDiv2 {
	public:
	char getHappyLetter (string letters) {
        int i, sz = SZ(letters);
        int count[26] = {0};
        FOR(i,sz) {
            count[letters[i] - 'a']++;
        }
        int c, max = 0;
        FOR(i,26) {
            if (count[i] > max) { 
                max = count[i];
                c = i;
            }
        }
        if (max > sz / 2) {
            return c + 'a';
        }
        return '.';
	
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const char &Expected, const char &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aacaaa"; char Arg1 = 'a'; verify_case(0, Arg1, getHappyLetter(Arg0)); }
	void test_case_1() { string Arg0 = "dcdjx"; char Arg1 = '.'; verify_case(1, Arg1, getHappyLetter(Arg0)); }
	void test_case_2() { string Arg0 = "bcbbbbba"; char Arg1 = 'b'; verify_case(2, Arg1, getHappyLetter(Arg0)); }
	void test_case_3() { string Arg0 = "aabc"; char Arg1 = '.'; verify_case(3, Arg1, getHappyLetter(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	HappyLetterDiv2 __test;
	__test.run_test(-1);
}
// END CUT HERE
