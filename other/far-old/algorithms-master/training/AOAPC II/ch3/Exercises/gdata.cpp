#include <ctime>
#include <cstdlib>
# include <cstdio>
# include <algorithm>
int main()
{
    int x, y, z;

    srand(time(NULL));

    freopen("in.txt", "w", stdout);

    int T = 100000;
    int a[12];
    while (T--) {
        x = rand();
        y = rand();
        z = rand();
        a[0] = a[2] = x;
        a[1] = a[3] = y;
        a[4] = a[6] = x;
        a[5] = a[7] = z;
        a[8] = a[10] = y;
        a[9] = a[11] = z;
        for (int i = 0; i < 6; ++i) {
            int t = rand()%(6-i) + i;
            if (i!=t) {
                std::swap(a[2*i], a[2*t]);
                std::swap(a[2*i+1], a[2*t+1]);
            }
            int xx = rand() % 100;
            if (xx < 30) {
                int yy = rand()%12;
                a[yy] = rand();
            }
        }
        for (int i = 0; i < 12; ++i) printf("%d ", a[i]); printf("\n");
    }

    return 0;
}
