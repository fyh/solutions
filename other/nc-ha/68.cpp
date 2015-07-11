# include <stdio.h>
# include <string.h>
# include <iostream>

char s[200005];
long long int n;

int main()
{
    while (~scanf("%s", s)) {
        std::cin >> n;
        int m = strlen(s);
        n = (-n%m+m) % m;
        for (int i = 0; i < m; ++i) {
            putchar( s[(i+n+m)%m] );
        }
        putchar('\n');
    }

    return 0;
}
