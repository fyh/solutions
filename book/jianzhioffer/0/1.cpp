# include <map>
# include <iostream>
using namespace std;
class Solution {
private:
    map<int,int> m;
public:
	int jumpFloor(int number) {
	    int t = m[number];
	    if (t > 0) return t;
	    if (number <= 1) return m[number] = 1;
	    return m[number] = jumpFloor(number-1) + jumpFloor(number-2);
	}
};

int main()
{
    Solution s;
    for (int i = 0; i < 10; ++i)
        cout << s.jumpFloor(i) << endl;
    return 0;
}
