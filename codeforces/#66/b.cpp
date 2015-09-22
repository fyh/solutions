#include <cstdio>
#include <map>
#include <string>
#include <algorithm>
# include <iostream>
using namespace std;
int i,x,y,n,p,r,z,m,a[100100],b[100100],k[100100];
map <string, int> mm;
string st[100100];
char s[44];
bool cmp(int i, int j) {
  return (a[i]<a[j] || (a[i]==a[j] && st[i]>st[j]));
}
/*
3 4 7

7 8 9
6 7 11

8 3  1  9
5 1  3  8
//3 A 3 B 5 C 8 3 4 3 1 A

A B C
3 5 8
4 3 1

7 6 11
7 8 9

*/
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%s",s);
    st[i]=s; mm[st[i]]=i+1;
    scanf("%d",&a[i]); k[i]=i;
  }
  sort(k,k+n,cmp);
  scanf("%d",&m);
  for (i=0; i<m; i++) scanf("%d",&b[i]);
  sort(b,b+m);
  reverse(b,b+m);
  scanf("%s",s);
  x=mm[s]-1; y=a[x]+b[0]; p=1; r=1;
  for (i=0; i<n; i++) if (k[i]!=x) {
    if (st[k[i]]<st[x]) z=y-a[k[i]]-1; else z=y-a[k[i]];
    if (p>=n || b[p]>z) r++;
    p++;
  }
  printf("%d ",r);
  y=a[x]+b[n-1]; p=0; r=1;
  for (i=0; i<n; i++) if (k[i]!=x) {
    if (st[k[i]]<st[x]) z=y-a[k[i]]; else z=y-a[k[i]]+1;
    if (p<n && b[p]>=z) { p++; r++; }
  }
  printf("%d\n",r);
  return 0;
}
