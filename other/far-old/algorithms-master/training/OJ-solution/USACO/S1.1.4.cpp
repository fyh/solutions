/*
ID : yajunw22
LANG : C++
PROG : beads
*/
# include <stdio.h>
# include <string.h>
int MyMax(int x, int y) {
    return x>y ? x:y;
}
char s[500005];
int main()
{
	FILE * fin = fopen("beads.in", "r");
	FILE * fout = fopen("beads.out", "w");
	int N;
	fscanf(fin, "%d%s", &N, s);
	fclose(fin);
	for (int i = N; i < 2*N; ++i) s[i] = s[i-N]; s[2*N] = '\0';
	int ans = 0;
	int a = 0, b = 0;
	for (int i = 0; i < N; ) {
        int t = i;
		while( s[i]=='w' || s[i] == s[t] ) {
			if ( s[i] == s[t] ) t = i;
			++i;
			++a;
		}
		ans = MyMax( a+b, ans );
		b = a;
		if (s[t]!='w') {a = i-t-1; b = b-a;}
	}
	if (ans > N) ans = N;
	fprintf(fout, "%d\n", ans);
	fclose(fout);
	return 0;
}
