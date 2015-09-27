# include <bits/stdc++.h>
using namespace std;

int h, m;

int main()
{
    scanf("%d:%d", &h, &m);
    h%=12;
    cout << h*30+m*0.5 << ' ' << m*6 << endl;

    return 0;
}
