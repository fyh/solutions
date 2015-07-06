# include <bits/stdc++.h>

const int maxm = 25;

int n, m;
int a[maxm], b[maxm];
int r[maxm];

bool cmp(const int x, const int y) {
    return b[x] > b[y];
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        r[i] = i;
    }
    std::sort(r, r+m, cmp);

    int ans = 0;
    int left = n;
    int i = 0;
    while (left > 0 && i < m) {
        if (left > a[ r[i] ]) {
            ans += a[ r[i] ] * b[ r[i] ];
            left -= a[ r[i] ];
            ++i;
        } else {
            ans += left * b[ r[i] ];
            left = 0;
        }
    }
    printf("%d\n", ans);

    return 0;
}
