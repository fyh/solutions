class Solution {
public:
	int Sum_Solution(int n) {
	    if (n&0x1) return (n+1)/2*n;
	    return n/2*(n+1);
	}
};
