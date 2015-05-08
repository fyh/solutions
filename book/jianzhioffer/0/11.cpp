class Solution {
public:
	 int  NumberOf1(int n) {
	     int ret = 0;
	     while (n) {
	         ++ret;
	         n &= (n-1);
	     }
	     return ret;
	 }
};
