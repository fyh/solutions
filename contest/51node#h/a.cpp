#include <cstdio>
#include <map>

int T;
int n;
int a[55*2];
std::map<int,int> mp;
int x[55*2], y[55*2], tx, ty;

int main()
{
    freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    for (int ica = 1; ica <= T; ++ica) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        tx = ty = 0;
        mp.clear();
        for (int i = 0; i < n; ++i) {
            if (mp[a[i]]%2==0) {
                x[tx++] = a[i];
            } else {
                y[ty++] = a[i];
            }
            ++mp[ a[i] ];
        }
        bool ok = true;
        if (tx != ty) ok = false;
        for (int i = 0; i < tx && ok; ++i) {
            if (x[i] != y[i]) ok = false;
        }
        if (!ok) puts("What a pity!");
        else puts("Good job!!");
    }

    return 0;
}
