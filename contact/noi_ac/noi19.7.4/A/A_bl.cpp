#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int MAXN=15;
int n,m,a[MAXN],b[MAXN];
int lim[MAXN];
bool use[MAXN];
int ans;
int cnt[1000000];
void dfs(int d){
	if (d==n){
		for (int i=1;i<=n;i++) b[i]=a[i];
		for (int i=1;i<n;i++){
			if (b[i]>b[i+1]) swap(b[i],b[i+1]);
		}
		bool flag=1;
		for (int i=1;i<=n;i++){
			if (lim[i]==0) continue;
			if (lim[i]!=b[i]) flag=0;
		}
		if (flag){
/*			cout<<"------"<<__func__<<"-------"<<endl;
			for (int i=1;i<=n;i++){
				printf("%d ",a[i]);
			} cout<<endl;
			int ret=0;
			for (int i=1;i<=n;i++){
				printf("%d ",b[i]); ret=ret*10+b[i];
			} cout<<endl;
			cnt[ret]++;
*/			ans++;
		}
	}
	for (int i=1;i<=n;i++){
		if (use[i]) continue;
		use[i]=1; a[d+1]=i;
		dfs(d+1);
		use[i]=0;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int x,y; scanf("%d%d",&x,&y);
		lim[x]=y;
	}
	dfs(0);
	printf("%d\n",ans);
/*	int bd=1;
	for (int i=1;i<=n;i++) bd=bd*10;
	for (int i=1;i<=bd;i++){
		if (!cnt[i]) continue;
		cout<<i<<" "<<cnt[i]<<endl;
	}
*/	return 0;
}
