
## define sup, inf ##

```
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int uint;

ulli sup = ~((ulli)0);
lli  sup = ~(1ll<<63);
uint sup = ~((int)0)
int  sup = ~(1 << 31);

# define ssup(type) (~((type)0x1<<(8*sizeof(type)-1)))
# define usup(type) (~(type)0)
# define sinf(type) ((type)1<<(8*sizeof(type)-1))
# define uinf(type) (0)

# define sup(type) std::numeric_limits<type>::max() 
# define inf(type) std::numeric_limits<type>::min()
```


```
# define sup(type) std::numeric_limits<type>::max() 
# define inf(type) std::numeric_limits<type>::min()
```
