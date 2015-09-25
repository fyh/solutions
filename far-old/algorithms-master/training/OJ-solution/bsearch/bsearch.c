// 递归能够终止：由于mid在[l,r]中，每次递归区间长度始终是严格减少的
// 不变性：如果arr[l..r]中至少有一个值和key相等的元素，那么每次递归都保证了当前区间始终存在值和key相等的元素
// 正确性（如果存在能找到）：如果arr[l..r]中至少有一个值和key相等的元素，由于上述不变性，递归终止时只会返回mid即找到的元素下标。
//         （否则假设返回-1，当前区间不存在和key 相等的元素，与不变性矛盾）
int bsearch(const int &key, int *arr, int l, int r) // [l, r];
{
    if (l > r) return -1;
    int mid = l + (r-l)/2;
    if (arr[mid] < key) return bsearch(key, arr, mid+1, r);  // [mid+1, r]
    else if (arr[mid] > key) return bsearch(key, arr, l, mid-1); // [l, mid-1]
    else return mid;
}

int bsearch(const int &key, int *arr, int n)
{
    // 初始查找的范围是[0,n-1]
    int lo = 0, hi = n-1, mid;
    while (lo < hi)
    {
        mid = lo+(hi-lo>>1);
        if ( arr[mid] < key ) lo = mid + 1;
        else if ( arr[mid] > key ) hi = mid - 1;
        else return mid;
    }
    return -1;
}
