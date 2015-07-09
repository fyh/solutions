# include <stdio.h>
# include <ctype.h>
# include <iostream>

typedef long long int lli;

int n;
char ops[55];
int opt[55];
lli s[55], top;

lli get(lli x, lli y, int ch)
{
    switch (ch)
    {
    case '+':
        return x + y;
        break;
    case '-':
        return x - y;
        break;
    case '*':
        return x * y;
        break;
    case '/':
        return x / y;
        break;
    default:
        break;
    }
    return 0;
}

int main()
{
    while (~scanf("%d", &n))
    {
        top = 0;
        char str[15];
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", str);
            if (isdigit(str[0]))
            {
                sscanf(str, "%d", &opt[i]);
                ops[i] = 0;
            }
            else
            {
                ops[i] = str[0];
            }
        }

        for (int i = n-1; i >= 0; --i)
        {
            if (ops[i])
            {
                int x = s[top-1];
                --top;
                int y = s[top-1];
                --top;
                s[top++] = get(x,y,ops[i]);
            }
            else
            {
                s[top++] = opt[i];
            }
        }
        std::cout << s[top-1] << std::endl;
    }

    return 0;
}
