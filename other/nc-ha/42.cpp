# include <stdio.h>
# include <algorithm>

const int maxn = 1005;

int n;
int a[maxn];
int b[maxn];

bool jd(void) {
    int t = n/2 + 1;
    for (int i = n-t, j = 0; j < t; ++i, ++j) {
        if (a[i] <= b[j]) {
            return false;
        }
    }
    return true;
}

void read(int *v) {
    for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
    std::sort(v, v+n);
}

int main()
{
    while ((~scanf("%d", &n)) && n) {
        read(a);
        read(b);
        puts(jd() ? "YES":"NO");
    }

    return 0;
}
