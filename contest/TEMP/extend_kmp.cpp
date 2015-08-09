
const int maxn = 1000005;
int ans[maxn];
int next[maxn];

void extend_kmp(char *text, char *pattern)
{
    int a, p;
    int n = strlen(text);
    int m = strlen(pattern);
    for (int i = 0; text[i]; ++i) {
        int L = next[i-a+2];
        if (i+L < p) {
            ans[i] = L;
        } else {
            int j = 0;
            while (i+L+j<n && L+j<m && text[i+L+j] == pattern[L+j]) {
                ++j;
            }
            L += j;
            ans[i] = L;
            if (i+L > p) {
                a = i;
                p = i + L;
            }
        }
    }
}
