typedef long long int lli;

const int maxn = 2005;

int hp,wp,hm,wm;

char cp[maxn][maxn];
char cm[maxn][maxn];

int main()
{
    while (cin >> hp >> wp >> hm >> wm) {
        for (int i = 0; i < hp; ++i) scanf("%s", cp[i]);
        for (int i = 0; i < hm; ++i) scanf("%s", cm[i]);
    }

    return 0;
}
