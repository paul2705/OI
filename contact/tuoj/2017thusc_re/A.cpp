#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=256;
int a[MAXN][MAXN],c[MAXN][MAXN];
int n,m,k,col[MAXN*MAXN],val[MAXN*MAXN];
int T;
void solve1(){
	int len=n+5,ans=n*m+5;
	for (int l=1;l<=m;l++){
		for (int r=l;r<=m;r++){
//			cout<<l<<" "<<r<<endl;
			int cnt=0;
			bool f=0;
			for (int i=l;i<=r;i++){
				if (c[1][i]==-1) f=1;
				col[++cnt]=c[1][i];
				val[cnt]=a[1][i];
			}
//			cout<<f<<endl;
			if (f) continue;
			sort(col+1,col+cnt+1);
			sort(val+1,val+cnt+1);
			int nn=unique(col+1,col+cnt+1)-col-1;
//			cout<<l<<" "<<r<<" "<<nn<<endl;
			if (nn>=k) len=min(len,r-l+1);
		}
	}
	for (int i=1;i<=m;i++){
		int j=i+len-1;
		bool f=0;
		if (j>m) break;
		int cnt=0;
		for (int l=i;l<=j;l++){
			if (c[1][l]==-1) f=1;
			col[++cnt]=c[1][l];
			val[cnt]=a[1][l];
		}
		if (f) continue;
		sort(col+1,col+cnt+1);
		int nn=unique(col+1,col+cnt+1)-col-1;
		if (nn<k) continue;
		sort(val+1,val+cnt+1);
//		cout<<i<<" "<<j<<" "<<val[(cnt+1)/2]<<endl;
		ans=min(ans,val[(cnt+1)/2]);
	}
	printf("%d %d\n",len,ans);
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d",&n,&m,&k);
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++) scanf("%d",&c[i][j]);
		}
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
		}
		if (n==1) solve1();
	}
	return 0;
}
