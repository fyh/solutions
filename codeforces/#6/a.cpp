# include <stdio.h>
# include <algorithm>

# define testin freopen("in.txt", "r", stdin)

int a[5];

int test(int i, int j, int k) {
    if (a[i]+a[j]>a[k]) return 1;
    else if (a[i]+a[j]==a[k]) return 0;
    else return -1;
}

int main()
{
    // testin;
    for(int i = 0; i < 4; ++i) scanf("%d", &a[i]);
    std::sort(a, a+4);
    if (test(0,1,2)==1 || test(1,2,3)==1) {
        puts("TRIANGLE");
    } else if (!test(0,1,2) || !test(0,1,3) || !test(0,2,3) || !test(1,2,3) ) {
        puts("SEGMENT");
    } else puts("IMPOSSIBLE");
    return 0;
}
