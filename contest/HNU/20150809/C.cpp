// bf
# include <stdio.h>
# include <string.h>
# include <algorithm>
using namespace std;

const int maxn = 200005;

int n, m;
bool ig[maxn];
bool im[maxn];
int kk[maxn];

int main()
{
    while (scanf("%d", &n) != EOF) {
        memset(ig, false, sizeof(ig));
        memset(im, false, sizeof(im));
        for (int i = 0; i < n; ++i) {
            scanf("%d", &kk[i]);
            im[ kk[i] ] = true;
        }
        sort(kk, kk + n);
        scanf("%d", &m);
        int ans = 0;
        for (int i = 0, x; i < m; ++i) {
            scanf("%d", &x);
            if (im[x] || ig[x]) ++ans;
            else {
                for (int j = 0; j < n && kk[j] < x; ++j) {
                    int* k = lower_bound(kk+j, kk+n, x-kk[j]);
                    if (*k == x-kk[j]) {
                        ig[x] = true;
                        ++ans;
                        break;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
