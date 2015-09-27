#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
typedef unsigned long long ULL;
const ULL INF = ~0ULL;

int p[] = {2,3,5,7,11,13,17,19,23, 29};

int n;
ULL ans;

void dfs(int dept,ULL tmp,int num)
{
    if(num > n) return;
    if(num == n && ans > tmp) ans = tmp;
    for(int i=1;i<=63;i++)
    {
        if(ans / p[dept] < tmp) break;
        dfs(dept+1,tmp *= p[dept],num*(i+1));
    }
}

int main()
{
    while(cin>>n)
    {
        ans = INF;
        dfs(0,1,1);
        cout<<ans<<endl;
    }

    return 0;
}
