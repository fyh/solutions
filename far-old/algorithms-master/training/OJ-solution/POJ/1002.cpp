// 18:43
# include <stdio.h>
# include <ctype.h>
# include <string.h>

class node {
public:
    int cnt;
    node * next[10];
    node() {
        cnt = 0;
        memset(next, 0, sizeof(next));
    }
};

class trie {
public:
    node * root;
    bool existDup;
    trie() {
        existDup = false;
        root = NULL;
    }
    void insert(char *s) {
        if (root == NULL) root = new node;
        node * p = root;
        for (int i = 0; i < 7; ++i) {
            if ( p->next[ s[i]-'0' ] == NULL ) {
                p->next[ s[i]-'0' ] = new node;
            }
            p = p->next[ s[i]-'0' ];
        }
        ++ p->cnt;
    }
    void dfsPrint(node *p, int level, char *ans) {
        if (level >= 7) {
            if (p->cnt > 1) {
                existDup = true;
                for (int i = 0; i < 7; ++i) {
                    printf("%c", ans[i]);
                    if (i==2) printf("-");
                }
                printf(" %d\n", p->cnt);
            }
            return ;
        }
        for (int i = 0; i < 10; ++i) {
            if ( p->next[i] != NULL ) {
                ans[level] = i+'0';
                dfsPrint(p->next[i], level+1, ans);
            }
        }
    }
    void printAns(void) {
        node * p = root;
        char sol[10];
        dfsPrint(p, 0, sol);
        if (existDup == false) printf("No duplicates. \n");
    }
};

trie tr;

char charMp(char ch)
{
    if (isdigit(ch)) return ch;

    if (ch <= 'C') return '2';
    if (ch <= 'F') return '3';
    if (ch <= 'I') return '4';
    if (ch <= 'L') return '5';
    if (ch <= 'O') return '6';
    if (ch <= 'S') return '7';
    if (ch <= 'V') return '8';
    return '9';
}

int main()
{
    int n;
    scanf("%d", &n);
    char tm[55];
    for (int i = 0; i < n; ++i) {
        scanf("%s", tm);
        for (int i = 0, j = 0; tm[i]; ++i) {
            if (isdigit(tm[i]) || isalpha(tm[i])) {
                tm[j++] = tm[i];
            }
        }
        for (int i = 0; i < 7; ++i) {
            tm[i] = charMp( tm[i] );
        }
        tr.insert(tm);
    }
    tr.printAns();

    return 0;
}
