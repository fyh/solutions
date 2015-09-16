# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int N = 105;
const int M = 6*N;

int n;
char s[3][N], t[M], p[M];

int a[4] = {0,1,2,0};

void doit(char *str) {
    int i = 0;
    for (int j = 0; str[j]; ++j) {
        if (isalpha(str[j])) str[i++] = tolower(str[j]);
    }
    str[i] = 0;
}

bool chk() {
    p[0] = 0;
    strcat(p, s[ a[0] ]);
    strcat(p, s[ a[1] ]);
    strcat(p, s[ a[2] ]);
    return strcmp(p, t) == 0;
}

int main()
{
    cin >> s[0] >> s[1] >> s[2] >> n;
    doit(s[0]), doit(s[1]), doit(s[2]);
    while(n--) {
        cin >> t;
        doit(t);
        bool ok = false;
        do {
            if (chk()) {
                ok = true;
                a[0] = 0, a[1] = 1, a[2] = 2;
                break;
            }
        } while (next_permutation(a, a+3));
        cout << (ok ? "ACC":"WA") << endl;
    }

    return 0;
}
