#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int a[MAXN],tmp[MAXN];
int n,m,ans,cnt;
void dfs(int d,int c){
	if (c<=0){ ans=min(ans,d); return; }
	if (d+((c+1)/2)*2>ans) return;
//	for (int i=0;i<cnt;i++) cout<<tmp[i]<<" ";
//	cout<<endl;
//	cout<<d<<" "<<c<<endl;
	for (int i=0;i<cnt;i++){
		for (int j=0;j<cnt;j++){
			if (i==j) continue;
			if (tmp[i]==tmp[j]&&tmp[i]==0) continue;
			int C=0;
			if (tmp[i]==0) C++;
			if (tmp[j]==0) C++;
			int t1=tmp[i],t2=tmp[j];
			int t=tmp[i]^tmp[j];
			tmp[i]=tmp[j]=t;
			if (t==0) dfs(d+1,c-(2-C));
			else dfs(d+1,c);
			tmp[i]=t1; tmp[j]=t2;
		}
	}
}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.ans","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++){
		int l,r; scanf("%d%d",&l,&r);
		cnt=0;
		for (int j=l;j<=r;j++){
			if (a[j]==0) continue;
			tmp[cnt++]=a[j];
		}
		ans=((cnt+1)/2)*2;
		dfs(0,cnt);
		printf("%d\n",ans);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
