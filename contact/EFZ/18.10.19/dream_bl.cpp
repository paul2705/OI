#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=105;
int n,m,ans;
struct rec{
	int l,r;
} a[MAXN];
int t[MAXN];
bool use[MAXN];
bool cmp(rec a,rec b){return a.l==b.l?a.r<b.r:a.l<b.l; }
void dfs(int d,int now){
	if (d==m+1){
		ans=max(ans,now);
		return;
	}
	for (int i=1;i<=n;i++){
		if (!use[i]&&a[i].l<=t[d]&&a[i].r>=t[d]){
			use[i]=1;
			dfs(d+1,now+1);
			use[i]=0;
		}
	}
	dfs(d+1,now);
}
int main(){
	freopen("dream.in","r",stdin);
	freopen("dream1.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].l,&a[i].r);
	for (int i=1;i<=m;i++) scanf("%d",&t[i]);
	sort(t+1,t+m+1); sort(a+1,a+n+1,cmp);
	dfs(1,0);
	printf("%d\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
