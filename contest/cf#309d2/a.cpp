# include <bits/stdc++.h>

# define testin freopen("in.txt", "r", stdin)

const int maxn = 25;

int len;
char str[maxn];

const int MOD = 31;

std::map<int,bool> mp;

int main()
{
    testin;

    int ans = 0;

    scanf("%s", str);

    len = strlen(str);
    for (int i = 0; i <= len; ++i) {
        for (int j = 0; j < 26; ++j) {
            int h = 0;
            for (int k = 0; k <= len; ++k) {
                h = h * MOD;
                if (k == i) h += j + 'a';
                else if (k < i) h += str[k];
                else h += str[k-1];
            }
            if (!mp[h]) ++ans, mp[h] = true;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
