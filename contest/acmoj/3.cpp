# include <stdio.h>

const int maxn = 10005;

int n;
int a[maxn];
int sum[maxn];
int p[maxn];

int get(int x) {
	return x==p[x] ? x:p[x]=get(p[x]);
}

int lb(int x) {
	return x & -x;
}

void add(int x, int dx) {
	for (; x < maxn; x += lb(x)) {
		sum[x] += dx;
	}
}

int getsum(int r) {
	int ret = 0;
	for (int i = r; i >= 0; i -= lb(i)) {
		ret += sum[i];
	}
	return ret;
}

int main()
{
	freopen("in.txt", "r", stdin);

	int T;
	scanf("%d", &T);
	for (int ica = 1; ica <= T; ++ica) {
		printf("Case #%d:\n", ica);
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			p[i] = i;
			if (a[i] == 1) p[i] = i + 1;
			sum[i] = a[i];
		}
		p[n] = n;
		p[n + 1] = n + 1;
		int k;
		scanf("%d", &k);
		for (int i = 0; i < k; ++i) {
			int q, l, r;
			scanf("%d%d%d", &q, &l, &r);
			if (!q) {
				int x = l;
				while ((x=get(x)) <= r) {
					int t = a[x] * a[x];
					if (t >= 1000) {
						t = 1000;
						p[x] = x + 1;
					}
					if (t != a[x]) {
                        a[x] = t;
                        add(x, t - a[x]);
					}
					x = x + 1;
				}
			} else {
				printf("%d\n", getsum(r) - getsum(l) + a[l]);
			}
		}
	}

	return 0;
}
