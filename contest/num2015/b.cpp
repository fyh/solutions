# include <stdio.h>
# include <string.h>
# include <iostream>
# include <algorithm>
# include <vector>
# include <map>
# include <set>
using namespace std;
typedef long long int lli;

char s[1005];
char st[1005];
int top;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int T; cin >> T;
    while (T--) {
        scanf("%s", s);
        top = 0;
        for (int i = 0; s[i]; ++i) {
            if (s[i] == '#') top = max(0, top-1);
            else if (s[i] == '@') top = 0;
            else {
                st[top++] = s[i];
            }
        }
        for (int i = 0; i < top; ++i) {
            putchar(st[i]);
        }
        cout << endl;
    }

    return 0;
}
