#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<queue>
#include<map>
#include<set>
#define ll long long
#define rep(i,j,k) for(int i=j;i<=k;++i)
#define drp(i,j,k) for(int i=j;i>=k;--i)
#define cross(i,x) for(int i=h[x];i;i=e[i].n)
using namespace std;
char buf[25];
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*f;
}
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(!x){putchar('0');return;}
    int cnt=0;
    while(x){buf[++cnt]='0'+x%10;x/=10;}
    drp(i,cnt,1)putchar(buf[i]);
}
int main(){
	n=read();
    return 0;
}
