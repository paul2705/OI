#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=25;
int n,m,mod;
int a[MAXN];
int nxt[MAXN];
struct rec{
	int a[MAXN][MAXN];
	rec(){
		for (int i=0;i<=m;i++){
			for (int j=0;j<=m;j++) a[i][j]=0;
		}
	}
} A;
rec mul(rec a,rec b){
	rec c;
	for (int k=0;k<=m;k++){
		for (int i=0;i<=m;i++){
			for (int j=0;j<=m;j++){
				c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j])%mod;
			}
		}
	}
	return c;
}
rec mod_pow(rec a,int n){
	rec ans=a; n--;
	while (n){
		if (n&1) ans=mul(ans,a);
		a=mul(a,a);
		n>>=1;
	}
	return ans;
}
int main(){
	scanf("%d%d%d",&n,&m,&mod);
	for (int i=1;i<=m;i++){
		char c=getchar(); while (c<'0'||c>'9') c=getchar();
		a[i]=c-'0';
	}
//	cout<<"done"<<endl;
	nxt[1]=0;
	for (int i=2;i<=m;i++){
		int pre=nxt[i-1];
		while (pre>0&&a[pre+1]!=a[i]) pre=nxt[pre];
		if (a[pre+1]==a[i]) pre++;
		nxt[i]=pre;
	}
//	cout<<"done"<<endl;
	for (int i=0;i<m;i++){
		for (int j=0;j<=9;j++){
//			cout<<i<<" "<<j<<endl;
			int pre=i;
			while (pre>0&&a[pre+1]!=j) pre=nxt[pre];
			if (a[pre+1]==j) pre++;
			if (pre!=m) A.a[pre][i]=(A.a[pre][i]+1)%mod;
		}
	}
//	cout<<"done"<<endl;
	A=mod_pow(A,n);
	int ans=0;
	for (int i=0;i<m;i++) ans=(ans+A.a[i][0])%mod;
	printf("%d\n",ans);
	return 0;
}
