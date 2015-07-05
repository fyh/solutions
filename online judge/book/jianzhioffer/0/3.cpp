# include <map>
class Solution {
private:
    std::map<int, int> m;
public:
	int rectCover(int number) {
	    int t = m[number];
	    if (t > 0) return t;
	    if (number <= 1) return m[number] = 1;
	    return m[number] = rectCover(number-1) + rectCover(number-2);
	}
};
