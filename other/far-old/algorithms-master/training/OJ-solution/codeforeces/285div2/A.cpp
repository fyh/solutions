# include <iostream>
# include <algorithm>
# include <stdio.h>
int cal(int x, int y)
{
    return std::max(3*x/10, x-x*y/250);
}
int main()
{
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    if (cal(a, c) > cal(b, d)) puts("Misha");
    else if (cal(a, c) < cal(b, d)) puts("Vasya");
    else puts("Tie");
    return 0;
}
