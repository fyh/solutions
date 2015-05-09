# include <stdio.h>
# include <string.h>
# include <iostream>
# include <algorithm>
# include <queue>

using namespace std;

# define testin freopen("in.txt", "r", stdin)

char o[105][105];

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

int n = 5, k = 1;
int main()
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i%2==j%2 && k)  {
                printf("L");
                --k;
            } else printf("S");
        }
        printf("\n");
    }
    return 0;
}
