# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 1e5+5;

int n;

int pr[maxn*3];
int af[maxn*3];
int od[maxn*3];
int te[maxn*3];
int a[3][maxn];

void read(int &num) {
    scanf("%d", &num);
}

void write(int num) {
    printf("%d ", num);
}

int main()
{
    // cin.tie(0);
    // ios_base::sync_with_stdio(false);
    read(n);
    for (int i = 0; i < 3*n; ++i) {
        int x; read(x); od[x] =  i + 1;
    }
    for (int i = 0; i < n; ++i) {
        read(a[0][i]); read(a[1][i]); read(a[2][i]);
        te[ a[0][i] ] = te[ a[1][i] ] = te[ a[2][i] ] = i+1;
    }
    int ro;
    read(ro);

    int p = 0, q = 0;
    int tt = te[ro] - 1;
    if (od[ro]<=od[ a[0][tt] ] && od[ro]<=od[ a[1][tt] ] && od[ro]<=od[ a[2][tt] ]) {
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 3; ++j) if (a[j][i] != ro){
                if (i <= tt) {
                    if (i == tt) mx = max(mx, a[j][i]);
                    pr[p++] = a[j][i];
                } else {
                    af[q++] = a[j][i];
                }
            }
        }
        sort(pr, pr+p);
        for (int i = 0; i < p; ++i) {
            if (pr[i] <= mx) write(pr[i]);
            else af[q++] = pr[i];
        }
        sort(af, af+q);
        for (int i = 0; i < q; ++i) write(af[i]);
        puts("");
    } else {
        for (int i = 1; i <= 3*n; ++i) {
            if (i != ro) write(i);
        }
        puts("");
    }

    return 0;
}
