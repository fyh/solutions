# include <stdio.h>
# include <algorithm>

const int maxn = 1e6+5;
int n;
int a[maxn];
int l[maxn];
int r[maxn];
int c[maxn];
int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int *p = std::max_element(a, a+n);
    a[n] = *p;
    std::rotate(a, p, a+n);
    for (int i = n-1; i >= 0; --i) {
        r[i] = i + 1;
        while (r[i]<n && a[i]>a[r[i]]) {
            r[i] = r[r[i]];
        }
        c[i] = 0;
        if (r[i]<n && a[i] == a[r[i]]) {
            c[i] = c[r[i]] + 1;
            r[i] = r[r[i]];
        }
    }
    for (int i = 1; i < n; ++i) {
        l[i] = i - 1;
        while (l[i]>=0 && a[i]>a[l[i]]) {
            l[i] = l[l[i]];
        }
        if (a[i] == a[l[i]]) l[i] = l[l[i]];
    }
    long long int ans = 0;
    for (int i = 1; i < n; ++i) {
        ans += c[i];
        if (l[i]==0 && r[i]==n) {
            ans += 1;
        } else ans += 2;
    }

    printf("%I64d\n", ans);

    return 0;
}

