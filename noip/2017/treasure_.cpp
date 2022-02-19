#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;
const int MAXN=13;
const int MAXS=(1<<12);
int n,m,mp[MAXN][MAXN];
int g[MAXN][MAXS],f[MAXN][MAXS];
int ans=1e9;
bitset<13> st;
int getdis(int s,int s1){
	int ret=0;
	for (int i=0;i<n;i++){
		if (s&(1<<i)) ret+=g[i+1][s1];
	}
//	cout<<ret<<endl;
	return ret;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) mp[i][j]=1e7;
	}
	for (int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		mp[u][v]=mp[v][u]=min(mp[u][v],w);
	}
	for (int i=1;i<=n;i++){
		for (int s=0;s<(1<<n);s++){
			g[i][s]=1e9;
			for (int j=0;j<n;j++){
				if (s&(1<<j)) g[i][s]=min(g[i][s],mp[i][j+1]);
			}
		}
	}
	memset(f,63,sizeof(f));
	for (int i=0;i<n;i++) f[1][1<<i]=0;
	for (int i=2;i<=n;i++){
		for (int s=1;s<(1<<n);s++){
			int pr=s^((1<<n)-1);
			for (int s1=pr;s1;s1=(s1-1)&pr){
				int w=getdis(s1,s);
//				cout<<w<<" "<<f[i][s|s1]<<" "<<f[i-1][s]<<endl;
				f[i][s|s1]=min(f[i][s|s1],f[i-1][s]+w*(i-1));
//				st=s|s1;
//				cout<<"; "<<st<<" ";
//				st=s;
//				cout<<st<<" "<<f[i-1][s]<<" "<<w<<" "<<f[i][s|s1]<<endl;
			}
//			st=s;
//			cout<<st<<" "<<f[i][s]<<endl;
		}
		ans=min(ans,f[i][(1<<n)-1]);
	}
	printf("%d\n",ans);
	return 0;
}
