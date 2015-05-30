# include <stdio.h>
# include <algorithm>

const int maxm = 105;
int mem[maxm];
int m;
int id;

int get_block(int i) {
    if (i<0 || i>=m) return -1;
    int ret = 0;
    while (i+ret<m && mem[i] == mem[i+ret]) ++ret;
    return ret;
}

void set_block(int st, int cnt, int x) {
    for (int i = 0; i < cnt; ++i) mem[st+i] = x;
}

int Alloc(int n) {
    if (n <= 0) return 0;
    for (int i = 0; i < m; ++i) {
        if (!mem[i] && get_block(i)>=n) {
            set_block(i, n, ++id);
            return id;
        }
    }
    return 0;
}

int Erase(int x) {
    if (x<=0 || x>id) return -1;
    bool ex = false;
    for (int i = 0; i < m; ++i) if (mem[i] == x) mem[i] = 0, ex = true;
    return ex ? 0:-1;
}

void Defrag(void) {
    for (int i = 0, j = 0; i < m && j < m; ) {
        if (mem[i]) ++i;
        else if (j<=i || !mem[j]) ++j;
        else {
            std::swap(mem[i++], mem[j++]);
        }
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);

    int t;
    scanf("%d%d", &t, &m);
    for (int it = 0; it < t; ++it) {
        char od[55]; scanf("%s", od);
        if (od[0] == 'a') {
            int n; scanf("%d", &n);
            int x = Alloc(n);
            if (!x) puts("NULL");
            else printf("%d\n", x);
        } else if (od[0] == 'e') {
            int x; scanf("%d", &x);
            if (Erase(x) < 0) puts("ILLEGAL_ERASE_ARGUMENT");
        } else {
            Defrag();
        }
    }
}
