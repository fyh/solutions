# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int a;
char b[5];
char c[1005];
lli A, B, C;

void put(lli num, int base) {
    if (num > 0) {
        put(num/base, base);
        int t = num % base;
        if (t >= 10) cout << (char)(t-10+'A');
        else cout << t;
    }
}

lli get() {
    lli ret = 0;
    for (int i = 0; c[i]; ++i) {
        if (isdigit(c[i])) ret = ret*a + (c[i]-'0');
        else ret = ret*a + (c[i]-'A'+10);
    }
    return ret;
}

void putx(char ch, int num) {
    for (int i = 0; i < num; ++i) putchar(ch);
}

int main()
{
    cin >> a >> b >> c;
    C = get();
    if (b[0] != 'R') {
        B = 0;
        for (int i = 0; b[i]; ++i) {
            B = B*10 + (b[i]-'0');
        }
        if(C != 0) put(C, B);
        else cout << 0;
    } else {
        int x = C / 1000;
        C %= 1000;
        putx('M', x);
        x = C / 100; C %= 100;
        if (x == 9) cout << "CM";
        else {
            if (x >= 5) x-=5, putx('D', 1);
            if (x <= 3) putx('C', x);
            else if (x == 4) cout << "CD";
        }
        x = C / 10;
        C %= 10;
        if (x == 9) cout << "XC";
        else {
            if (x >= 5) x-=5, putx('L', 1);
            if (x <= 3) putx('X', x);
            else cout << "XL";
        }
        x = C % 10;
        if (x == 9) cout << "IX";
        else {
            if (x >= 5) x-=5, putx('V', 1);
            if (x <= 3) putx('I', x);
            else cout << "IV";
        }
    }
    cout << endl;

    return 0;
}
