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
class Time {
	public:
	string whatTime (int seconds) {
        int rest = seconds % (60 * 60);
        int min = rest / 60;
        int sec = rest % 60;
        stringstream ss;
        ss << seconds / (60 * 60) << ":" << min << ":" << sec;
        return ss.str();
	}
	

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
