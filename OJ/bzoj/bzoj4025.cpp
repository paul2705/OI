#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=2e5+5;
int fa[MAXN],dis[MAXN],n,m,T,cnt;
struct rec{
	int u,v,l,r;
} a[MAXM];
vector<rec> tmp;
int k=0;
bool ans[MAXN];
struct ch{
	int x,f;
};
int find(int x){
	if (fa[x]==x) return x;
	k^=dis[x];
	return find(fa[x]);
}
void solve(int l,int r,vector<rec> a){
//	cout<<l<<" "<<r<<endl;
	vector<rec> cl,cr;
	vector<ch> chg;
	int mid=(l+r)>>1;
	for (int i=0;i<a.size();i++){
		if (a[i].l<=l&&r<=a[i].r){
			k=0;
			int fu=find(a[i].u),fv=find(a[i].v);
			if (fu==fv&&k==0){
				for (int j=l;j<=r;j++) ans[j]=1;
				for (int j=0;j<chg.size();j++){
					int x=chg[j].x,fx=chg[j].f;
					fa[x]=x; dis[x]=0;
				}
				return;
			}
			if (fu!=fv){
				int x=rand()%2;
				if (x) fa[fu]=fv,dis[fu]=k^1,chg.push_back((ch){fu,fv});
				else fa[fv]=fu,dis[fv]=k^1,chg.push_back((ch){fv,fu});
			}
		}
		else if (a[i].r<=mid) cl.push_back(a[i]);
		else if (a[i].l>mid) cr.push_back(a[i]);
		else cl.push_back(a[i]),cr.push_back(a[i]);
	}
	if (l!=r) solve(l,mid,cl);
	if (l!=r) solve(mid+1,r,cr);
	for (int i=0;i<chg.size();i++){
		int x=chg[i].x,fx=chg[i].f;
		fa[x]=x; dis[x]=0;
	}
}
int main(){
//	srand(ctime());
	scanf("%d%d%d",&n,&m,&T);
	for (int i=1;i<=m;i++){
		scanf("%d%d%d%d",&a[i].u,&a[i].v,&a[i].l,&a[i].r);
		a[i].r--;
		if (a[i].l<=a[i].r) tmp.push_back(a[i]);
	}
	for (int i=1;i<=n;i++) fa[i]=i;
	solve(0,T-1,tmp);
	for (int i=0;i<T;i++){
		if (ans[i]) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
