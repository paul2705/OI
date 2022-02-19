#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e4+5;
const int MAXM=2e5+5;
int a[MAXN],t[MAXN],b[MAXN];
struct rec{
	int l,r,id;
} ask[MAXM];
int n,m,las[MAXN],ans[MAXM];
int sum(int x){
	int ans=0;
	for (;x>0;x-=x&-x) ans+=t[x];
	return ans;
}
void add(int x,int val){
//	cout<<__func__<<endl;
	for (;x<=n;x+=x&-x) t[x]+=val;
//	cout<<"out"<<endl;
}
bool cmp(rec a,rec b){ return a.r<b.r; }
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	int nn=unique(b+1,b+n+1)-b-1;
	for (int i=1;i<=n;i++){
		a[i]=lower_bound(b+1,b+nn+1,a[i])-b;
//		cout<<a[i]<<" ";
	}
//	cout<<endl;
	scanf("%d",&m);
	for (int i=1;i<=m;i++) scanf("%d%d",&ask[i].l,&ask[i].r),ask[i].id=i;
	sort(ask+1,ask+m+1,cmp);
	int now=1;
	for (int i=1;i<=m;i++){
//		cout<<": "<<i<<endl;
		int l=ask[i].l,r=ask[i].r;
		for (;now<=r;now++){
			int x=a[now];
			add(now,1);
			if (las[x]) add(las[x],-1);
			las[x]=now;
		}
		ans[ask[i].id]=sum(r)-sum(l-1);
	}
	for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}
