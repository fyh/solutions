# include <iostream>
# include <cstring>

const int maxn = 1000005;
int pi[maxn];

int kmp(char *t, char *p)
{
	int m = strlen(p);
	int k = 0;
	pi[0] = k;
	for (int i = 1; i < m; ++i) {
		while (k>0 && p[i]!=p[k]) k = pi[k];
		if (p[i] == p[k]) ++k;
		pi[i] = k;
	}
	int q = 0;
	for (int i = 0; t[i]; ++i) {
		while (q>0 && t[i]!=p[q]) q = pi[q];
		if (t[i] == p[q]) ++q;
		if (q == m) {
			return i+1-m;
		}
	}
	// pattern string is empty!
	if (!m) return 0;
	// no match exist!
	return -1;
}

int main()
{
	std::cout << kmp("ababcababac", "ababa") << std::endl;
	std::cout << kmp("ababcbabac", "ababa") << std::endl;
	std::cout << kmp("", "ababa") << std::endl;
	std::cout << kmp("", "") << std::endl;

	return 0;
}
