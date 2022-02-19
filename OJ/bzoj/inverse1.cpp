#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e2+5;
int a[MAXN],b[MAXN],c[MAXN],r[MAXN];
bool use[MAXN];
int n,T,cnt,ans;
void merge(int l,int r){
	if (l==r) return;
	int mid=(l+r)>>1;
	merge(l,mid); merge(mid+1,r);
	int tot=r-l+1;
	int n=l,m=mid+1,i=0;
	while (n<=mid||m<=r){
		if (m>r||(n<=mid&&a[n]<=a[m])) c[i++]=b[n++];
		else c[i++]=b[m++],cnt+=mid-n+1;
	}
	n=l;
	for (int i=0;i<tot;i++) b[n++]=c[i];
}
bool check(){
	int res=0; bool f=0;
	for (int i=1;i<=n;i++){
		if (b[i]>a[i]){ f=1; break; }
		else if (b[i]<a[i]){ f=0; break; }
	}
	if (!f) return 0;
	for (int i=1;i<=n;i++) res+=abs(i-b[i]);
	res/=2; cnt=0;
	merge(1,n);
	return cnt==res;
}
void dg(int d){
	if (d==n+1) ans+=check();
	for (int i=1;i<=n;i++){
		if (!use[i]){
			use[i]=1; b[d]=i;
			dg(d+1);
			use[i]=0;
		}
	}
}
int main(){
	scanf("%d",&T);
	while (T--){
		ans=0;
		memset(use,0,sizeof(use));
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		dg(1);
		printf("%d\n",ans);
	}
	return 0;
}
