// a 2d rabin karp matching variant
// TODO

typedef long long int lli;

const int maxc = 1e5+5;
const int maxk = 65;

const int hc = 5;
const int ph[] = {50331653, 6291469, 786433, 769, 193};  // http://planetmath.org/goodhashtableprimes

const int base = 10;

static int pm[hc][maxk];

int R, C;
int r, c;
std::map<char, int> mr;

void calc_pm() {
	for (int i = 0; i < hc; ++i) {
		pm[i][0] = 1;
		for (int j = 1; j < maxk; ++j) {
			pm[i][j] = (pm[i][j-1] * base) % ph[i];
		}
	}
}
void calc(char str[maxc][], TYPE hv[][maxr][maxc]) {
	for (int i = 0; i < w; ++i) {
		hv[0][i] = 0;
		for (int j = 0; j < r; ++j) {
			for (int k = 0; k < hc; ++k) {
				hv[k][0][i] = (base*hv[k][0][i] + mr[ str[j][i] ]) % ph[k];
			}
		}
		for (int j = 1; j+r <= R; ++j) {
			for (int k = 0; k < hc; ++k) {
				hv[k][j][i] = ((base*(h[k][j-1][i] - mr[ str[j-1][i] ]*pm[k][r]) + mr[ str[j+r-1][i]] ]) % ph[k] + ph[k]) % ph[k];
			}
		}
	}
	for (int i = 0; i + r <= R; ++i ) {
		for (int j = 1; j < c; ++j) {
			for (int k = 0; k < hc; ++k) {
				hv[k][i][0] = (base * hv[k][i][j-1] + hv[k][i][j]) % ph[k];
			}
		}
		for (int j = 1; j + c <= C; ++j) {
			for (int k = 0; k < hc; ++k) {
				hv[k][i][j] = base*(hv[k][i][j-1] - hv[i][j-1]*pm[k][c]) + hv[i][j+c-1];
				hv[k][i][j] = (hv[k][i][j]%hp[k] + hp[k]) % hp[k];
			}
		}
	}
}

const int maxn = maxc;

char t[maxn][maxn];
char p[maxn][maxn];

int ht[hc][maxn][maxn];
int hp[hc][maxn][maxn]; // TODO

void check() 
{
	calc(t, ht);
	calc(p, hp)
	for (int i = 0; i + r <= R; ++i) {
		for (int j = 0; j + c <= C; ++j) {
			bool ok = true;
			for (int k = 0; k < hc; ++k) {
				if (ht[k][i][j] != hp[k][0][0]) {
					ok = false;
					break;
				}
			}
			if (ok) {
				std::cout << "match case : (" << i << ", " << j << ")"  << std::endl;  // # include <iostream>
			}
		}
	}
}
