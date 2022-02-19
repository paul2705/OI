#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e2+5;
const int MAXM=1e3+5;
const int mod=31011;
struct rec{
	int u,v,w;
} ed[MAXM];
int n,m,ans=1,tot;
int fa[MAXN];
int use[MAXN];
int mat[MAXN][MAXN];
int ffa[MAXN];
bool cmp(rec a,rec b){ return a.w<b.w; }
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
void uion(int x,int y){ fa[find(x)]=find(y); }
int ffind(int x){ return ffa[x]==x?x:ffa[x]=ffind(ffa[x]); }
void fuion(int x,int y){ ffa[ffind(x)]=ffind(y); }
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		ed[i]=(rec){u,v,w};
	}
	sort(ed+1,ed+m+1,cmp);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int l=1,r=1;l<=m;l=r+1,r++){
		while (ed[l].w==ed[r].w) r++;
		r--;
//		cout<<l<<" "<<r<<endl;
		memset(mat,0,sizeof(mat));
		memset(use,0,sizeof(use));
		bool flag=0;
		int cnt=0;
		for (int i=l;i<=r;i++){
			int u=ed[i].u,v=ed[i].v;
			int fu=find(u),fv=find(v);
			if (!use[fu]) use[fu]=++cnt;
			if (!use[fv]) use[fv]=++cnt;
		}
		for (int i=1;i<=cnt;i++) ffa[i]=i;
		for (int i=l;i<=r;i++){
			int u=ed[i].u,v=ed[i].v;
			int fu=find(u),fv=find(v);
			if (fu!=fv) flag=1;
			fu=use[fu]; fv=use[fv];
			fuion(fu,fv);
			mat[fu][fv]--; mat[fv][fu]--;
			mat[fu][fu]++; mat[fv][fv]++;
		}
		for (int i=2;i<=cnt;i++){
			int fu=ffind(i-1),fv=ffind(i);
			if (fu!=fv){
				fuion(i-1,i);
				mat[fu][fv]--; mat[fv][fu]--;
				mat[fu][fu]++; mat[fv][fv]++;
			}
		}
		cnt--;
/*		for (int i=1;i<=cnt;i++){
			for (int j=1;j<=cnt;j++) cout<<mat[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;
*/		int ret=1;
		for (int i=1;i<=cnt;i++){
			int pos=i;
			for (int j=i+1;j<=cnt;j++){
				if (mat[j][i]) pos=j;
			}
			for (int j=1;j<=cnt;j++) swap(mat[i][j],mat[pos][j]);
			if (pos!=i) ret=-ret;
			for (int j=i+1;j<=cnt;j++){
				while (mat[j][i]){
					int t=mat[j][i]/mat[i][i];
					for (int k=1;k<=cnt;k++){
						mat[j][k]=(mat[j][k]-t*mat[i][k])%mod;
					}
					if (!mat[j][i]) break;
					ret=-ret;
					for (int k=1;k<=cnt;k++) swap(mat[j][k],mat[i][k]);
				}
			}
			ret=ret*mat[i][i]%mod;
		}		
/*		for (int i=1;i<=cnt;i++){
			for (int j=1;j<=cnt;j++) cout<<mat[i][j]<<" ";
			cout<<endl;
		}
*/		ret=(ret%mod+mod)%mod;
//		cout<<ret<<endl;
		if (flag) ans=ans*ret%mod;
		for (int i=l;i<=r;i++){
			int u=ed[i].u,v=ed[i].v;
			int fu=find(u),fv=find(v);
			if (fu==fv) continue;
			uion(u,v); tot++;
		}
	}
	if (tot!=n-1) return printf("0\n"),0;
	printf("%d\n",ans);
	return 0;
}
