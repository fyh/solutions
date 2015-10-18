# include <bits/stdc++.h>

typedef long long int lli;

lli po(lli a, lli n, lli m) {
    lli ans = 1;
    for (lli h = a; n > 0; n >>= 1, h = h*h%m) {
        if (n&0x1) ans = ans*h%m;
    }
    return ans;
}

bool miller_rabin(lli x, int MCNT = 30) {
    // error < 1-(1/4)^MCNT
    if (x < 2) return false;
    if (x%2 == 0) return x==2;
    if (x%3 == 0) return x==3;
    if (x%5 == 0) return x==5;
    for (int i = 1; i < MCNT; ++i) {
        if ( po(rand()%(x-1)+1,x-1,x) != 1) return false;
    }
    return true;
}


int main()
{
    for (int i = 0; i < 1e6; ++i) miller_rabin(i);

    return 0;
}
