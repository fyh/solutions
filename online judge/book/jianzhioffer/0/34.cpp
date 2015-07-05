# include <string>
# include <string.h>
# include <iostream>
using namespace std;
class Solution {
    const int N = 256;
public:
	int FirstNotRepeatingChar(string str) {
	    if (str.length() <= 0) return -1;
	    int p[N];
	    int a[N];
	    int c[N];
	    int k = 0;
	    memset(c, 0, sizeof(c));
	    memset(p, -1, sizeof(p));
	    for (int i = 0; i < str.length(); ++i) {
            int t = str[i];
            if (p[t] == -1) {
                p[t] = k;
                a[k] = i;
                c[t] = 1;
                ++k;
            } else {
                ++c[t];
            }
	    }
	    for (int i = 0; i < k; ++i) if (c[ str[a[i]] ] == 1) return a[i];
	    return -1;
	}
};

int main()
{
    Solution s;
    cout << s.FirstNotRepeatingChar("AAbbBCD") << endl;
    return 0;
}
