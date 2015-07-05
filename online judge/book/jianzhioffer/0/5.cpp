# include <string>
# include <iostream>
using namespace std;
class Solution {
public:
	string replaceSpace(string str) {
	    string ret;
	    for (int i = 0; i < str.length(); ++i) {
	        if (str[i] != ' ') ret += str[i];
	        else ret += "\%20";
	    }
	    return ret;
	}
};

int main()
{
    Solution s;
    std::cout << s.replaceSpace("we are w!");
    return 0;
}

