#include<bits/stdc++.h>
using namespace std;
int n,m;
int p[1005],fa[1005];
vector<int> g[1005],c[1005];
int d[1005];
int x[1005],y[1005],deg[1005];
int e[1005][1005];
void dfs(int u,int p)
{
	fa[u]=p;
	d[u]=d[p]+1;
	for (int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if (v==p) continue;
		dfs(v,u);
	}
}
int lca(int u,int v)
{
	if (d[u]<d[v]){
		int t=u;u=v;v=t;
	}
	while (d[u]>d[v]) u=fa[u];
	if (u==v) return u;
	while (fa[u]!=fa[v]) {
		u=fa[u];v=fa[v];
	}
	return fa[u];
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) {
	    scanf("%d",&p[i]);
	    c[p[i]].push_back(i);
	}
	for (int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
//	for (int i=1;i<=n;i++) cout<<d[i]<<" ";
//	cout<<endl;
//	for (int i=1;i<=n;i++) cout<<p[i]<<' ';
//cout<<lca(3,5)<<" "<<lca(3,4)<<" "<<lca(2,2)<<" "<<endl;
//    for (int i=1;i<=m;i++){
//    	for(int j=0;j<c[i].size();j++)cout<<c[i][j]<<" ";
//    	cout<<endl;
//	}
	for (int i=1;i<=m;i++){
		if (c[i].size()==0)x[i]=y[i]=1;
	    else if (c[i].size()==1) x[i]=y[i]=c[i][0];
	    else {
	    	for (int j=0;j<c[i].size();j++){
	    		if (d[x[j]]<d[c[i][j]]) x[i]=c[i][j];
			}
			int l=x[i];
			for (int j=0;j<c[i].size();j++){
				int v=c[i][j];
				l=lca(l,v);
			}
			for (int j=0;j<c[i].size();j++){
				int v=c[i][j];
				if (lca(v,x[i])==l&&d[v]>d[y[i]]) y[i]=v;
			}
			if (y[i]==x[i]) y[i]=l;
			int u=x[i],v=y[i];
//			cout<<i<<" "<<x[i]<<" "<<y[i]<<" "<<l<<endl;
			while (d[u]>=d[l]){
				if (p[u]!=i) e[i][p[u]]=1;
				u=fa[u];
			}
			while (d[v]>=d[l]){
				if (p[v]!=i) e[i][p[v]]=1;
				v=fa[v];
			}

		}
	}
//	for (int i=1;i<=m;i++){
//	    for (int j=1;j<=m;j++) cout<<e[i][j]<<" ";
//	    cout<<endl;
//	}
	for (int i=1;i<=m;i++){
		for (int j=1;j<=m;j++) 
		    if (e[i][j]) deg[j]++;
	}
	
	int q[1005],l=1,r=1;
	for (int i=1;i<=m;i++) {
		if (c[i].size()==0) printf("%d 1 1\n",i);
	    else if (deg[i]==0) q[r++]=i;
	}
	while (l<r){
		int u=q[l++];
		for (int v=1;v<=m;v++)
		    if (e[u][v]){
		    	deg[v]--;
		    	if (deg[v]==0) q[r++]=v;
			}
	}
	for (int i=1;i<r;i++) printf("%d %d %d\n",q[i],x[q[i]],y[q[i]]);
	fclose(stdin);fclose(stdout);
}

