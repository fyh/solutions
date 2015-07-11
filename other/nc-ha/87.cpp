# include <stdio.h>

int get(int y, int m, int d) {
    if (m < 3) m += 12, --y;
    int c = y / 100;
    y = y % 100;
    return ((y+y/4+c/4-2*c+(26*(m+1))/10+d-1) % 7 + 7) %7;
}
void pr(int y, int m, int d) {
    printf("%04d-%02d-%02d\n", y, m, d);
    // printf("%d\n", get(y,m,d));
}
void getW(int y, int m, int w, int c) {
    for (int d = 1; d < 32; ++d) {
        if (get(y,m,d) == w%7) {
            --c;
            if (!c) {pr(y,m,d); return ;}
        }
    }
}
int main()
{
    int y;
    while (~scanf("%d", &y)) {
        pr(y,1, 1);
        getW(y,1,1,3);
        getW(y,2,1,3);
        for (int d = 31; d >= 1; --d) {
            if (get(y,5,d) == 1) {pr(y,5,d); break;}
        }
        pr(y,7,4);
        getW(y,9,1,1);
        getW(y,11,4,4);
        pr(y,12,25);
        putchar('\n');
    }

    return 0;
}
