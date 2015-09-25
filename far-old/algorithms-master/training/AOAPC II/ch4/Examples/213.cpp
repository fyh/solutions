# include <cstdio>

# define testin freopen("in.txt", "r", stdin)

char str[256];

int mp[256];

int getKey(int len)
{
    int ret = 0;
    for (int i = 0, ch; i < len; ++i) {
        while (ch=getchar(), ch!='0'&&ch!='1') ;
        ret = ret*2 + ch-'0';
    }
    return ret;
}
int main()
{
    testin;
    while (gets(str) != NULL) {
        int key = 0, len = 1;
        for (int i = 0; str[i]; ++i) {
            mp[ key | (0x1<<len) ] = str[i];
            ++key;
            if (key+1 == (0x1<<len)) key = 0, ++len;
         }
         int t;
         while (t = getKey(3), t != 0) {
             int key;
             while ( key = getKey(t), key+1!=(0x1<<t) ) {
                 putchar( mp[key | (0x1<<t)] );
             }
         }
         getchar();
         putchar('\n');
    }

    return 0;
}
