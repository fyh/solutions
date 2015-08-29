#line 64 "EqualSubstrings.cpp"
#include<bits/stdc++.h>
using namespace std;

class EqualSubstrings {
	public:
	vector <string> getSubstrings(string str) {
	    vector<string> ret;
		int ca = 0;
		for (int i = 0; i < str.length(); ++i) {
            if (str[i] == 'a') ++ca;
		}
		if (ca == 0) {
            ret.push_back(str);
            ret.push_back(string(""));
            return ret;
		}
		int cb = 0;
		for (int i = str.length()-1; i >= 0; --i) {
            if (str[i] == 'b') ++cb;
            else if (str[i] == 'a') --ca;
            if (cb == ca) {
                ret.push_back(str.substr(0,i));
                ret.push_back(str.substr(i, str.length()-i));
                return ret;
            }
		}
		return ret;
	}
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
