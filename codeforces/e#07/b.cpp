# include <bits/stdc++.h>

using namespace std;

int main()
{
    int h, m, a;
    scanf("%d:%d", &h, &m);
    cin >> a;

    a += h*60 + m;
    a %= 3600;

    printf("%02d:%02d\n", a/60%24, a%60);

    return 0;
}
