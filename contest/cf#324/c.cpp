# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 1e5+5;

int n, t;
char s1[maxn], s2[maxn];
int st1[maxn], t1;
int st2[maxn], t2;
char str[maxn];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> t >> s1 >> s2;

    for (int i = 0; i < n; ++i) {
        if (s1[i] == s2[i]) st1[t1++] = i;
        else st2[t2++] = i;
    }

    t = n - t;

    int up = t1 + t2/2;
    if (t > up) puts("-1");
    else {
        for (int i = 0; i < t1; ++i) {
            int ch = s1[ st1[i] ];
            if (i < t) str[st1[i]] = ch;
            else str[st1[i]] = (ch == 'a' ? 'b' : 'a');
        }
        if (t > t1) t -= t1;
        else t = 0;
        for (int i = 0; i < t2; ++i) {
            int j = st2[i];
            if (i < t) str[j] = s1[j];
            else if (i < 2*t) str[j] = s2[j];
            else {
                for (int k = 'a'; k <= 'z'; ++k) {
                    if (k!=s1[j] && k!=s2[j]) {
                        str[j] = k;
                        break;
                    }
                }
            }
        }
        str[n] = 0;
        puts(str);
    }

    return 0;
}
