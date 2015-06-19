# include <bits/stdc++.h>

int w, m;

int n = 0;
int a[105];

int main()
{
    scanf("%d%d", &w, &m);
    while (m > 0) {
        a[n] = m % w;
        m /= w;
        ++n;
    }

    bool ok = true;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0 || a[i] == 1) continue;
        if (a[i] == w-1 || a[i] == w) {
            ++a[i+1];
            continue;
        }
        ok = false;
        break;
    }
    puts(ok ? "YES":"NO");


    return 0;
}
