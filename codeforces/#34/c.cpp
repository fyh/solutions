# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int maxn = 1005;

bool p[maxn];

void init() {
    int ch;
    int cur = 0;
    while ( (ch=getchar()) != EOF ) {
        if (isdigit(ch)) {
            cur = cur*10 + (ch-'0');
        } else {
            if (cur) p[cur] = true;
            cur = 0;
        }
    }
}

int main()
{
    init();

    int c = 0;
    bool first = true;
    for (int i = 1; i < maxn; ++i) {
        if (!p[i]) {
            if (c > 1) cout << '-' << i-1;
            c = 0;
        } else {
            if (!c) {
                if (first) first = false;
                else cout << ',' ;
                cout << i;
            }
            ++c;
        }
    }
    cout << endl;

    return 0;
}
