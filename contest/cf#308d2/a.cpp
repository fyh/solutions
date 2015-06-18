# include <bits/stdc++.h>
using namespace std;

# define testin freopen("data.in", "r", stdin)

const int maxn = 105;

int n;
int X1, Y1, X2, Y2;

int main()
{
    //testin;
    int sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);
        sum += (abs(X1-X2)+1) * (abs(Y1-Y2)+1);
    }
    printf("%d\n", sum);


    return 0;
}
