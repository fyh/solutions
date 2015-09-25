# include <time.h>
# include <stdlib.h>

void swap(int * x, int * y)
{
     int t = *x;
     *x = *y;
     *y = t;
}

int RandomizedPartion(int * arr, int p, int r)
{
     int t = rand()%(r-p+1) + p;
     swap( &arr[t], &arr[r] );
     int x = arr[r];
     int i = p-1, j;
     for (j = p; j < r; ++j) {
          if (arr[j] <= x) {
               ++ i;
               swap( &arr[i], &arr[j] );
          }
     }
     swap( &arr[i+1], &arr[r] );
     return i+1;
}

int RandomizedSelect(int * arr, int p, int r, int i)
{
//     if (i > r-p+1) return -1;
     if (p == r) return arr[p];
     int q = RandomizedPartion( arr, p, r );
     int k = q - p + 1;
     if (k == i) return arr[q];
     else if (i < k) return RandomizedSelect( arr, p, q-1, i);
     else RandomizedSelect( arr, q+1, r, i-k );
}

// example
# include <stdio.h> 

int main()
{
     srand(time(NULL));
     int a[] = {2, 1, 2, 3, 5, 6};
     int i;
     for (i = 1; i <= 6; ++i) printf( "%d : %d\n", i, RandomizedSelect( a, 0, 5, i ) );
     for (i = 0; i < 6; ++i) printf("%d ", a[i]);
     printf("\n");

     return 0;
}

