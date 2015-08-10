# include <stdio.h>
# include <math.h>

double SQ(double x) { return x*x; }
int main()
{
	int n;
	while (scanf("%d", &n) != EOF) {
		double ans = 0.0;
		double x0, y0;
		for (int i = 0; i < n; ++i) {
			scanf("%lf%lf", &x, &y);
			if (!i) {
				x0 = x;
				y0 = y;
			}
			ans += sqrt( SQ(x-x0)+SQ(y-y0) );
			x0 = x, y0 = y;
		}
		printf("%.4lf\n", ans);
	}	
	
	return 0;
}
