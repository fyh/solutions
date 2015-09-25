int bsearch_upper(const int &key, int *arr, int l, int r)
{
    if (l+1 == r) return arr[l]==key ? l:-1;
    int mid = l+(r-l)/2;
    if (arr[mid] < key) bsearch_upper(key, arr, mid+1, r);
    else if (arr[mid] > key) bsearch_upper(key, arr, l, mid-1);
    else bsearch_upper(key, arr, mid, r);
}

int bsearch_upper(const int &key, int *arr, int n)
{
    int lo = 0, hi = n-1, mid;
    while (lo+1 < hi) {
        mid = lo + (hi-lo>>1);
        if (arr[mid] < key) lo = mid+1;
        else if (arr[mid] > key) hi = mid-1;
        else lo = mid;
    }
}
