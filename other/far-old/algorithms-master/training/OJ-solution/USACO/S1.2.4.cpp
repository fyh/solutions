/*
ID : yajunw22
LANG : C++
PROG : palsquare
*/

# include <stdio.h>

int B;

void readBase(void)
{
	FILE * fp = fopen("palsquare.in", "r");
	fscanf(fp, "%d", &B);
	fclose(fp);
}

void work(void)
{
	FILE * fout = fopen("palsquare.out", "w");
	char s[20];
	char t[20];
	for (int i = 1; i < 301; ++i) {
		int sq = i * i;
		int digLen = 0;
		while (sq > 0) {
			if (sq%B<10) s[digLen++] = sq%B + '0';
			else s[digLen++] = sq%B -10 + 'A';
			sq /= B;
		}
		s[digLen] = '\0';
		bool ok = true;
		for (int j = 0; j < digLen/2; ++j) {
			if (s[j] != s[digLen-1-j]) {
				ok = false;
				break;
			}
		}
		int tmp = i;
		int n = 0;
		for (int j = 0; tmp > 0; ++j) {
			if (tmp%B < 10)	t[j] = tmp%B + '0';
			else t[j] = tmp%B -10 + 'A';
			tmp /= B;
			if (tmp <= 0) t[j+1] = '\0', n = j+1;
		}
		for (int j = 0; j < n/2; ++j) {
			char tt = t[j];
			t[j] = t[n-1-j];
			t[n-1-j] = tt;
		}
		if (ok) {
			fprintf(fout, "%s %s\n", t, s);
		}
	}
	fclose(fout);
}

int main()
{
	readBase();
	work();

	return 0;
}
