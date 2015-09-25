// 19:13
# include <stdio.h>
# include <ctype.h>
# include <time.h>
# include <stdlib.h>
# include <algorithm>
int a[100005];
int getInt(char *s) {
    int ret = 0;
    for (int i = 0; s[i]; ++i) {
        if (isdigit(s[i])) ret = ret*10 + s[i]-'0';
        else if (isalpha(s[i])) {
            ret = ret*10;
            if (s[i]<='O') ret += (s[i]-'A')/3+2;
            else if (s[i]<='S') ret += 7;
            else if (s[i]<='V') ret += 8;
            else ret += 9;
        }
    }
    return ret;
}
int rpartion(int *arr, int r)
{
    if (r <= 0) return 0;
    int t = rand()%(r+1);
    if (t^r) std::swap(arr[t], arr[r]);
    int x = arr[r];
    int i = -1;
    for (int j = 0; j < r; ++j) {
        if (arr[j]<=x && ++i!=j) {
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[++i], arr[r]);
    return i;
}
void rqsort(int *arr, int n)
{
    if (n>1) {
        int x = rpartion( arr, n-1 );
        rqsort(arr, x);
        rqsort(arr+x+1, n-x-1);
    }
}
int main()
{
    srand(time(NULL));
    int n;
    char s[55];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        a[i] = getInt(s);
    }
    rqsort(a, n);
    bool exist = false;
    for (int i = 0; i < n; ++i) {
        int c = 1;
        while (i+1 < n && a[i] == a[i+1]) ++c, ++i;
        if (c > 1) printf("%03d-%04d %d\n", a[i]/10000, a[i]%10000, c), exist = true;
    }
    if (exist == false) printf("No duplicates.\n");

    return 0;
}
