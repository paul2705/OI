#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
struct rec{
	int l,r,d;
} a[MAXN];
int T,n,ans,cnt;
int calc(int pos){
	int ret=0;
	for (int i=1;i<=n;i++){
		if (a[i].l<=pos){
			ret+=(min(a[i].r,pos)-a[i].l)/a[i].d+1;
		}
	}
	return ret;
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		int mx=0;
		for (int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].d);
			mx=max(mx,a[i].r);
		}
		int l=0,r=mx,mid;
		while (l+1<r){
			mid=((ll)l+(ll)r)>>1ll;
			if (calc(mid)&1) r=mid;
			else l=mid;
		}
		ans=r; cnt=0;
		for (int i=1;i<=n;i++){
			if (a[i].l>r||a[i].r<r) continue;
			if ((r-a[i].l)%a[i].d==0) cnt++;
		}
		if (cnt&1) printf("%d %d\n",ans,cnt);
		else printf("Poor QIN Teng:(\n");
	}
	return 0;
}
