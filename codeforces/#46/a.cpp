# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

char last;

void jd(void) {
    switch(last) {
        case 'a':case 'e':case 'y':case 'o':case 'u':case 'i': cout << "YES" << endl; break;
        default: cout << "NO" << endl;
    }
}

int main()
{
    int ch;
    while ((ch = getchar()) != EOF) {
        if (isalpha(ch)) {
            last = tolower(ch);
        }
    }

    jd();

    return 0;
}
