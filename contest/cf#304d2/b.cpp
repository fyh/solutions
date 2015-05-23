# include <map>
# include <stdio.h>
std::map<int,int> c;

int n;
int main()
{
    int ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        ++c[x];
    }
    for (int i = 1; i <= 3*n; ++i) {
        while (c[i] > 1) {
            --c[i];
            ++ans;
            ++c[i+1];
        }
    }
    printf("%d\n", ans);
    return 0;
}
