
# include <stdio.h>
# include <ctype.h>
# include <iostream>

# define testin freopen("in.txt", "r", stdin)

void ch_rxcy(int r, int c)
{
    printf("R%dC%d\n", r, c);
}

void pr_col(int c)
{
    if (c > 0) {
        int t = c%26;
        if (t == 0) c--, t = 26;
        c/=26;
        pr_col(c);
        printf("%c", t+'A'-1);
    }
}

void ch_A1(int r, int c)
{
    pr_col(c);
    printf("%d\n", r);
}

int n;
char s[55];

int main()
{
    //testin;

    scanf("%d", &n);
    for (int ica = 0; ica < n; ++ica) {
        scanf("%s", s);
        bool rxcy = false;
        for (int i = 0; s[i]; ++i) {
            if (s[i] == 'C') {
                if (i > 0) {
                    if ( isdigit(s[i-1]) ) {
                        rxcy = true;
                        break;
                    }
                }
            }
        }
        int r = 0, c = 0;
        if (rxcy) {
            for (int i = 1; s[i] != 'C'; ++i) {
                r = r*10 + (s[i]-'0');
            }
            for (int i = 0; s[i]; ++i) {
                if (s[i] == 'C') {
                    for (++i;s[i]; ++i) {
                        c = c*10 + (s[i]-'0');
                    }
                    break;
                }
            }
            ch_A1(r, c);
        } else {
            for (int i = 0; s[i]; ++i) {
                if (isalpha(s[i])) {
                    c = c*26 + (s[i]-'A')+1;
                } else {
                    r = r*10 + (s[i]-'0');
                }
            }
            ch_rxcy(r, c);
        }
    }

    return 0;
}
