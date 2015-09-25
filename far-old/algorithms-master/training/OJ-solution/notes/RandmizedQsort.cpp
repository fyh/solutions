# include <stdlib.h>
# include <time.h>

void swap(int * x, int * y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

// srand( time(NULL) );
int RandomizedPartion(int * arr, int p, int r)
{
    int t = rand()%(r-p+1)+p;
    swap(&arr[t], &arr[r]);
    int x = arr[r];
    int i = p-1;
    for (int j = p; j < r; ++j) {
        if (arr[j] <= x) {
            ++ i;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[r]);
    return i+1;
}

void RandomizedQsort(int * arr, int p, int r)
{
    if (r >= p) {
        int q = RandomizedPartion(arr, p, r);
        RandomizedQsort(arr, p, q-1);
        RandomizedQsort(arr, q+1, r);
    }
}


// test
# include <stdio.h>

int a[10005];
int main()
{
    freopen("data.in", "r", stdin);
    srand( time(NULL) );
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        RandomizedQsort(a, 0, n-1);
        for (int i = 0; i < n; ++i) printf("%d ", a[i]);
        printf("\n\n");
    }
}

