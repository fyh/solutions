# include <string.h>

# define TEST

# ifdef TEST
	# include <iostream>
# endif 

const int maxn = 1e3+5;

int cp, rp, ct, rt;
char p[maxn][maxn];
char t[maxn][maxn];

int hp, ht[maxn][maxn];

bool match[maxn][maxn];

const int hc = 5;
const int hk[] = {50331653, 6291469, 786433, 769, 193};
int hpow[maxn];

const int base = 10;


void init() {
	
}

int mr(char ch) {
	return ch;
}

void rkv2d() {
	memset(match, true, sizeof(match));
	memset(ht, 0, sizeof(ht));
	
	for (int ica = 0; ica < hc; ++ica) {
		int hkey = hk[ica];
		hpow[0] = 1;
		int upper = cp>rp ? cp:rp;
		for (int i = 1; i < upper; ++i) hpow[i] = (hpow[i-1]*base)%hkey;
		
		// calc pattern
		hp = 0;
		for (int c = 0; c < cp; ++c) {
			int cur = 0;
			for (int r = 0; r < rp; ++r) {
				cur = (cur*base + mr(p[r][c])) % hkey;
			}
			hp = (hp * base + cur) % hkey;
		}
# ifdef TEST
		std::cout << hp << std::endl;
# endif
		// calc text
		for (int c = 0; c < ct; ++c) {
			for (int r = 0; r+rp <= rc; ++r) {
				if (!r) {
					ht[r][c] = 0;
					for (int i = 0; i < rc; ++i) {
						ht[r][c] = (ht[r][c]*base + mr(t[i][c])) % hkey;
					}
				} else {
					ht[r][c] = (ht[r-1][c]-hpow[rp-1]*mr(t[r-1][c]))*base + mr(t[r][c]);
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
					ht[r][c] = (ht[r][c-1]-hpow[cp-1]*pre)*base + cur;
					ht[r][c] = (ht[r][c]%hkey + hkey) % hkey;
					pre = cur;
				}
				if (h[r][c] != hp) match[r][c] = false;
			}
		}
	}
	
	int cnt = 0;
	for (int r = 0; r+rp <= rt; ++r) {
		for (int c = 0; c+cp <= ct; ++c) {
			if (match[r][c]) {
				++cnt;
				std::cout << r << ", " << c << std::endl;
			}
		}
	}
}
