# include <stdio.h>
# include <math.h>
class Solution {
public:
	double Power(double base, int exponent) {
	    if (fabs(base) <= 1e-6 ) return 0.0;
	    if (exponent < 0) base = 1.0/base, exponent = -exponent;
	    double ret = 1.0;
	    double hr = base;
	    while (exponent > 0) {
	        if (exponent & 0x1) ret *= hr;
	        hr = hr * hr;
	        exponent >>= 1;
	    }
	    return ret;
	}
};

int main()
{
    Solution s;
    for (int i = 0; i < 6; ++i) {
        printf("%lf\n", s.Power(2, 0));
    }
    return 0;
}
