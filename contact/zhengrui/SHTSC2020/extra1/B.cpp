#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define R register
const int N=512,P=998244353;
int n,f[N][2][N],g[N][2][N],r[N],w[N];
inline void upd(int&x,int y){x+=y;if(x>=P)x-=P;}
inline int pw(int a,int b){int r=1;for(;b;b>>=1,a=1ll*a*a%P)if(b&1)r=1ll*r*a%P;return r;}
inline void ntt(int n,int*a,int f){
	int l=1;while((1<<l)<n)l++;
	for(int i=1;i<n;i++)r[i]=r[i>>1]>>1|(i&1)<<(l-1);
	for(int i=0;i<n;i++)if(i<r[i])swap(a[i],a[r[i]]);
	for(int i=2;i<=n;i<<=1){
		int wn=pw(3,f==1?(P-1)/i:P-1-(P-1)/i);
		for(int j=w[0]=1;j<(i>>1);j++)w[j]=1ll*w[j-1]*wn%P;
		for(int j=0;j<n;j+=i){
			int *x=a+j,*y=a+j+(i>>1);
			for(int k=0;k<(i>>1);k++){int v=1ll*y[k]*w[k]%P;y[k]=(x[k]+P-v)%P;x[k]=(x[k]+v)%P;}
		}
	 } 
	if(f==-1)for(int i=0,iv=pw(n,P-2);i<n;i++)a[i]=1ll*a[i]*iv%P;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<N;i++)f[0][0][i]=g[0][1][i]=1;
	int wn=pw(3,(P-1)/N);
	for(int i=w[0]=1;i<N;i++)w[i]=1ll*w[i-1]*wn%P;
	for(R int i=1;i<=n;i++){
		for(R int t=0;t<2;t++)for(R int j=0;j<N;j++)f[i][t][j]=g[i-1][t][j];
		for(R int j=0;j<i;j++)for(R int t1=0;t1<2;t1++)for(R int t2=0;t2<2;t2++)for(int k=0;k<N;k++) {
			if(!t2)g[i][t1&(!t2)][k]=(g[i][t1&(!t2)][k]+1ll*g[j][t1][k]*f[i-j][t2][k])%P;
			else g[i][t1&(!t2)][k]=(g[i][t1&(!t2)][k]+1ll*g[j][t1][k]*f[i-j][t2][k]%P*w[k])%P;
		} 
	}
	for(int i=1;i<=n;i++){
		ntt(N,f[i][0],-1);ntt(N,f[i][1],-1);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++)printf("%d ",(f[i][0][j]+(j?f[i][1][j-1]:0))%P);
		puts("");
	}
	return 0; 
}
