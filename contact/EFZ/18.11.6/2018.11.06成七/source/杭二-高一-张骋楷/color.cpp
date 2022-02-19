#include<cstdio> 
#include<iostream> 
#include<cstring> 
#include<cmath> 
#include<vector>
#include<cctype> 
#include<algorithm> 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define interesting int
const int N=1E5+10,lst=20;
int n,m,a[N],siz[N];
int hd[N],nxt[N<<1],to[N<<1],cnt;
int dep[N],fa[N],used[N];
vector<int>f[N];
int node[N][2],fo[N][lst+1],num[N];
inline void init(int x,int y){
	cnt++;
	nxt[cnt]=hd[x];
	hd[x]=cnt;
	to[cnt]=y;
}
inline void dfs(int x,int pre){
	dep[x]=dep[pre]+1;fa[x]=pre;
	fo[x][0]=pre;
	for(int i=hd[x];i;i=nxt[i]){
		int u=to[i];
		if(u!=pre){
			dfs(u,x);
		}
	}
}
inline int ck(const int x,register int y){
	if(dep[x]>dep[y])return 0;
	for(int i=lst;i>=0;i--){
		if(dep[fo[y][i]]>=dep[x]) y=fo[y][i];
		if(dep[x]==dep[y]) break;
	}
	return x==y;
}
inline int cmp(int x,int y){return dep[x]>dep[y];}
inline int cnp(const int&x,const int&y){
	if(!siz[x]) return 1;
	if(!siz[y]) return 0;
	for(int i=0;i<siz[x];i++){
		if(ck(f[x][i],node[y][0])||ck(f[x][i],node[y][1])) return 0;
	}
	for(int i=0;i<siz[y];i++){
		if(ck(f[y][i],node[x][0])||ck(f[y][i],node[x][1])) return 1;
	}
	return 0;
}
inline void up(int x){
	for(int i=x;;i=fa[i]){
		used[i]=x;
		if(i==1) return;
	}
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		f[a[i]].push_back(i);
	}
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		init(x,y);
		init(y,x);
	}
	dfs(1,1);
	for(int j=1;j<=lst;j++){
		for(int i=1;i<=n;i++){
			fo[i][j]=fo[fo[i][j-1]][j-1];
		}
	}
	for(int i=1;i<=m;i++){
		num[i]=i;siz[i]=f[i].size();
		if(!siz[i]){
			node[i][1]=node[i][0]=1;
			continue;
		}
		sort(f[i].begin(),f[i].end(),cmp);
		if(siz[i]==1){
			node[i][1]=node[i][0]=f[i][0];
			continue;
		}
		node[i][0]=f[i][0];up(f[i][0]);
		for(int j=1;j<siz[i];j++){
			if(used[f[i][j]]!=node[i][0]){
				node[i][1]=f[i][j];
				break;
			}
		}
		if(!node[i][1]) node[i][1]=f[i][siz[i]-1];
	}
	sort(num+1,num+1+m,cnp);
	for(int i=1;i<=m;i++){
		int t=num[i];
		printf("%d %d %d\n",t,node[t][1],node[t][0]);
	}
    return 0;
} 
