#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=3e3+5;
const int MAXM=MAXN*MAXN;
int edge,head[MAXN],nex[MAXM],tail[MAXM];
int n;
vector<int> ans[MAXN],g[MAXN];
bool fl,use[MAXN];
int a[MAXN][MAXN];
int q[MAXM],l,r;
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			char c=getchar();while (c!='1'&&c!='0') c=getchar();
			if (c=='1') add(j+n,i);
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			char c=getchar(); while (c!='1'&&c!='0') c=getchar();
			if (c=='1') add(i,j+2*n),a[i][j+2*n]=1;
		}
	}
	for (int i=n+1;i<=2*n;i++){
		for (int j=1;j<=3*n;j++) use[j]=0;
		use[i]=1; l=r=0;
		q[++r]=i;
		while (l<r){
			int u=q[++l];
			for (int e=head[u];e;e=nex[e]){
				int v=tail[e];
				if (use[v]) continue;
				use[v]=1;
				q[++r]=v;
			}
		}
		for (int j=2*n+1;j<=3*n;j++){
			if (use[j]) cout<<j<<" "<<i<<endl,ans[i].push_back(j);
		}
	}
	for (int i=1;i<=3*n;i++){
		for (int e=head[i];e;e=nex[e]){
			int v=tail[e];
			if (v>2*n) continue;
			g[v].push_back(i);
		}
	}
	for (int i=n+1;i<=2*n;i++){
		for (int j=0;j<ans[i].size();j++){
			int v=ans[i][j];
			g[i].push_back(v);
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=3*n;j++) use[j]=0;
		use[i]=1; l=r=0; q[++r]=i;
		while (l<r){
			int u=q[++l];
			for (int j=0;j<g[u].size();j++){
				int v=g[u][j];
				if (use[v]) continue;
				use[v]=1;
				q[++r]=v;
			}
		}
		for (int j=2*n+1;j<=3*n;j++){
			cout<<use[j]<<" ";
			if (use[j]!=a[i][j]) fl=1;
		}
		cout<<endl;
	}
	if (fl) printf("-1\n");
	else {
		for (int i=n+1;i<=2*n;i++){
			for (int j=0;j<ans[i].size();j++){
				int v=ans[i][j];
				a[i][v]=1;
			}
			for (int j=2*n+1;j<=3*n;j++) printf("%d",a[i][j]);
			printf("\n");
		}
	}
	return 0;
}
