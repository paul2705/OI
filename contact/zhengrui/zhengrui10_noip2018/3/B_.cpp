#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e3+5;
const int mod=998244353;
int l[MAXN],r[MAXN],a[MAXN];
int n,m,f[MAXN][MAXN];
int ans;
int find(int id,int x){
	int l=0,r=m+1,mid;
	while (l+1<r){
		mid=(l+r)>>1;
		if (id==2) if (a[mid]<x) l=mid;
		else r=mid;
		else if (a[mid]<=x) l=mid;
		else r=mid;
	}
	if (id==1) return l;
	else return r;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
	for (int i=1;i<=m;i++) scanf("%d",&a[i]);
	sort(a+1,a+m+1);
	for (int i=1;i<=n;i++){
		int lm=find(2,l[i]),rm=find(1,r[i]);
//		cout<<lm<<" "<<rm<<endl;
		for (int j=1;j<=m;j++){
			if (lm<=j&&j<=rm) f[i][j]=1;
			if (lm<=j&&j<=rm) f[i][j]=(f[i][j]+f[i-1][j]*2%mod)%mod;
			else f[i][j]=f[i-1][j];
//			cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
//			ans=(ans+f[i][j])%mod;
		}
	}
	for (int j=1;j<=m;j++) ans=(ans+f[n][j])%mod;
	for (int i=1;i<=n;i++){
		int lm=find(2,l[i]),rm=find(1,r[i]);
		ans=((ans-(rm-lm))%mod+mod)%mod;
	}
	printf("%d\n",ans);
	return 0;
}
