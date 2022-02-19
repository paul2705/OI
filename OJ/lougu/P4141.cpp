#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e3+5;
int n,m,w[MAXN],f[MAXN],g[MAXN];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&w[i]);
	f[0]=1;
	for (int i=1;i<=n;i++){
		for (int j=m;j>=w[i];j--){
			f[j]+=f[j-w[i]]; f[j]%=10;
		}
	}
	for (int i=1;i<=n;i++){
		memset(g,0,sizeof(g)); g[0]=1;
		for (int j=1;j<=m;j++){
			g[j]=f[j];
			if (j>=w[i]) g[j]=(g[j]-g[j-w[i]]+10)%10;
			cout<<g[j];
		}
		cout<<endl;
	}
	return 0;
}
