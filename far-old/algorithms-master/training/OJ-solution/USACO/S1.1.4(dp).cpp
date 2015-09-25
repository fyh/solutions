/*
PROG : beads
LANG : C++
ID : yajunw22
*/

# include <stdio.h>
# include <string.h>
# include <algorithm>

const int maxn = 5005;

int lr[maxn], lb[maxn], rr[maxn], rb[maxn];

int main()
{
	FILE * fin = fopen("beads.in", "r");
	FILE * fout = fopen("beads.out", "w");

	int n;
	char s[maxn];
	fscanf(fin, "%d", &n);
	fscanf(fin, "%s", s);

	fclose(fin);

	memset(lr, 0, sizeof(lr[0])*(n+1));
	memset(lb, 0, sizeof(lb[0])*(n+1));
	memset(rr, 0, sizeof(rr[0])*(n+1));
	memset(rb, 0, sizeof(rb[0])*(n+1));

	for (int i = n; i < 2*n; ++i) s[i] = s[i-n];
	n *= 2;

	for (int i = 0; s[i]; ++i) {
		if (s[i] == 'b') {
			lb[i] = ((!i) ? 1:(lb[i-1]+1));
			lr[i] = 0;
		} else if (s[i] == 'r') {
			lr[i] = ((!i) ? 1:(lr[i-1]+1));
			lb[i] = 0;
		} else {
			lb[i] = ((!i) ? 1:(lb[i-1]+1));
			lr[i] = ((!i) ? 1:(lr[i-1]+1));
		}
	}
	for (int i = n-1; i+1; --i) {
		if (s[i] == 'b') {
			rb[i] = (i==n-1) ? 1:(rb[i+1]+1);
			rr[i] = 0;
		} else if (s[i] == 'r') {
			rr[i] = (i==n-1) ? 1:(rr[i+1]+1);
			rb[i] = 0;
		} else {
			rb[i] = (i==n-1) ? 1:(rb[i+1]+1);
			rr[i] = (i==n-1) ? 1:(rr[i+1]+1);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = std::max(ans, std::max(lr[i], lb[i]) + std::max(rr[i+1], rb[i+1]));
	}

    if (ans > n/2) ans = n/2;

	fprintf(fout, "%d\n", ans);

	fclose(fout);

	return 0;
}
