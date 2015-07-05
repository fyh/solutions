# include <map>
# include <queue>
# include <vector>
# include <iostream>
using namespace std;
class Solution {
    map<long long int, int> m;
public:
	int GetUglyNumber_Solution(int index) {
	    if (index <= 0) return 0;
	    if (index == 1) return 1;
	    priority_queue<long long int, vector<long long int>, greater<long long int> > Q;
	    m.clear();
	    Q.push(2);
	    Q.push(3);
	    Q.push(5);
	    long long int x;
	    for (int i = 1; i < index; ++i) {
            x = Q.top(); Q.pop();
            if (!m[2*x]) Q.push(2*x), ++m[2*x];
            if (!m[3*x]) Q.push(3*x), ++m[3*x];
            if (!m[5*x]) Q.push(5*x), ++m[5*x];
	    }
	    return x;
	}
};

int main()
{
    Solution s;
    for (int i = 0; i < 10; ++i) {
        cout << s.GetUglyNumber_Solution(1500) << endl;
    }
    return 0;
}
