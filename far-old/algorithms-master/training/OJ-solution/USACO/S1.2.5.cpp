/*
PROG : dualpal
LANG : C++
ID : yajunw22
*/

# include <string.h>
# include <stdio.h>

int N,S;

void readArg(void)
{
	FILE * fp = fopen("dualpal.in", "r");
	fscanf(fp, "%d%d", &N, &S);
	fclose(fp);
}

bool isPalindrome(int base, int x)
{
	char s[35];
	int n;
	for (n = 0; x; ) {
		s[n++] = x%base + '0';
		x /= base;
	}
	for (int i = 0; i < n/2; ++i) {
		if (s[i] != s[n-1-i]) return false;
	}
	return true;
}

void work(void)
{
	FILE * fp = fopen("dualpal.out", "w");
	for (int c = 0, i = S+1; c < N ; ++i) {
		int tc = 0;
		for (int b = 2; b < 11; ++b) {
			if (isPalindrome(b, i)) ++tc;
			if (tc > 1) {
                ++c;
				fprintf(fp, "%d\n", i);
				break;
			}
		}
	}
	fclose(fp);
}

int main()
{
	readArg();
	work();

	return 0;
}
