# include <cstdlib>
# include <ctime>
# include <cstdio>

# define testout freopen("in.txt", "w", stdout)

int main()
{
    testout;
    int N, k, m;

    for (int i = 0; i < 100; ++i) {
        N = rand() % 20 + 1;
        k = rand() % N + 1;
        m = rand() % N + 1;
        printf("%d %d %d\n", N, k, m);
    }
    printf("0 0 0\n");

    return 0;
}
