/**************************************************************
    Problem: 1002
    User: fyh
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:804 kb
****************************************************************/
 
//
// 暴力找规律
  
# include <cstdio>
# include <cstring>
 
// 高精度
class BigInt
{
public:
  int s[1005];
  int len;
  int operator[](int v){return s[v];}
  BigInt(){memset(s, 0, sizeof(s));}
  void operator=(int num) {
    for (len = 0; num; ++len) {
      s[len] = num%10;
      num/=10;
    }
  }
  void operator=(BigInt t) {
    for (len = 0; len < t.len; ++len) {
      s[len] = t[len];
    }
  }
  void operator+=(BigInt t) {
    for (int i = 0, c = 0; i <= len; ++i) {
      c = t[i] + s[i] + c;
      s[i] = c%10;
      c /= 10;
    }
    if (s[len]>0) ++len;
  }
  void operator*=(BigInt t) {
    BigInt tmp = *this;
    memset(s, 0, sizeof(s));
    for (int i = 0, c = 0; i < len; ++i) {
      for (int j = 0; j < t.len || c > 0; ++j) {
        c = s[i+j]+tmp[i]*t[j] + c;
        s[i+j] = c % 10;
        c /= 10;
      }
    }
    for (len = 1004; len >= 0 && s[len] == 0; --len); ++len;
  }
  void operator*=(int num) {
    for (int i = 0, c = 0; i < len || c>0; ++i) {
      c = c + s[i]*num;
      s[i] = c%10;
      c /= 10;
      if (i>=len && c<=0) len = i+1;
    }
  }
  void print(void) {
    for (int i = len-1; i >= 0; --i) printf("%d", s[i]);
    printf("\n");
  }
};
 
 
int main()
{
  int n;
  scanf("%d", &n); 
  BigInt a, b, t;
  a = n%2 ? 2:1;
  b = 1;
  for (int i = 1; i <= (n%2 ? n:n-1); ++i) {
    t = a;
    a = b;
    b += t;
  }
  a *= a;
  if (n%2==0) a *= 5;
  a.print();
  return 0;
}
?