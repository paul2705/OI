#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e4;
const int MAXN=1e3+5;
int n,m,M,ans1,ans2;
int mod_pow(int x,int n){
	int ret=1; x%=mod;
	while (n){
		if (n&1) ret=ret*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return ret;
}
int main(){
	scanf("%d",&n);
	ans1=M=1;
	for (int i=1;i<=n;i++){
		int p,r; scanf("%d%d",&p,&r);
		M=M*mod_pow(p,r)%mod;
		if (p!=2){
			int t=ans1;
			ans1=(ans1+ans2*(p-1))%mod;
			ans2=(ans2+t*(p-1))%mod;
		}
	}
	ans1=(ans1-1+mod)%mod;
	printf("%d\n%d\n%d\n",ans1,ans2,((M-ans1-ans2-1)%mod+mod)%mod);
	return 0;
}
