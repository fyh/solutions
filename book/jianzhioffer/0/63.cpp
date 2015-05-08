# include <set>
class Solution {
private:
    std::multiset<int> s;
public:
	void Insert(int num)
	{
	    s.insert(num);
	}
	double GetMedian()
	{
	    int n = s.size();
	    if (!n) return 0.0;
	    std::multiset<int>::iterator it = s.begin();
	    if (n&0x1) {
	        advance(it, n/2);
	        return *it;
	    } else {
            double ret = 0.0;
	        advance(it, n/2-1);
	        ret += *it;
	        ++it;
	        ret += *it;
	        return 0.5 * ret;
	    }
	}
};
