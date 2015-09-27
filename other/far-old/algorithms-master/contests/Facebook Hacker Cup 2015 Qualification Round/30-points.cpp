# include <stdio.h>

# define setin  freopen("new_years_resolution.txt", "r", stdin);
# define setout freopen("out.txt", "w", stdout);

const int maxn = 25;
int N;
int Gp, Gc, Gf;
int P[maxn], C[maxn], F[maxn];

int main()
{
    setin;
    setout;

    int T;
    scanf("%d", &T);
    for (int ica = 1; ica <= T; ++ica) {
        scanf("%d%d%d", &Gp, &Gc, &Gf);
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            scanf("%d%d%d", &P[i], &C[i], &F[i]);
        }
        bool ans = false;
        for (int i = 0; i < (0x1<<N); ++i) {
            int sp = 0, sc = 0, sf = 0;
            for (int j = 0; j < N; ++j) {
                if ((i>>j)&0x1) {
                    sp += P[j];
                    sc += C[j];
                    sf += F[j];
                }
            }
            if (sp == Gp && sc==Gc && sf==Gf) {
                ans = true;
                break;
            }
        }
        printf("Case #%d: %s\n", ica, ans==true?"yes":"no");
    }

    return 0;
}
