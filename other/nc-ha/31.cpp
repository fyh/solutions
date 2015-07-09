# include <stdio.h>
# include <algorithm>

const int maxn = 1005;
const int maxd = 20005;

int co[maxn][2];
int H[maxn];
int d[maxn][2];
int r[maxn];

int N, X, Y, MAX, M;

bool cmp(const int &a, const int &b) {
    return H[a] > H[b];
}

int main()
{
  //  freopen("in.txt", "r", stdin);
    while (~scanf("%d%d%d%d", &N, &X, &Y, &MAX)) {
        for (int i = 1; i <= N; ++i) { scanf("%d%d%d", &co[i][0], &co[i][1], &H[i]); if (co[i][0]>co[i][1]) std::swap(co[i][0],co[i][1]); }
        co[0][0] = co[0][1] = X, H[0] = Y;
        co[N+1][0] = -maxd, co[N+1][1] = maxd, H[N+1] = 0;
        for (int i = 0; i < N+2; ++i) r[i] = i;
        std::sort(r, r+N+2, cmp);
        for (int i = 0; i <= N+1; ++i) d[i][0] = d[i][1] = 0x3FFFFFFF;
        d[0][0] = d[0][1] = 0;
        for (int ii = 0; ii <= N+1; ++ii) {
            int i = r[ii];
            for (int k = 0; k < 2; ++k) {
                for (int jj = ii+1; jj <= N+1; ++jj) {
                    int j = r[jj];
                    if (co[j][0]<=co[i][k]&&co[i][k]<=co[j][1]) {
                        if (H[i]<=H[j]+MAX) {
                            if (H[j] == 0) {
                                d[j][0] = std::min(d[j][0], H[i]-H[j]+d[i][k]);
                                d[j][1] = std::min(d[j][1], H[i]-H[j]+d[i][k]);
                            } else {
                                d[j][0] = std::min(d[j][0], co[i][k]-co[j][0]+H[i]-H[j]+d[i][k]);
                                d[j][1] = std::min(d[j][1], co[j][1]-co[i][k]+H[i]-H[j]+d[i][k]);
                            }
                        }
                        break;
                    }
                }
            }
        }
        printf("%d\n", d[N+1][1]);
    }
    return 0;
}
