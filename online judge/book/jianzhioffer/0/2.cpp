# include <map>
# include <iostream>
using namespace std;
class Solution {
private:
    map<int,int> m;
public:
	int jumpFloorII(int number) {
	    int t = m[number];
	    if (t > 0) return t;
	    if (number <= 1) return m[number] = 1;
	    t = 0;
	    for (int i = 0; i < number; ++i) t += jumpFloorII(i);
	    return m[number] = t;
	}
};

int main()
{
    Solution s;
    for (int i = 0; i < 10; ++i)
        cout << s.jumpFloorII(i) << endl;
    return 0;
}
