# include <stdio.h>

int y1, m1, d1, y2, m2, d2;

int md[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int tt[] = {0,  2,  1,  1,  2,  1,  2,  1,  2,  2,  2,  1,  2};

int get(int y, int yy, int mm, int dd)
{
    int ret = 0;
    for (int i = y; i < yy; ++i) {
        for(int m = 0; m < 13; ++m) {
            ret += md[m]*tt[m];
        }
        if ((i%4==0&&i%400!=0) || i%400==0) ret += 1;
    }
    for (int m = 0; m < mm; ++m) {
        ret += md[m]*tt[m];
    }
    ret += dd * tt[mm];
    if ((yy%4==0&&yy%400!=0) || yy%400==0) {
        if(mm > 2) ret += 1;
    }
    return ret;
}

int main()
{
    while (~scanf("%d%d%d%d%d%d", &y1, &m1, &d1, &y2, &m2, &d2)) {
        printf("%d\n", get(y1,y2,m2,d2) - get(y1,y1,m1,d1) + tt[m1]);
    }

    return 0;
}
