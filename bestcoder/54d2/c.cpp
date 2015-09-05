# include <iostream>
# include <vector>
# include <map>
# include <string.h>
using namespace std;

const int maxl = 5005;
const int maxn = 105;

int n;
char s[maxn][maxl];

bool isZero(char *str) {
    return (str[0] == '0' && str[1] == 0);
}

void rev(char *str) {
    int sn = strlen(str);
    int hl = sn / 2;
    for (int i = 0; i < hl; ++i) {
        swap(str[i], str[sn-1-i]);
    }
}

void trim(char *str) {
    if(strlen(str) == 1) return ;
    int x, y;
    for (int j = 0; str[j]; ++j) {
        if (str[j] != '0') {
            x = j;
            break;
        }
    }
    int ns = strlen(str);
    y = ns - 1;
    if (x >= y) {
        if (x == y) str[0] = str[x];
        else str[0] = '0';
        str[1] = 0;
    } else {
        for (int i = 0; i < y-x+1; ++i) {
            str[i] = str[x+i];
        }
        str[y-x+1] = 0;
        rev(str);
    }
}

char a[maxl];
char b[maxl];

void mul(int x, int y, char *str) {
    int nx = strlen(s[x]);
    int ny = strlen(s[y]);

    for (int i = 0; s[x][i]; ++i) {
        int carry = 0;
        for (int j = 0; s[y][j]; ++j) {
            int ca = s[x][i] - '0';
            int cb = s[y][j] - '0';
            int tmp  = ca * cb + carry;
            if (str[i+j] != 0) tmp += (str[i+j] - '0');
            str[i+j] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        int t = ny + i;
        while (carry > 0) {
            int tmp = carry;
            if (str[t] != 0) tmp += (str[t] - '0');
            str[t++] = tmp % 10 + '0';
            carry = tmp / 10;
        }
    }
}

bool chk(int x, int y, int z) {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));

    mul(y, y, a);
    mul(x, z, b);
    return strcmp(a, b) == 0;
}

void solve() {
    bool exZero = false;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        trim(s[i]);
        if (isZero(s[i])) exZero = true;
    }

    if (n == 1) cout << "Yes" << endl;
    else if (exZero) {
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (!isZero(s[i])) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "Yes":"No") << endl;
    } else if (n <= 2) cout << "Yes" << endl;
    else {
        bool ok = true;
        for (int i = 1; i+1 < n; ++i) {
            if (!chk(i-1, i, i+1)) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "Yes":"No") << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}
