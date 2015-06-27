# include <bits/stdc++.h>
# define testin freopen("in.txt", "r", stdin)

using namespace std;

const int maxn = 1005;

int n;
int a[maxn];

void mov() {
    for (int i = 0; i < n; ++i) {
        if (i&0x1) {
            a[i] = (a[i]+n-1)%n;
        } else {
            a[i] = (a[i]+1)%n;
        }
    }
}

bool jd() {
    for (int i = 0; i < n; ++i) {
        if (a[i] != i) return false;
    }
    return true;
}

int main()
{
    // testin;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    bool ok = false;
    for (int i = 0; i < 3*n; ++i) {
        if (jd()) {
            ok = true;
            puts("Yes");
            break;
        }
        mov();
    }
    if (!ok) puts("No");

    return 0;
}
