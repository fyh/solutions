/*
Accepted	8156K	954MS	G++	1167B	2014-10-15 22:29:45

sparse table 

²Î¿¼£º http://poj.org/showmessage?message_id=341932
Íâ¹Ò£º http://blog.csdn.net/lyhvoyage/article/details/39780049
*/

# include <algorithm>
# include <cstdio>
# include <cctype>

const int maxn = 1000005;

int n, k;
int x[maxn], y[maxn];

int ReadInt()
{
    int ret = 0, flag = 1;
    char ch;
    while ((ch=getchar())!='-' && !isdigit(ch)) ;
    if (ch=='-') flag = -1;
    else if(isdigit(ch)) ret = ch - '0';
    while (isdigit(ch=getchar())) ret = ret*10 + ch-'0';
    return ret * flag;
}
void WriteInt(int x)
{
    if (x < 0) putchar('-'), x = -x;
    if (x>=10) WriteInt(x/10);
    putchar(x%10 + '0');
}

int main()
{
    while (scanf("%d%d", &n, &k) != EOF) {
        for (int i = 0; i < n; ++i) x[i] = ReadInt();
        for (int i = 0; i < n; ++i) y[i] = x[i];
        int j;
        for (j = 1; (j<<1) < k; j<<=1) {
            for (int i = 0; i+j < n; ++i) {
                x[i] = std::min(x[i], x[i+j]);
                y[i] = std::max(y[i], y[i+j]);
            }
        }
        for (int i = 0; i+k-1<n; ++i) {if(i) putchar(' '); WriteInt(std::min(x[i], x[i+k-j]));} putchar('\n');
        for (int i = 0; i+k-1<n; ++i) {if(i) putchar(' '); WriteInt(std::max(y[i], y[i+k-j]));} putchar('\n');
    }

    return 0;
}

