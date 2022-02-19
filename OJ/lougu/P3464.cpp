#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define inf 0x7f7f7f7f
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
inline int read(){
    int x=0,f=1;char ch=getchar();
    for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
    for (;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
    return x*f;
}
inline void print(int x){
    if (x>=10)     print(x/10);
    putchar(x%10+'0');
}
const int p=1e9;
const int N=1e4;
const int digit=4;
const int base=1e4;
char s[N+10];
struct Bignum{
    int v[N+10],len;
    Bignum(){len=1,memset(v,0,sizeof(v));}
    void read(){
        scanf("%s",s);
        int t=strlen(s),tim=1;
        len=(t-1)/digit+1;
        for (int i=0,j=t-1;i<j;i++,j--) swap(s[i],s[j]);
        for (int i=0;i<t;i++){
            v[i/digit]+=(s[i]-'0')*tim,tim*=10;
            if (tim==base)  tim=1;
        }
    }
    void write(){
        printf("%d",v[len-1]);
        for (int i=len-2;~i;i--)    printf("%0*d",digit,v[i]);
        putchar('\n');
    }
}A,Zero;
int operator %(Bignum x,int y){
    for (int i=x.len;i;i--) x.v[i-1]+=x.v[i]%y*base;
    return x.v[0]%y;
}
Bignum operator /(Bignum &x,int y){
    for (int i=x.len;~i;i--)    x.v[i-1]+=x.v[i]%y*base,x.v[i]/=y;
    while (!x.v[x.len]&&x.len)  x.len--;
    x.len++;
    return x;
}
bool operator ==(const Bignum &x,const Bignum &y){
    if (x.len!=y.len)   return 0;
    for (int i=0;i<=x.len;i++)  if (x.v[i]!=y.v[i]) return 0;
    return 1;
}
bool operator !=(const Bignum &x,const Bignum &y){return !(x==y);}
struct Dp{
    int x,y;
    Dp(){}
    Dp(int _x,int _y){x=_x,y=_y;}
}f[N+10],g[N+10];
Dp min(const Dp &a,const Dp &b){return a.x<b.x?a:b;}
Dp operator +(const Dp &a,int b){return Dp(a.x+b,a.y);}
Dp operator +(const Dp &a,const Dp &b){return a.x==b.x?Dp(a.x,(a.y+b.y)%p):min(a,b);}
int T[N+10];
int main(){
    int tot=1;
    A.read();
    while (A!=Zero) T[tot++]=A%4,A=A/4;
    f[0]=Dp(0,1),g[0]=Dp(inf,0);
    for (int i=1;i<=tot;i++){
        f[i]=(f[i-1]+T[i])+(g[i-1]+(T[i]+1));
        g[i]=(f[i-1]+(4-T[i]))+(g[i-1]+(3-T[i]));
    }
    printf("%d\n",f[tot].y);
    return 0;
}
