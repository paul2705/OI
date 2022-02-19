#include <bits/stdc++.h>
using namespace std;
#define ref(i,x,y)for(int i=x;i<=y;++i)
#define def(i,x,y)for(int i=x;i>=y;--i)
typedef long long LL;
const int N=1001,M=1000000;
int n,m,p,ft[M+1],Ft[M+1],f[N];
int mul(int a,int b){
	return (LL)a*b%p;
}
int mi(int a,int b){
	int s=1;
	for(;b;b>>=1,a=mul(a,a))
		if(b&1)s=mul(s,a);
	return s;
}
void dec(int&a,int b){
	a-=b;if(a<0)a+=p;
}
int P(int n,int m){
	if(n<0||m<0||m>n)return 0;
	return mul(ft[n],Ft[n-m]);
}
int C(int n,int m){	
	if(n<0||m<0||m>n)return 0;
	return mul(mul(ft[n],Ft[n-m]),Ft[m]);
}
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>n>>m>>p;
	ft[0]=Ft[0]=1;
	ref(i,1,M)ft[i]=mul(ft[i-1],i);
	Ft[M]=mi(ft[M],p-2);
	def(i,M,1)Ft[i-1]=mul(Ft[i],i);
	ref(i,1,min(n,m)){
		f[i]=mul(P(n,i),P(m,i));
		int l=n+m-1,s=n+m-1,S=ft[s-1];
		def(j,i-1,1){
			l-=2;
			S=mul(S,P(s+l-1,l-1));
			s+=l;
		}
		S=mul(S,P(n*m,(n-i)*(m-i)));
		f[i]=mul(f[i],S);
	}
	def(i,min(n,m),1){
		ref(j,i+1,min(n,m))
			dec(f[i],mul(f[j],C(j,i)));
	}
	printf("%d\n",f[1]);
}