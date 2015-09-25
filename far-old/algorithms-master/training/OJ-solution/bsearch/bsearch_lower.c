//
int bsearch_lower(const int &key, int *arr, int l, int r)
{
    if (l == r) return arr[l]==key ? l:-1;
    int mid = l + (r-l)/2;
    if (arr[mid] < key) bsearch_lower(key, arr, mid+1, r);
    else if(arr[mid] > key) bsearch_lower(key, arr, l, mid-1);
    else bsearch_lower(key, arr, l, mid);
}

int bsearch_lower(const int &key, int *arr, int n)
{
    int lo = 0, hi = n-1, mid;
    while (lo < hi) {
        mid = lo + (hi-lo>>1);
        if (arr[mid] < key) lo = mid+1;
        else if (arr[mid] > key) hi = mid - 1;
        else hi = mid;
    }
    return arr[lo]==key ? lo:-1;
}
