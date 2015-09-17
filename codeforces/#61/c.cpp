# include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

class Node {
public:
    string st;
    vector<Node*> ve;
    Node(string str) {st = str;}
    Node *FindChild(string str) {
        for (auto it = ve.begin(); it != ve.end(); ++it) {
            if ((*it)->st == str) return *it;
        }
        return NULL;
    }
    Node *AddChild(string str) {
        Node *ret = FindChild(str);
        if (ret == NULL) {
            ret = new Node(str);
            ve.push_back(ret);
        }
        return ret;
    }
};


char s[105];

void Get(Node *cur, int &c1, int &c2) {
    if ((cur->ve).empty()) {
        ++c2;
    } else {
        ++c1;
        for (int i = 0; i < (cur->ve).size(); ++i) {
            Get((cur->ve)[i], c1, c2);
        }
    }
}

char tmd[105];

int main()
{
    //freopen("in.txt", "r", stdin);
 //   freopen("out.txt", "w", stdout);

    Node *root = new Node("#");
    while (scanf("%s", s) != EOF) {
        int len = strlen(s);
        for (int i = 0; s[i]; ++i) {
            if (s[i] == '\\') s[i] = 0;
        }
        Node* p = root;

        char *t = s;
        while (sscanf(t, "%s", tmd) != EOF) {
            p->AddChild(tmd);
            p = p->FindChild(tmd);
            t += strlen(tmd) + 1;
            if (t-s >= len) break;
        }
    }
    int cfo = 0, cfi = 0;
    for (int i = 0; i < (root->ve).size(); ++i) {
        Node * ttmp = (root->ve)[i];
        for (int j = 0; j < (ttmp->ve).size(); ++j) {
            int c1 = 0, c2 = 0;
            Get((ttmp->ve)[j], c1, c2);
            cfo = max(c1-1, cfo);
            cfi = max(c2, cfi);
        }
    }
    cout << cfo << ' ' << cfi << endl;

    return 0;
}
