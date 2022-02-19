#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=3e3+5;
int n,m,down[MAXN][MAXN],fa[MAXN];
int a[MAXN],mn[MAXN],s[MAXN],sum[MAXN];
ll ans;
bool vis[MAXN];
int tag[MAXN][MAXN];
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
void uion(int l,int r){
	l=find(l); r=find(r);
	if (l==r) return;
	if (mn[l]<mn[r]) swap(l,r);
	ans+=(ll)(mn[l]-mn[r])*s[l]*(s[l]+1)/2;
	fa[l]=r; s[r]+=s[l];
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			char c=getchar(); while (c!='0'&&c!='1') c=getchar();
			tag[i][j]=c-'0';
		}
	}
	for (int i=1;i<=n;i++){
		int p=1,nex=0;
		while (p<=m){
			for (nex=p;tag[i][nex];nex++);
			for (int j=p;j<nex;j++) down[j][i]=nex-j;
			p=nex+1;
		}
	}
	for (int i=1;i<=m;i++){
		memset(vis,0,sizeof(vis)); memset(sum,0,sizeof(sum));
		memcpy(mn,down[i],sizeof(mn));
		for (int j=1;j<=n;j++) fa[j]=j,s[j]=1;
		for (int j=1;j<=n;j++) sum[mn[j]]++;
		for (int j=m;j>=0;j--) sum[j]+=sum[j+1];
		for (int j=1;j<=n;j++) a[sum[mn[j]]--]=j;
		for (int j=1;j<=n;j++){
			vis[a[j]]=1;
			if (vis[a[j]-1]) uion(a[j]-1,a[j]);
			if (vis[a[j]+1]) uion(a[j],a[j]+1);
		}
		int x=find(1);
		ans+=(ll)mn[x]*s[x]*(s[x]+1)/2;
	}
	printf("%lld\n",ans);
	return 0;
}
