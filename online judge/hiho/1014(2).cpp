# include <bits/stdc++.h>
using namespace std;

const int maxa = 26+1;
const int maxn = 1e3+5;
const int maxl = 11;

class Node {
public:
    Node *next[maxa];
    int cnt;
    Node() : cnt(0) {
        memset(next, 0, sizeof(next));
    }
};

Node arr[maxn];
int Id = 0;
Node *NewNode() {
    if (Id >= maxn) return new Node();
    return &arr[Id++];
}

Node *root = NewNode();

void add(char *s) {
    Node *fa = root;
    for (int i = 0; s[i]; ++i) {
        int c = s[i] - 'a';
        Node* cur = fa->next[c];
        if (!cur) {
            cur = NewNode();
            fa->next[c] = cur;
        }
        ++ cur->cnt;
        fa = cur;
    }
}

int query(char *s) {
    Node *fa = root;
    for (int i = 0; s[i]; ++i) {
        int c = s[i] - 'a';
        Node *cur = fa->next[c];
        if (!cur) return 0;
        fa = cur;
    }
    return fa->cnt;
}

int n, m;
char s[15];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        add(s);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%s", s);
        printf("%d\n", query(s));
    }

    return 0;
}

