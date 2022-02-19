#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=6e5+6;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int rd[MAXN];
int n,m,cnt[MAXN],id[MAXN];
int bel[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
	rd[v]++;
}
bool fl=0,use[MAXN];
void dfs(int u,int col){
	if (bel[u]==col) fl=1;
	use[u]=1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (use[v]) continue;
		dfs(v,col);
	}
}
void dfs1(int u,int col,int b){
	if (bel[u]!=col) return;
	use[u]=1; bel[u]=b;
	int tmp=b;
	if (tmp==col) tmp=3;
	else tmp=col;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (use[v]) continue;
		if (bel[u]!=col) return;
		dfs1(v,col,tmp);
	}
}
void dfs2(int u,int col){
	use[u]=1; bel[u]=col;
	int tmp=col%3+1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (use[v]) continue;
		dfs2(v,tmp);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	for (int i=1;i<=n;i++){
		cnt[rd[i]]++;
	}
	int res=0;
	for (int i=1;i<=n;i++){
		if (cnt[i]) id[i]=++res;
	}
//	cout<<res<<endl;
	if (res>=4) return printf("-1\n"),0;
	else if (res==3){
		for (int i=1;i<=n;i++){
			bel[i]=id[rd[i]];
		}
		for (int i=1;i<=n;i++){
			if (!use[i]) dfs(i,id[i]);
		}
		if (fl) printf("-1\n");
		else {
			for (int i=1;i<=n;i++) cout<<bel[i]<<" ";
			cout<<endl;
		}
	}
	else if (res==2){
		int cnt[3]={0,0,0};
		for (int i=1;i<=n;i++){
			bel[i]=id[rd[i]];
			cnt[bel[i]]++;
		}
		if (cnt[1]%2==1&&cnt[2]%2==1) printf("-1\n");
		else {
			int x=1,y=2;
			if (cnt[x]%2==1) swap(x,y);
			for (int i=1;i<=n;i++){
				if (bel[i]!=x) continue;
				if (!use[i]) dfs1(i,x,3);
			}
			int tmp=0;
			for (int i=1;i<=n;i++) tmp+=(bel[i]==3);
			if (2*tmp!=cnt[x]){
				if (cnt[y]%2==0){
					for (int i=1;i<=n;i++){
						if (bel[i]!=y) bel[i]=x;
						use[i]=0;
					}
					for (int i=1;i<=n;i++){
						if (bel[i]!=y) continue;
						if (!use[i]) dfs1(i,x,3);
					}
					int tmp1=0;
					for (int i=1;i<=n;i++) tmp+=(bel[i]==3);
					if (2*tmp1!=cnt[y]) printf("-1\n");
					else {
						for (int i=1;i<=n;i++) cout<<bel[i]<<" ";
						cout<<endl;
					}
				}
				else printf("-1\n");
			}
			else {
				for (int i=1;i<=n;i++) cout<<bel[i]<<" ";
				cout<<endl;
			}
		}
	}
	else {
		if (n%3!=0) printf("-1\n");
		else {
			for (int i=1;i<=n;i++){
				if (!use[i]) dfs2(i,1);
			}
			int cnt[4]={0,0,0,0};
			for (int i=1;i<=n;i++){
				cnt[bel[i]]++;
			}
			if (cnt[1]==cnt[2]&&cnt[2]==cnt[3]){
				for (int i=1;i<=n;i++) cout<<bel[i]<<" ";
				cout<<endl;
			}
			else printf("-1\n");
		}
	}
	return 0;
}
