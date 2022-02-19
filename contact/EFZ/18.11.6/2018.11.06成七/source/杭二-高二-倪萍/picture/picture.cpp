#include<bits/stdc++.h>
#define LL long long 
#define N 1000005
using namespace std;
LL h1,w1,h2,w2,H,W,k1,k2,K1,K2,Ans;
char s1[N],s2[N];
int gcd(LL a,LL b){ if (!b) return a;return gcd(b,a%b);} 
/*int check(int A,int B){
	int T=1,t=0,ans=0,pp=s2[(B-1)*w2+T]-'0';
	for (int i=1;i<=w1;i++){
		int p=s1[(A-1)*w1+i]-'0';
		for (int j=1;j<=k2;j++){
			t++;
			if (t>K2) t%=K2,T++,pp=s2[(B-1)*w2+T]-'0';
			ans+=(p==pp);
		} 
	} 
	return ans;
} */
LL check(LL A,LL B){
	LL ans=0,f=0,ff=0,tf,tff,p,pp,Li;
	while (f<W){
		f++,ff++;
		tf=( (f-1)/k2+1 )*k2,tff=( (ff-1)/K2+1 )*K2;
		Li=min(tf,tff);
		p=s1[(A-1)*w1+(f-1)/k2+1 ]-'0',pp=s2[(B-1)*w2+ (ff-1)/K2+1 ]-'0';
		if (p==pp) ans+=(Li-f+1);
		f=Li,ff=Li;
	}
	return ans;
} 
int main(){
	freopen("picture.in","r",stdin);freopen("picture.out","w",stdout);
	scanf("%lld%lld",&h1,&w1); scanf("%s",s1+1);
	scanf("%lld%lld",&h2,&w2); scanf("%s",s2+1);
	H=((LL)h1*(LL)h2)/gcd(h1,h2);
	W=((LL)w1*(LL)w2)/gcd(w1,w2);
	k1=H/h1,k2=W/w1;
	K1=H/h2,K2=W/w2;
	//printf("%d %d %d %d %d %d\n",H,W,k1,k2,K1,K2);
	Ans=0;
	LL d=0,dd=0,td,tdd,lim,A,B;
	while (d<H){
		d++,dd++;
		td=( (d-1)/k1+1 )*k1,tdd=( (dd-1)/K1+1 )*K1;
		lim=min(td,tdd); 
		//printf("    %d %d\n",d,dd),printf("   %d %d\n",td,tdd),printf("*%d\n",lim);
		A=(d-1)/k1+1,B=(dd-1)/K1+1;
		Ans+=(LL)check(A,B)*(LL)(lim-d+1);
		d=lim,dd=lim;
	}
	printf("%lld\n",Ans);
} 

