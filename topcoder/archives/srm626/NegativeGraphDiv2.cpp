// BEGIN CUT HERE
// PROBLEM STATEMENT
/* 
Nancy has a directed graph with N vertices and E edges.
The vertices are numbered 1 through N.
Each edge of the graph has a positive integer weight.
This graph is described by three vector <int>s with E elements each: s, t, and weight.
For each valid i, the graph contains an edge s s[i] to t[i], and its weight is weight[i].
Note that Nancy's graph may contain multiple edges with the same start and end.
It may also contain self-loops.



Nancy is currently standing in the vertex 1.
She can reach other vertices by moving along the edges.
The cost of using an edge is equal to its weight.
Nancy's goal is to reach the vertex N and to minimize the total cost of doing so.



Nancy has a special power she can use to make her travels cheaper.
Whenever she traverses an edge, she can use that special power to make the weight of that edge temporarily negative.
You are given an int charges: the number of times Nancy can use her special power.
Each use of the special power only works for one traversal of an edge.
Nancy can traverse each edge arbitrarily many times.
Each time she traverses an edge, she may use her special power, if she still has some charges left.



Compute and return the minimal total cost of Nancy's journey.


DEFINITION
Class:NegativeGraphDiv2
Method:findMin
Parameters:int, vector <int>, vector <int>, vector <int>, int
Returns:long long
Method signature:long long findMin(int N, vector <int> s, vector <int> t, vector <int> weight, int charges)


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-E will be between 1 and 2500, inclusive.
-s, t, weight will each contain exactly E elements.
-s and t will only contain numbers between 1 and N, inclusive.
-There will be a path s node 1 to node N.
-weight will contain numbers between 0 and 100,000, inclusive. 
-charges will be between 0 and 1,000, inclusive.


EXAMPLES

0)
3
{1,1,2,2,3,3}
{2,3,1,3,1,2}
{1,5,1,10,1,1}
1

Returns: -9

The optimal path for Nancy is 1->2->3, and using her single charge on the last edge.

1)
1
{1}
{1}
{100}
1000

Returns: -100000

The graph may contain self-loops. Here, the optimal solution is that Nancy uses the self-loop 1,000 times, each time using her special power to change its cost s 100 to -100.

2)
2
{1,1,2}
{2,2,1}
{6,1,4}
2

Returns: -9

There can be multiple edges between vertices.

3)
2
{1}
{2}
{98765}
100

Returns: -98765

Nancy may not be able to use all her charges.
*/
// END CUT HERE
#line 99 "NegativeGraphDiv2.cpp"
#include<cstdio>
#include<cstdlib>
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
#define INF 1<<20
#define C_MAX 2500
#define V_MAX 50

typedef long long ll;
ll dp[C_MAX+1][V_MAX+1];

class NegativeGraphDiv2 {
	public:
	long long findMin(int N, vector <int> s, vector <int> t, vector <int> weight, int charges) {
        for (int i = 0; i < s.size(); i++) {
            s[i]--;
            t[i]--;
        }
        for (int i = 0; i <= C_MAX; i++) {
            for (int j = 0; j <= V_MAX; j++) {
                dp[i][j] = INF;
            }
        }
        dp[0][0] = 0;
        for (int c = 0; c <= charges; c++) {
            while (true) {
                bool update = false;
                for (int i = 0; i < s.size(); i++) {
                    int a = s[i], b = t[i], w = weight[i];
                    if (dp[c][a] != INF && dp[c][b] > dp[c][a] + w) {
                        dp[c][b] = dp[c][a] + w;
                        update = true;
                    }
                    if (c != 0 && dp[c-1][a] != INF && dp[c][b] > dp[c-1][a] - w) {
                        dp[c][b] = dp[c-1][a] - w;
                        update = true;
                    }
                }
                if (!update) break;
            }
        }

 	    long long res = INF;
        for (int c = 0; c <= charges; c++) {
            res = min(res, dp[c][N-1]);
        }

	    return res;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {1,1,2,2,3,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,1,3,1,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,5,1,10,1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; long long Arg5 = -9LL; verify_case(0, Arg5, findMin(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 1; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {100}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1000; long long Arg5 = -100000LL; verify_case(1, Arg5, findMin(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 2; int Arr1[] = {1,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,2,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {6,1,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; long long Arg5 = -9LL; verify_case(2, Arg5, findMin(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 2; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {98765}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 100; long long Arg5 = -98765LL; verify_case(3, Arg5, findMin(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  NegativeGraphDiv2 ___test;
  ___test.run_test(-1);
}
// END CUT HERE
