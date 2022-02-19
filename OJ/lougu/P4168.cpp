#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=4e4+5;
const int MAXT=40;
struct rec{
	int v,id;
} b[MAXN];
int cnt[MAXT][MAXT][MAXN];
int n,m,a[MAXN],bel[MAXN],bl[MAXT],br[MAXT];
int rid[MAXN],ans[MAXN];
bool cmp(rec a,rec b){ return a.v<b.v; }
int query(int x,int y){
//	cout<<x<<" "<<y<<endl;
	int l=bel[x],r=bel[y],res=0;
//	cout<<l<<" "<<r<<endl;
	if (r-l<=1){
		for (int i=1;i<=n;i++) ans[i]=0;
		for (int i=x;i<=y;i++) ans[a[i]]++;
		for (int i=1;i<=n;i++){
			if (ans[i]>ans[res]) res=i;
		}
	}
	else {
		for (int j=1;j<=n;j++) ans[j]=cnt[l][r-1][j];
		for (int i=x;i<bl[l];i++) ans[a[i]]++;
		for (int i=bl[r];i<=y;i++) ans[a[i]]++;
		for (int i=1;i<=n;i++){
			if (ans[i]>ans[res]) res=i;
		}
	}
//	for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
//	cout<<endl;
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	int T=pow(n,1.0/3),mx; T=n/T;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]); b[i]=(rec){a[i],i};
		bel[i]=(i-1)/T+1; mx=max(mx,bel[i]);
//		cout<<bel[i]<<" ";
	}
//	cout<<endl<<mx<<" fuck"<<endl;
	sort(b+1,b+n+1,cmp); 
	int res=0;
	for (int i=1;i<=n;i++){
		if (b[i].v!=b[i-1].v) a[b[i].id]=++res,rid[res]=b[i].v;
		else a[b[i].id]=a[b[i-1].id];
//		cout<<a[i]<<" ";
	}
//	cout<<endl;
	for (int i=1;i<=mx;i++) bl[i]=(i-1)*T+1,br[i]=i*T;
//	for (int i=1;i<=mx;i++) cout<<bl[i]<<" "<<br[i]<<endl;
	for (int i=1;i<=mx;i++){
		for (int j=i;j<=mx;j++){
			for (int i=1;i<=n;i++) ans[i]=0;
			for (int k=bl[i];k<=br[j];k++){
				ans[a[k]]++;
			}
			
		}
	}
	res=0;
	for (int i=0,l,r;i<m;i++){
		scanf("%d%d",&l,&r);
		l=(l+res-1)%n+1,r=(r+res-1)%n+1;
		if (l>r) swap(l,r);
		printf("%d\n",rid[query(l,r)]);
	}
	return 0;
}
