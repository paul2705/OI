#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e2+5;
struct rec{
	int l,r,x;
} a[MAXN];
int n,ans=0;
int b[MAXN*20];
int main(){
	freopen("blist.in","r",stdin);
	freopen("blist.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].x);
	for (int i=1;i<=n;i++){
		b[a[i].l]+=a[i].x; b[a[i].r+1]-=a[i].x;
	}
	for (int i=1;i<=1000;i++){
		b[i]+=b[i-1];
		ans=max(ans,b[i]);
	}
	printf("%d\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
