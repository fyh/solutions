# include <bits/stdc++.h>

int Y, W;

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a%b);
}

int main()
{
    std::cin >> Y >> W;
    int t = 7 - std::max(Y, W);
    std::cout << t / gcd(t,6) << "/" << 6 / gcd(t,6);

    return 0;
}
