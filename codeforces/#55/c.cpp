# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;

const int maxn = 3 * 105;

int n;
char s[maxn];

int m;
char a[maxn];

set<int> S;

int k;

void init() {
    cin >> k >> s;
    n = strlen(s);
    for (int i = 0; i < k; ++i) S.insert(i+'a');
    for (int i = 0, j = 0; s[j]; i += 2, ++j) {
        a[i] = '$';
        a[i+1] = s[j];
        S.erase((int)s[j]);
    }
    a[2*n] = '$';
    m = 2*n + 1;
}

void solve() {
    int mid = n;
    for (int i = 0; i <= n; ++i) {
        if (a[mid-i]!='?' && a[mid+i]!='?' && a[mid-i]!=a[mid+i]) {
            puts("IMPOSSIBLE");
            return ;
        } else if (a[mid-i]=='?' && a[mid+i]=='?') {
            int ch;
            if (!S.empty()) {
                ch = *(S.rbegin()); // cout << (char)ch << endl;
                S.erase(ch);
            } else ch = 'a';
            a[mid-i] = a[mid+i] = ch;
        } else if (a[mid+i]=='?' || a[mid-i]=='?') {
            a[mid-i] = a[mid+i] = (a[mid+i]+a[mid-i]-'?');
        }
    }
    if (S.size()) {
        puts("IMPOSSIBLE");
        return ;
    }
    for (int i = 0; i < m; ++i) {
        if (a[i] != '$') putchar(a[i]);
    }
    puts("");
}

int main()
{
    init();
    solve();

    return 0;
}
