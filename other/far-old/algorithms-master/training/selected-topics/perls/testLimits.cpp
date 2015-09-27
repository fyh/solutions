# include <limits>
# include <iostream>
using namespace std;

typedef long long int lli;

# define ssup(type) (~((type)0x1<<(8*sizeof(type)-1)))
# define usup(type) (~(type)0)
# define sinf(type) ((type)1<<(8*sizeof(type)-1))
# define uinf(type) (0)

int main()
{
    cout << ~(0ull) << endl;
    cout << numeric_limits<unsigned long long int>::max() << endl;

    cout << ~(1ll << 63) << endl;
    cout << numeric_limits<long long int>::max() << endl;

    cout << ~(1 << 31) << endl;
    cout << numeric_limits<int>::max() << endl;

    cout << ssup(int) << endl;
    cout << ssup(long long int) << endl;
    cout << usup(unsigned int) << endl;
    cout << usup(unsigned long long int) << endl;

    cout << uinf(unsigned int) << endl;
    cout << sinf(int) << endl;

    cout << uinf(unsigned long long int) << endl;
    cout << sinf(long long int) << endl;

    cout << (unsigned long long int)-1 << endl;

    return 0;
}
