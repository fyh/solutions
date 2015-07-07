// # include <bits/stdc++.h>
# include <stdio.h>
# include <algorithm>

const int maxn = 1e7+5.0;

char isp[maxn];
int pt[700000], pn = 0;

void prep(void) {
    isp[1] = 1;
    for (int i = 2; i < maxn; ++i) {
        if (!isp[i]) {
            pt[pn++] = i;
            for (int j = 2; j*i < maxn; ++j) {
                isp[j*i] = 1;
            }
        }
    }
}

int main()
{
    prep();

    int n;
    while ((~scanf("%d", &n)) && n) {
      int t = std::lower_bound(pt, pt+pn, n) - pt;
      printf("%d\n", t);
    }

    return 0;
}
