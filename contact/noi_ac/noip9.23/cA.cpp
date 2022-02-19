#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int f[3][MAXN],g[3][MAXN],h[5][MAXN*3];
int n,m,x[MAXN],y[MAXN];
int ans[MAXN];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=MAXN;i++) f[1][i]=g[1][i]=1e9;
	for (int i=1;i<=2*MAXN;i++) h[1][i]=h[3][i]=1e9;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&x[i],&y[i]);
		f[1][x[i]]=min(f[1][x[i]],y[i]);
		f[2][x[i]]=max(f[2][x[i]],y[i]);
		g[1][y[i]]=min(g[1][y[i]],x[i]);
		g[2][y[i]]=max(g[2][y[i]],x[i]);
		h[1][x[i]+y[i]]=min(h[1][x[i]+y[i]],x[i]);
		h[2][x[i]+y[i]]=max(h[2][x[i]+y[i]],x[i]);
		h[3][x[i]-y[i]+MAXN]=min(h[3][x[i]-y[i]+MAXN],x[i]);
		h[4][x[i]-y[i]+MAXN]=max(h[4][x[i]-y[i]+MAXN],x[i]);
	}
//	for (int i=1;i<=2*n;i++) cout<<i<<" "<<h[1][i]<<" "<<h[2][i]<<endl;
	for (int i=1;i<=m;i++){
		int s=0;
		s+=f[1][x[i]]<y[i]; s+=f[2][x[i]]>y[i];
		s+=g[1][y[i]]<x[i]; s+=g[2][y[i]]<x[i];
		s+=h[1][x[i]+y[i]]<x[i]; s+=h[2][x[i]+y[i]]>x[i];
		s+=h[3][x[i]-y[i]+MAXN]<x[i]; s+=h[4][x[i]-y[i]+MAXN]>x[i];
//		cout<<i<<" "<<s<<endl;
		ans[s]++;
	}
	for (int i=0;i<9;i++) printf("%d ",ans[i]);
	cout<<endl;
	return 0;
}
