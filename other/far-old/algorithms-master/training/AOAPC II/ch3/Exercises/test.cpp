#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <map>
#define maxn 100000 + 10
#define INF 0x7fffffff
using namespace std;
struct NODE
{
    int h, w;
    bool operator < (const NODE& rha) const{
        if(h == rha.h) return w < rha.w;
        return h < rha.h;
    }
}a[10];
bool ok()
{
    if(a[0].h != a[1].h || a[0].w != a[1].w) return false;
    if(a[2].h != a[3].h || a[2].w != a[3].w) return false;
    if(a[4].h != a[5].h || a[4].w != a[5].w) return false;
    if(a[1].h != a[2].h) return false;
    if(a[1].w != a[4].h) return false;
    if(a[3].w != a[4].w) return false;
    return true;
}
int main()
{
    freopen("in.txt", "r", stdin);
 //   freopen("outc.txt", "w", stdout);
    while(scanf("%d%d", &a[0].h, &a[0].w) != EOF)
    {
        if(a[0].h > a[0].w) swap(a[0].h, a[0].w);
        for(int i = 1; i < 6; ++i)
        {
            scanf("%d%d", &a[i].h, &a[i].w);
            if(a[i].h > a[i].w) swap(a[i].h, a[i].w);
        }
        sort(a, a+6);
        if(ok()) puts("POSSIBLE");
        else puts("IMPOSSIBLE");
    }
    return 0;
}
