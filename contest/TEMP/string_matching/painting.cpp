// The Big Painting
# include <string.h>
# include <stdio.h>
# include <iostream>

const int maxn = 2055;

int cp, rp, ct, rt;
char p[maxn][maxn];
char t[maxn][maxn];

int hp, ht[maxn][maxn];

bool match[maxn][maxn];

const int hc = 14;
const int hk[] = {98317, 2, 5, 7, 11, 17, 29, 53, 769, 3145739, 73079, 86433, 12582917, 50331653 };
int hpow[maxn];

const int base = 10;

bool first = true;

void init() {
	for (int i = 0; i < rp; ++i) scanf("%s", p[i]);
	for (int j = 0; j < rt; ++j) scanf("%s", t[j]);
}

int mr(char ch) {
    return ch;
    return ch=='x' ? 2:1;
}

void rkv2d() {
    if (first) first = false;
    else {
        for (int i = 0; i+cp <= ct; ++i) {
            for (int j = 0; j+rp <= rt; ++j) {
                match[j][i] = false;
            }
        }
    }
	for (int ica = 0; ica < hc; ++ica) {
		int hkey = hk[ica];
		hpow[0] = 1;
		int upper = cp>rp ? cp:rp;
		for (int i = 1; i < upper; ++i) hpow[i] = (hpow[i-1]*base)%hkey;

		hp = 0;
		for (int c = 0; c < cp; ++c) {
			int cur = 0;
			for (int r = 0; r < rp; ++r) {
				cur = (cur*base + mr(p[r][c])) % hkey;
			}
			hp = (hp * base + cur) % hkey;
		}

		// calc text
		for (int c = 0; c < ct; ++c) {
			for (int r = 0; r+rp <= rt; ++r) {
				if (!r) {
					ht[r][c] = 0;
					for (int i = 0; i < rp; ++i) {
						ht[r][c] = (ht[r][c]*base + mr(t[i][c])) % hkey;
					}
				} else {
					ht[r][c] = (ht[r-1][c]-hpow[rp-1]*mr(t[r-1][c]))*base + mr(t[r+rp-1][c]);
					ht[r][c] = (ht[r][c]%hkey + hkey) % hkey;
				}
			}
		}

		for (int r = 0; r+rp <= rt; ++r) {
			int pre = ht[r][0];
			for (int c = 0; c+cp <= ct; ++c) {
				if (!c) {
					int tmp = 0;
					for (int i = 0; i < cp; ++i) {
						tmp = (tmp*base + ht[r][i]) % hkey;
					}
					ht[r][c] = tmp;
				} else {
					int cur = ht[r][c];
					ht[r][c] = (((ht[r][c-1]-hpow[cp-1]*pre)*base + ht[r][c+cp-1])%hkey + hkey) % hkey;
					pre = cur;
				}
				if (ht[r][c] != hp) match[r][c] = true;
			}
		}
	}

	int cnt = 0;
	for (int r = 0; r+rp <= rt; ++r) {
		for (int c = 0; c+cp <= ct; ++c) {
			if (!match[r][c]) {
                bool fi = true;
                for (int i = 0; fi && i < std::min(rp,1003); ++i) {
                    for (int j = 0; fi && j < std::min(cp,1003); ++j) {
                        if (p[i][j] != t[r+i][c+j]) {
                            fi = false;
                        }
                    }
                }
                if (fi) ++cnt;
			}
		}
	}
	printf("%d\n", cnt);
}

int main()
{
  //  freopen("painting.in", "r", stdin);
    while (~scanf("%d%d%d%d", &rp, &cp, &rt, &ct)) {
        init();
        if (rp>rt || cp>ct) puts("0");
        else rkv2d();
    }

	return 0;
}
