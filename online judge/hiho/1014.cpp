# include <bits/stdc++.h>
using namespace std;

const int maxa = 26+5;

class Node {
public:
    Node *next[maxa];
    int cnt;
    Node() : cnt(0) {
        memset(next, 0, sizeof(next));
    }
};

Node *root = new Node();

void add(char *s) {
    Node *fa = root;
    for (int i = 0; s[i]; ++i) {
        int c = s[i] - 'a';
        Node* cur = fa->next[c];
        if (!cur) {
            cur = new Node();
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
