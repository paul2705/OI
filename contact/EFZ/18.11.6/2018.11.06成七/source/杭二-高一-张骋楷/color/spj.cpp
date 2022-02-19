#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1E5+10;
int n,m;
int a[N],fa[N],b[N],dep[N];
int hd[N],nxt[N<<1],to[N<<1],cnt;
inline void init(int x,int y){
	cnt++;
	nxt[cnt]=hd[x];
	hd[x]=cnt;
	to[cnt]=y;
}
inline void dfs(int x,int pre){
	fa[x]=pre;dep[x]=dep[pre]+1;
	for(int i=hd[x];i;i=nxt[i]){
		int u=to[i];
		if(u!=pre){
			dfs(u,x);
		}
	}
}
inline void cover(int x,int y,int c){
	while(x!=y){
		if(dep[x]<dep[y]) swap(x,y);
		b[x]=c;x=fa[x];
	}
	b[x]=c;
}
int main(){
    freopen("color.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		init(x,y);
		init(y,x);
	}
	dfs(1,1);
    freopen("color.out","r",stdin);
	while(m--){
		int c,x,y;
		scanf("%d %d %d",&c,&x,&y);
		cover(x,y,c);
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i]){
			printf("WA : %d is %d , but you puts %d\n",i,a[i],b[i]);
			return 0;
		}
	}
	puts("correct");
	return 0;
}
