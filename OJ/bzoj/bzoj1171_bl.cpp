#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf=5e5;
const int MAXN=2e3+5;
int f[MAXN];
int n,L;
int x[MAXN],y[MAXN],d[MAXN];
int main(){
	freopen("bzoj1171.in","r",stdin);
	freopen("bzoj1171_bl.out","w",stdout);
	scanf("%d%d",&n,&L);
	int lim=0;
	for (int i=2;i<=n;i++){
		scanf("%d%d%d",&x[i],&y[i],&d[i]);
		lim=max(lim,y[i]);
		f[i]=inf;
	}
	x[1]=0; y[1]=lim;
	f[1]=0;
	for (int i=2;i<=n;i++){
		for (int j=i-1;j>=1;j--){
			if (d[i]-d[j]>L) break;
			if (x[i]>y[j]||y[i]<x[j]) continue;
//			cout<<"("<<j<<","<<f[j]<<")->"<<i<<endl;
			f[i]=min(f[i],f[j]+1);
		}
		printf("%d\n",f[i]>=inf?-1:f[i]);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
