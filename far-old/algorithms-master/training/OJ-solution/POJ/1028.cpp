# include <stdio.h>
# include <string.h>
const int maxn = 105;
const int maxm = 75;
class brows{
public:
    char s[maxn][maxm];
    int top;
    int i;
    brows() {i = top = -1; visit( "http://www.acm.org/", false); }
    void forw(void) {
        if (i+1<top) printf("%s\n", s[++i]);
        else printf("Ignored\n");
    }
    void backw(void) {
        if (i-1>=0) printf("%s\n", s[--i]);
        else printf("Ignored\n");
    }
    void visit(const char *str, bool show=true) {
        if(show) printf("%s\n", str);
        top = ++i;
        strcpy(s[top], str);
        ++top;
    }
};

brows b;
int main()
{
    char od[15];
    char s[75];
    while (scanf("%s", od), strcmp(od, "QUIT")!=0) {
        switch (od[0]) {
        case 'V': scanf("%s", s); b.visit(s); break;
        case 'F': b.forw(); break;
        case 'B': b.backw(); break;
        }
    }

    return 0;
}
