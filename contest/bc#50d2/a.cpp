# include <stdio.h>
# include <string.h>
# include <algorithm>
# include <iostream>

using namespace std;

# define testin freopen("in.txt", "r", stdin)

int a[1005];

int main()
{
    // testin;

    int n;
    while(cin >> n) {
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a, a+n);
        int k = upper_bound(a, a+n, a[n/2]) - lower_bound(a, a+n, a[n/2]);
        if (2*k > n) printf("%d\n", a[n/2]);
        else puts("-1");
    }


    return 0;
}
