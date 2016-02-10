# include <stdio.h>
# include <math.h>
# include <iostream>

# define testin freopen("in.txt", "r", stdin)

int n, m, a;

int main() {
    //testin;

    scanf("%d%d%d", &n, &m, &a);
    int r = ceil(n * 1.0 / a);
    int c = ceil(m * 1.0 / a);
    printf("%I64d\n", (long long int) r * c);

    return 0;
}
