#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int T,n,a[1001];
inline int read(){
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9'){ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}
int main(){
	T=read();
	while(T--){
		int ans=0;
		n=read();
		for(int i=1;i<=n;i++)
		    a[i]=read();
		for(int i=n;i>1;i-=2)
		    ans^=(a[i]-a[i-1]);
        if(n&1)ans^=a[1];
		if(ans)printf("TAK\n");
		else printf("NIE\n");
	}
	return 0;
}
