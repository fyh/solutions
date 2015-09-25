# include <cstdio>
# include <iostream>
const int maxn = 1000005;
char s[maxn], t[maxn];
int main()
{
    while (/*scanf("%s%s", s, t) != EOF*/std::cin>>s>>t) {
        bool ans = true;
        int j = 0;
        for (int i = 0; s[i]; ++i) {
            while (t[j] && t[j]!=s[i]) ++j;
            if (!t[j]) {
                ans = false;
                break;
            } else {
                ++j;
            }
        }
        printf(ans ? "Yes\n":"No\n");
    }
    return 0;
}
