# include <bits/stdc++.h>

char s[15];
char t[15];

int main()
{
    int it;
    scanf("%s%d", s, &it);
    sprintf(t, "%d", it);
    std::sort(s, s+strlen(s));
    int m = '9', mj;
    for (int i = 0; s[i]; ++i) {
        if (s[i]!='0' && m > s[i]) {
            m = s[i];
            mj = i;
        }
    }
    if (s[0] = '0') {
        std::swap(s[0], s[mj]);
    }

    if (strcmp(s, t) == 0) puts("OK");
    else puts("WRONG_ANSWER");

    return 0;
}
