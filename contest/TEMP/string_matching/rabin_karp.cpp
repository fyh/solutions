// TODO : simplify

# include <iostream>
# include <string.h>
# include <stdio.h>

const int maxn = 1e5+5;

int tl, pl;
char t[maxn]; // text
char p[maxn]; // pattern

const int hc = 3;
const int hk[] = {786433, 12289, 769};
const int base = 10;

int hpow[hc][maxn];
int ph[hc];
int th[hc][maxn], pc;

void init(void)
{
    scanf("%s%s", t, p);
    tl = strlen(t);
    pl = strlen(p);
    for (int i = 0; i < tl; ++i) t[i] -= '0';
    for (int i = 0; i < pl; ++i) p[i] -= '0';
}

void rk()
{
    if (tl < pl) return ;
    memset(ph, 0, sizeof(ph));
    memset(th, 0, sizeof(th));
    for (int i = 0; i < pl; ++i) {
        for (int j = 0; j < hc; ++j) {
            if (!i) hpow[j][i] = 1;
            else hpow[j][i] = (hpow[j][i-1]*base)%hk[j];
        }
    }
    for (int i = 0; i < pl; ++i) {
        for (int j = 0; j < hc; ++j) {
            ph[j] = (ph[j]*base + p[i]) % hk[j];
            th[j][0] = (th[j][0]*base + t[i]) % hk[j];
        }
    }

    for (int i = 1; i+pl <= tl; ++i) {
        for (int j = 0; j < hc; ++j) {
            int &cur = th[j][i];
            cur = (th[j][i-1]-t[i-1]*hpow[j][pl-1])*base + t[i+pl-1];
            cur = (cur%hk[j] + hk[j]) % hk[j];
        }
    }

    for (int i = 0; i+pl < tl; ++i) {
        bool fi = true;
        for (int j = 0; j < hc; ++j) {
            if (ph[j] != th[j][i]) {
                fi = false;
                break;
            }
        }
        if (fi) {
            std::cout << i << std::endl;
        }
    }
}

int main()
{
    init();
    rk();

    return 0;
}
