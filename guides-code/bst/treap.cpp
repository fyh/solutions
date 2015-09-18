// treap
// dynamic version

struct Node {
    int value;
    int key;
    Node *lson;
    Node *rson;
    Node(int v, int k) {
        value = v;
        key = k;
        lson = NULL;
        rson = NULL;
    }
};

int GetRand() {
    //
}

void RRotate(Node *&p) {
    Node *q = p->lson;
    p->lson = q->rson;
    q->rson = p;
    p = q;
}

void LRotate(Node *p) {
    Node *q = p->rson;
    p->rson = q->lson;
    q->lson = p;
    p = q;
}

Node* Insert(Node *p, int k) {
    if (!p) {
        p = new Node(k, getRand());
        return p;
    } else if (k < p->k) {
        Insert(p->lson, k);
        if (p->lson->value < p->value) {
            RRotate(p);
        }
    } else {
        Insert(p->rson, k);
        if (p->rson->value < p->value) {
            LRotate(p);
        }
    }
}

void Delete(Node *&p, int k) {
    if (k == p->key) {
        if (!p->lson || !p->rson) {
            Node *t = p;
            if (p->lson) p = p->lson;
            else p = p->rson;
            delete t;
        } else {
            if (p->lson->value < p->rson->value) {
                RRotate(p);
                Delete(p->rson, k);
            } else {
                LRotate(p)
                Delete(p->lson, k);
            }
        }
    } else if (k < p->key){
        Delete(p->left, k);
    } else {
        Delete(p->right, k);
    }
}
