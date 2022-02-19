#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)ans=1ll*ans*a%mod;
	return ans;
}
int fac[300100],inv[300100],T,n,m,P,A;
int ni[301000],mi[301000],Pi[301000],Ai[301000];
int C(int x,int y){
	if(x<y||y<0)return 0;
	return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
namespace Calc{
	struct data{
		int n,k,f,id;
		data(){}
		data(int n,int k,int f,int id):
			n(n),k(k),f(f),id(id){}
	}d[301000];
	int ptr,anses[301000];
	void push(int n,int k,int f,int id){
		d[++ptr]=data(n,k,f,id);
	}
	void run(int BLK){
		sort(d+1,d+ptr+1,[&](data a,data b){
			int ak=a.k/BLK,bk=b.k/BLK;
			if(ak!=bk)return ak<bk;
			return a.n<b.n;
		});
		int sum1=0,sum2=0;
		int pos=1;
		while(pos<=ptr){
			sum1=0,sum2=0;
			for(int i=0;i<=d[pos].k;++i){
				sum1=(sum1+C(d[pos].n,2*i))%mod;
				sum2=(sum2+C(d[pos].n,2*i+1))%mod;
			}
			anses[d[pos].id]=d[pos].f==0?sum1:sum2;
//			pos++;continue;
			for(pos++;pos<=ptr&&d[pos].k/BLK==d[pos-1].k/BLK;pos++){
				for(int i=d[pos-1].n;i<d[pos].n;++i){
					int A=(sum1+sum2)%mod;
					sum1=(A-C(i,d[pos-1].k*2+1)+mod)%mod;
					sum2=A;
				}
				for(int i=d[pos-1].k;i>d[pos].k;--i){
					sum1=(sum1+mod-C(d[pos].n,i*2))%mod;
					sum2=(sum2+mod-C(d[pos].n,i*2+1))%mod;
				} 
				for(int i=d[pos-1].k+1;i<=d[pos].k;++i){
					sum1=(sum1+C(d[pos].n,i*2))%mod;
					sum2=(sum2+C(d[pos].n,i*2+1))%mod;
				} 
				anses[d[pos].id]=d[pos].f==0?sum1:sum2;
			}
		} 
	}
}
int main(){
	fac[0]=inv[0]=1;
	for(int i=1;i<=300000;++i)fac[i]=1ll*fac[i-1]*i%mod;
	inv[300000]=qpow(fac[300000],mod-2);
	for(int i=300000-1;i>=0;--i)inv[i]=1ll*inv[i+1]*(i+1)%mod;
	scanf("%d",&T);
	int mx=0;
	for(int i=1;i<=T;++i){
		scanf("%d%d%d%d",&n,&m,&P,&A);
		ni[i]=n,mi[i]=m,Pi[i]=P,Ai[i]=A;
		if(n>m)swap(n,m);
		mx=max(mx,n);
		A^=(n+m)%2;
		if(A==1)
			Calc::push(n+m,n/2-1,n%2==0&&m%2==0?0:1,i);
		else 
			Calc::push(n+m+(m%2==0&&n%2==1?1:0),n/2-(n%2==m%2?1:0),n%2==0&&m%2==1?0:1,i);
	}
	Calc::run(sqrt(mx*2));
	for(int i=1;i<=T;++i){
		n=ni[i],m=mi[i],P=Pi[i],A=Ai[i];
		int _A=A;
		A^=(n+m)%2;
		P=1ll*P*qpow((int)1e9,mod-2)%mod;
		if(n>m)swap(n,m),P=mod+1-P;
		int ans=Calc::anses[i];
//		printf("{%d}",ans);
		if(A==1){
			ans=1ll*ans*qpow(C(n+m,n),mod-2)%mod;
			ans=(ans+m/2)%mod;
			if(m%2==0&&n%2!=0)ans=(ans+mod-1ll*(m/2)*qpow(n+m,mod-2)%mod)%mod;
			if(m%2!=0&&n%2==0)ans=(ans+mod-1ll*(n/2)*qpow(n+m,mod-2)%mod)%mod;
			if(m%2!=0&&n%2!=0)ans=(ans+(mod+1)/2)%mod;	
		} else {
			ans=1ll*ans*qpow((m%2==0&&n%2==1?2ll:1ll)*C(n+m,n)%mod,mod-2)%mod;
			ans=(ans+m/2)%mod;
			if(m%2!=0&&n%2==0)ans=(ans+1ll*(n/2)*qpow(n+m,mod-2)%mod)%mod;
			if(m%2!=0&&n%2!=0)ans=(ans+1ll*(n/2*3+m/2+2)*qpow(n+m,mod-2)%mod)%mod;
		}
		int mans=0;
		mans=1ll*(1ll*(mod+1-P)*C(m+n,m)+1ll*(2ll*P+mod-1)*C(m+n-1,n-1))%mod*(((n+m)%2==_A?(n+m)/2:n+m-(n+m)/2))%mod;
//		printf("<%d>",mans);
		mans=1ll*mans*qpow(C(m+n,m),mod-2)%mod;
		ans=(ans+mans)%mod;
		ans=(ans%mod+mod)%mod;
		printf("%d\n",ans);
	}
}
