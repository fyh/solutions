# include <stdio.h>

int get(int x, int y) {
    while (x != y) {
        if (x > y) x/=2;
        else y/=2;
    }
    return x;
}

int main()
{
    int x, y;

    while (~scanf("%d%d",&x,&y)) {
        printf("%d\n", get(x, y));
    }

    return 0;
}
