#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod=2019201997;
const int MAXN=7505;
int n,k;
struct rec{
	int u,v,w;
} ed[MAXN*MAXN];
int cnt;
int fa[MAXN];
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
void uion(int x,int y){ fa[find(x)]=find(y); }
bool cmp(rec a,rec b){ return a.w<b.w; }
bool check(int mid,int& ans){
	cnt=0;
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<n;i++){
		if ((ll)2019201913*i%mod>mid) continue;
		for (int j=i+1;j<=n;j++){
			ll w=(ll)2019201913*i%mod+(ll)2019201949*j%mod;
			w%=mod;
			if (w>mid) continue;
			cout<<w<<endl;
			ed[cnt++]=(rec){i,j,(int)w};
		}
	}
	sort(ed,ed+cnt,cmp);
	int ret=n,mx=0;
	for (int i=0;i<cnt;i++){
		int u=ed[i].u,v=ed[i].v,w=ed[i].w;
		if (find(u)!=find(v)){
			uion(u,v);
			mx=max(mx,w);
			ret--;
		}
		if (ret==k-1) break;
	}
	ans=mx;
	cout<<ret<<endl;
	return ret==k-1;
}
int main(){
	scanf("%d%d",&n,&k);
	int l=0,r=2019201997,mid,ans;
	while (r-l>1){
		cout<<l<<" "<<r<<endl;
		mid=((ll)l+r)>>1;
		cout<<mid<<endl;
		if (check(mid,ans)) r=mid;
		else l=mid;
		cout<<ans<<" "<<mid<<" "<<l<<" "<<r<<";"<<endl;
	}
	printf("%d\n",ans);
	return 0;
}

