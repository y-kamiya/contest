#line 92 "ImageDithering.cpp"
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
#define CLR(x,a) memset(x,a,sizeof(x))
#define SZ(x) (int)x.size()
#define FOR(i,m,n) for(i=m;i<(n);i++)
#define INF 1<<20

typedef long long ll;

class ImageDithering {
	public:
	int count (string dithered, vector <string> screen) {
        int i,j, count = 0;
        const int n = dithered.size();
        FOR (i,0,n) {
            for (vector<string>::iterator it = screen.begin(); it != screen.end(); it++) {
                string line = *it;
                FOR (j,0,SZ(line)) {
                    if (dithered[i] == line[j]) count++;
                }
            }
        }
        return count;
	}
	

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
