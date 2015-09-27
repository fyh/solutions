// �ݹ��ܹ���ֹ������mid��[l,r]�У�ÿ�εݹ����䳤��ʼ�����ϸ���ٵ�
// �����ԣ����arr[l..r]��������һ��ֵ��key��ȵ�Ԫ�أ���ôÿ�εݹ鶼��֤�˵�ǰ����ʼ�մ���ֵ��key��ȵ�Ԫ��
// ��ȷ�ԣ�����������ҵ��������arr[l..r]��������һ��ֵ��key��ȵ�Ԫ�أ��������������ԣ��ݹ���ֹʱֻ�᷵��mid���ҵ���Ԫ���±ꡣ
//         ��������践��-1����ǰ���䲻���ں�key ��ȵ�Ԫ�أ��벻����ì�ܣ�
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
    // ��ʼ���ҵķ�Χ��[0,n-1]
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
