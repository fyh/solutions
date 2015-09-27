/*
LANG : C++
ID : yajunw22
PROG : transform
*/

# include <stdio.h>


const int maxn = 15;

int n;
char mp[maxn][maxn];
char sr[maxn][maxn];
char mr[maxn][maxn];

bool cmp(void)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (mr[i][j] != sr[i][j]) return false;
		}
	}
	return true;
}

void cRotate(void)
{
	int tmr[maxn][maxn];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			tmr[i][j] = mr[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
        for (int j = n-1; j >= 0; --j) {
            mr[i][j] = tmr[n-1-j][i];
        }
	}
}

void reflect(void)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n/2; ++j) {
			int t = mr[i][j];
			mr[i][j] = mr[i][n-1-j];
			mr[i][n-1-j] = t;
		}
	}
}

void initCopy(void)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			mr[i][j] = mp[i][j];
		}
	}
}

int work(void)
{
	initCopy();
	cRotate();
	if (cmp()) return 1;
	cRotate();
	if (cmp()) return 2;
	cRotate();
	if (cmp()) return 3;

	initCopy();
	reflect();
	if (cmp()) return 4;
	cRotate();
	if (cmp()) return 5;
	cRotate();
	if (cmp()) return 5;
	cRotate();
	if (cmp()) return 5;
	initCopy();
	if (cmp()) return 6;
	return 7;
}

int main()
{
	FILE * fin = fopen("transform.in", "r");
	FILE * fout = fopen("transform.out", "w");

	fscanf(fin, "%d", &n);
	for (int i = 0; i < n; ++i) fscanf(fin, "%s", mp[i]);
	for (int i = 0; i < n; ++i) fscanf(fin, "%s", sr[i]);

	fclose(fin);

	fprintf(fout, "%d\n", work());

	fclose(fout);

	return 0;
}
