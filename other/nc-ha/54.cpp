# include <stdio.h>a

int n;

int get(int x) {
    int ret = x/100;
    x%=100; ret += x/50; x%=50;
    ret += x/20; x%=20; ret += x/10; x%=10;
    ret += x/5; x%=5; ret += x/2; x%=2;
    ret += x;
    return ret;
}

int main()
{
    while (~scanf("%d", &n)) {
        int s = 0;
        for (int i = 0; i < n; ++i) {
            int x; scanf("%d", &x);
            s += get(x);
        }
        printf("%d\n", s);
    }

    return 0;
}
