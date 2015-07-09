# include <stdio.h>

const int maxm = 55;

int m, n;
char name[maxm][25];
int acc[maxm];

int main()
{
    while (~scanf("%d%d", &m, &n)) {
        for (int i = 0; i < m; ++i) {
            scanf("%s%d", name[i], &acc[i]);
        }
        int cnt = 0;
        for (;cnt != m;) {
            bool ok = false;
            for (int i = 0; i < m; ++i) {
                if (acc[i]>0 && n >= acc[i]) {
                    ok = true;
                    printf("%s\n", name[i]);
                    n -= acc[i];
                    acc[i] = -acc[i];
                    ++cnt;
                }
            }
            for (int i = 0; i < m; ++i) {
                if (acc[i] < 0) {
                    n += -acc[i];
                    acc[i] = 0;
                }
            }
        }
        printf("\n");
    }

    return 0;
}
