# include <string>
# include <iostream>
# include <limits>
using namespace std;
class Solution {
private:
    string trim(string &s)
    {
        int x = 0, y = s.length()-1;
        for (; x <= y && s[x] == ' '; ++x) ;
        for (; y >= x && s[y] == ' '; --y) ;
        if (x > y) return "";
        return s.substr(x, y-x+1);
    }
public:
	int StrToInt(string str) {
	    str = trim(str);
	    if (str.length() > 13) return 0;
	    long long int ret = 0;
	    int f = 1;
        int i = 0;
	    if (str[0] == '-') f = -1, ++i;
	    if (str[0] == '+') ++i;
	    for (; i < str.length(); ++i) {
            if (!isdigit(str[i])) return 0;
            ret = ret * 10 + str[i] - '0';
	    }
	    ret *= f;
	    if (ret < numeric_limits<int>::min() || ret > numeric_limits<int>::max()) return 0;
	    return (int)(ret);
	}
};

int main()
{
    Solution s;
    std::cout << s.StrToInt(" -123  ");
    return 0;
}
