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
class BinaryCode {
	public:
	vector <string> decode (string message) {
        int length = message.length();
        vector<string> ret;

        for (int i = 0; i <= 1; i++) {
            ret.push_back(itos(i));
            int P[2] = {0, i};

            for (int j = 1; j <= length; j++) {
                const char c = message[j-1];
                int d = atoi(&c);
                int v = d - P[0] - P[1];
                if (v == 0 || v == 1) {
                    if (j != length) { 
                        ret[i].append(itos(v));
                        P[0] = P[1];
                        P[1] = v;
                    }
                } else {
                    ret[i] = "NONE";
                    break;
                }
            }
        }
        return ret;
	}

    string itos(int num) {
        stringstream ss;
        ss << num;
        return ss.str();
    }
	

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
