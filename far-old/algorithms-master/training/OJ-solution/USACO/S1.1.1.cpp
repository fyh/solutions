/*
ID : yajunw22
PROG : ride
LANG : C++
*/

# include <stdio.h>

int cal( char * s )
{
    int ret = 1;
    for (int i = 0; s[i]; ++i) {
        ret *= s[i]-'A'+1;
    }
    return ret % 47;
}

int main()
{
    char c[15];
    char g[15];

    FILE * fin = fopen("ride.in", "r");
    FILE * fout = fopen("ride.out", "w");

    fscanf( fin, "%s%s", c, g );

    fclose(fin);

    if ( cal(c) == cal(g) )  {
        fprintf( fout, "GO\n");
    } else {
        fprintf( fout, "STAY\n" );
    }

    fclose(fout);

    return 0;
}
