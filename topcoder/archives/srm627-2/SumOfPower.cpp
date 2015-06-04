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
#define INF 10^20
#define MAX 50

class SumOfPower {
	public:
	int findSum(vector <int> array) {
 	    int res = 0;
        int sz = array.size();
        for (int i = 1; i <= sz; i++) {
            for (int j = 0; j < sz; j++) {
                if (j + i > sz) break;
                for (int k = j; k < j + i; k++) {
                    res += array[k];
                }
            }
        }
	    return res;
	}

	

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
