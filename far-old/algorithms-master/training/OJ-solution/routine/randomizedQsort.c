/*

当前日期: 2014/10/10 周五 
by Wu Yajun

*/

# include <stdlib.h>
# include <time.h>

void swap( int * x, int * y)
{
     if (x ^ y) { 
          int t = *x;
          *x = *y;
          *y = t;
     }
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

void RandomizedQsort(int * arr, int p, int r)
{
     if (r > p) {
          int q = RandomizedPartion( arr, p, r );
          RandomizedQsort( arr, p, q-1);
          RandomizedQsort( arr, q+1, r);
     }
}

// an example
# include <stdio.h>
int main()
{
     srand( time(NULL) );
     int a[] = {5, 3, 2, 4, 1, 2};
     RandomizedQsort(a, 0, 5);
     int i;
     for (i = 0; i < 6; ++i) {
          printf("%d ", a[i]);
     }
     printf("\n");
}

