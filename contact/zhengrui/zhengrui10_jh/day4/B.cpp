#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
int g[MAXN][MAXN],rg[MAXN][MAXN];
int rd[MAXN],cnt,top[MAXN];
int n,bel[MAXN],sz[MAXN];
bool use[MAXN],fl=0;
void dfs1(int u,int p){
	use[u]=1;
	for (int i=1;i<=n;i++){
		if (rg[u][i]&&!use[i]) dfs1(i,u);
	}
	if (rd[u]%2==1){
		g[u][p]=g[p][u]=2;
//		cout<<u<<" "<<p<<endl;
		rd[u]++; rd[p]++;
		if (p==0) fl=1;
	}
}
void dfs2(int u,int p){
	use[u]=1; bel[u]=cnt; sz[cnt]++;
	for (int i=1;i<=n;i++){
		if (g[u][i]&&!use[i]) dfs2(i,u);
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			char c=getchar(); while (c!='0'&&c!='1') c=getchar();
			g[i][j]=c-'0'; rd[j]+=g[i][j];
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (g[i][j]) continue;
			rg[i][j]=1;
		}
	}
	for (int i=1;i<=n;i++){
		if (!use[i]) dfs1(i,0);
	}
	memset(use,0,sizeof(use));
	for (int i=1;i<=n;i++){
		if (!use[i]){
			top[++cnt]=i;
			dfs2(i,0);
		}
	}
//	cout<<fl<<endl;
	if (cnt>=3){
		for (int i=1;i<=cnt;i++){
			g[top[i]][top[i%cnt+1]]=1;
			g[top[i%cnt+1]][top[i]]=1;
			rd[top[i%cnt+1]]++;
			rd[top[i]]++;
		}
	}
	else if (cnt==2&&sz[1]>1&&sz[2]>1){
		int tmp1=0,tmp2=0;
		for (int i=1;i<=n;i++){
			if (g[top[1]][i]==0&&i!=top[1]&&bel[i]==1) tmp1=i;
			if (g[top[2]][i]==0&&i!=top[2]&&bel[i]==2) tmp2=i;
		}
		g[top[1]][tmp2]=g[tmp2][top[1]]=1;
		g[top[1]][top[2]]=g[top[2]][top[1]]=1;
		g[tmp1][top[2]]=g[top[2]][tmp1]=1;
		g[tmp1][tmp2]=g[tmp2][tmp1]=1;
	}
	else if (cnt==2){
		int x=1,y=2,tmp=0;
		if (sz[x]>1) swap(x,y);
		for (int i=1;i<=n;i++){
			if (g[top[y]][i]==0&&i!=top[y]&&bel[i]==y) tmp=i;
		}
		if (tmp){
			g[top[x]][top[y]]=g[top[y]][top[x]]=1;
			g[top[x]][tmp]=g[tmp][top[x]]=1;
			g[top[y]][tmp]=g[tmp][top[y]]=1;
		}
		else {
			int tmp1=0,tmp2=0;
			for (int i=1;i<=n;i++){
				if (bel[i]!=y) continue;
				for (int j=1;j<=n;j++){
					if (bel[j]!=y) continue;
					if (g[i][j]==2) tmp1=i,tmp2=j;
				}
			}
			if (!tmp1&&!tmp2) fl=1;
			else {
				g[tmp1][tmp2]=g[tmp2][tmp1]=0;
				g[tmp1][top[x]]=g[top[x]][tmp1]=1;
				g[top[x]][tmp2]=g[tmp2][top[x]]=1;
			}
		}
	}		
//	cout<<fl<<endl;
	if (fl) return printf("No\n"),0;
//	for (int i=1;i<=n;i++) rd[i]=0;
	printf("Yes\n");
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) printf("%d",g[i][j]>0?1:0);
		printf("\n");
	}
//	for (int i=1;i<=n;i++){
//		if (rd[i]%2==1) return printf("Wrong\n"),0;
//		else return printf("Good!\n"),0;
//	}
	return 0;
}
