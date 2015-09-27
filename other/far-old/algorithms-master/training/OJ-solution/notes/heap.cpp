// binary_heap for dijkstra
//

# include <cstdio>

const int maxv = 1005;
const int INF = 0x7FFFFFFF;

class node
{
public:
    int value;
    int key;
};

class bheap
{
    node h[maxv];
    int pos[maxv];
    int sz;
    bheap() { init(); }
public:
    void init(){ h[sz = 0].value = -INF; memset(pos+1, 0, sizeof(pos));}
    void insert(int key, int value) {
        node p = {value, key};
        int i, f;
        for (i = ++sz; p.value < h[f=i>>1].value; f = i) {
            h[i] = h[f];
            pos[h[i].key] = i;
        }
        h[i] = p;
        pos[h[i].key] = i;
    }
    void decrease(int key, int value){
        int i, f;
        node p = {key, value};
        for (i = pos[key]; p.value < h[f=i>>1]; i = f) {
            h[i] = h[f]; 
            pos[h[i].key] = i;
        }
        h[i] = p;
        pos[h[i].key] = i;
    }
    int extract_min(void){
        int i, c;
        int ret = h[1].key;
        node p = h[sz--];
        for (i = 1; (c=i<<1) <= sz; c = i) {
            if (c+1<=sz && h[c+1].value < h[c].value) ++c;
            if (h[c].value < p.value) {
                h[i] = h[c];
                pos[h[i].key] = i;
            } else break;
        }
        h[i] = p;
        pos[h[i].key] = i;
        return ret;
    }
};

bheap heap;
int dijkstra(int src, int dest)
{
    heap.init();
    heap.insert(src, 0);
    for ( ; ; ) {
        int x = extract_min();
        if (x == dest) return dist[x];
        for (int e = first[x]; ; e = next[e]) {
            relax();
        }
    }
}

int main()
{
    printf("INF = %d %x\n", INF, INF);
    printf("-INF = %d %x\n", -INF, -INF);

    return 0;
}

