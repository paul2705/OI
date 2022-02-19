#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=1e3+4;
const int MAXM=2e6+6;
int g[MAXN][MAXN];
int n,ans;
vector<int> ev(4),od(4);
int rd[MAXN];
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int fa[MAXN],flw[MAXN],tim,mat[MAXN];
int pre[MAXN],tp[MAXN];
int q[MAXM],l,r;
bool cmp(int x,int y){ return rd[x]<rd[y]; }
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int lca(int x,int y){
	tim++;
	while (1){
		x=find(x);
		if (flw[x]==tim) return x;
		else flw[x]=tim,x=mat[pre[x]];
		swap(x,y);
	}
}
void shk(int x,int y,int p){
	while (find(x)!=p) {
		pre[x]=y,y=mat[x];
		if (tp[y]==2) tp[y]=1,q[++r]=y;
		if (find(x)==x) fa[x]=p;
		if (find(y)==y) fa[y]=p;
		x=pre[y];
	}
}
bool bfs(int s){
	l=r=0;
	for (int i=1;i<=n;i++) fa[i]=i,tp[i]=pre[i]=0;
	q[++r]=s; tp[s]=1;
	while (l<r){
		int u=q[++l];
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (find(u)==find(v)||tp[v]==2) continue;
			if (!tp[v]){
				tp[v]=2; pre[v]=u;
				if (!mat[v]){
					for (int now=v,last;now;now=last){
						int tmp=pre[now];
						last=mat[pre[now]];
						mat[tmp]=now; mat[now]=tmp;
					}
					return 1;
				}
				tp[mat[v]]=1; q[++r]=mat[v];
			}
			else if (tp[v]==1){
				int f=lca(u,v);
				shk(u,v,f); shk(v,u,f);
			}
		}
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	bool flx=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			char c=getchar(); while (c!='0'&&c!='1') c=getchar();
			if (c=='1'){
				g[i][j]=1;
				rd[j]++;
				flx=1;
			}
		}
	}
	if (!flx){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (j==i%n+1) g[i][j]=g[j][i]=1;
			}
		}
		printf("Yes\n");
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++) printf("%d",g[i][j]);
			printf("\n");
		}
		return 0;
	}
	for (int i=1;i<=n;i++){
		if (rd[i]%2==1) od.push_back(i);
		else ev.push_back(i),mat[i]=1;
	}
	for (int i=0;i<od.size();i++){
		for (int j=0;j<od.size();j++){
			int u=od[i],v=od[j];
			if (u==v) continue;
			if (!g[u][v]) add(u,v);
		}
	}
	bool fl=0;
	int res=0;
	for (int i=0;i<od.size();i++){
		int x=od[i];
		if (!mat[x]) res+=bfs(x);
	}
//	cout<<"fuck"<<endl;
	for (int i=0;i<od.size();i++){
		int x=od[i];
//		cout<<x<<" "<<mat[x]<<endl;
		if (mat[x]&&!g[x][mat[x]]) g[x][mat[x]]=g[mat[x]][x]=1,rd[x]++,rd[mat[x]]++;
	}
	sort(ev.begin(),ev.end(),cmp);
	int now=0;
//	cout<<"fuck"<<endl;
	while (mat[od[now]]&&now<od.size()) now++;
//	cout<<now<<" "<<od.size()<<endl;
	for (int i=0;i<ev.size();i++){
		int x=ev[i];
		if (now>=od.size()) break;
		int u=od[now++];
		while (mat[u]&&now<od.size()) u=od[now++];
		int v=od[now++];
		while (mat[v]&&now<od.size()) v=od[now++];
		g[u][x]=g[x][u]=1; rd[x]++; rd[u]++;
		g[v][x]=g[x][v]=1; rd[x]++; rd[v]++;
	}
//	cout<<"fuck"<<endl;
	if (now<od.size()) fl=1;
	now=1;int to=1;
	for (int i=1;i<=n;i++){
		cout<<i<<" "<<rd[i]<<endl;
		if (rd[i]==0){
			while ((!mat[now])||(i==now)||(!mat[to])||(i==to)||g[now][to]||now==to){
				to++;
				if (to>n) now++,to=1;
				if (now>n){
					fl=1;
					break;
				}
			}
			g[i][now]=g[now][i]=1; rd[i]++; rd[now]++;
			g[i][to]=g[to][i]=1; rd[i]++; rd[to]++;
			g[now][to]=g[to][now]=1; rd[now]++; rd[to]++;
		}
	}
//	cout<<"fuck"<<endl;
	for (int i=1;i<=n;i++) rd[i]=0;
	if (fl) printf("No\n");
	else {
		printf("Yes\n");
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				printf("%d",g[i][j]);
				if (g[i][j]) rd[j]++;
			}
			printf("\n");
		}
/*		bool chk=1;
		for (int i=1;i<=n;i++){
//			cout<<i<<" "<<rd[i]<<endl;
			if (rd[i]%2==1) chk=0;
		}
		if (chk) printf("Good!\n");
		else printf("Wrong\n");
*/	}
	return 0;
}
