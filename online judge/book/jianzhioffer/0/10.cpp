# include <map>
class Solution {
private:
    std::map<int, int> m;
public:
	int Fibonacci(int n) {
	    int t = m[n];
	    if (t > 0) return t;
	    if (n <= 1) return m[n] = n;
	    return m[n] = Fibonacci(n-1) + Fibonacci(n-2);
	}
};
