/*
LANG : C++
PROG : milk2
ID : yajunw22
*/

# include <algorithm>
# include <stdio.h>

const int maxn = 5005;

int n;
int r[maxn];
int b[maxn], f[maxn];

bool cmp(int x, int y)
{
	if (b[x] == b[y]) return f[x] < f[y];
	return b[x] < b[y];
}

int main()
{
	FILE * fin = fopen("milk2.in", "r");
	FILE * fout = fopen("milk2.out", "w");

	fscanf(fin, "%d", &n);
	for (int i = 0; i < n; ++i) fscanf(fin, "%d%d", &b[i], &f[i]);
	fclose(fin);

	for (int i = 0; i < n; ++i) r[i] = i;

	std::sort(r, r+n, cmp);

	int aa = 0, ab = 0;
	int ss = b[ r[0] ], ff = f[ r[0] ];
	for (int i = 0; i < n; ++i) {
		int idx = r[i];
		if ( b[idx] > ff ) ss = b[idx];
		ab = std::max(ab, ss-ff);
		ff = std::max(ff, f[idx]);
        aa = std::max(aa, ff-ss);
	}

	fprintf(fout, "%d %d\n", aa, ab);

	fclose(fout);

	return 0;
}
