#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=405;
int n,m,f[MAXN][MAXN];
int a[MAXN];
int s[MAXN];
int main(){
	scanf("%d%d",&n,&m);
	m++;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for (int i=0;i<=n;i++){
		for (int j=0;j<=n;j++) f[i][j]=1e9;
	}
	f[0][0]=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			int mx=a[i];
			for (int k=i-1;k>=0;k--){
				f[i][j]=min(f[i][j],f[k][j-1]+mx*(i-k)-s[i]+s[k]);
				mx=max(mx,a[k]);
			}
//			cout<<f[i][j]<<" ";
		}
//		cout<<endl;
	}
	int ans=1e9;
	for (int i=1;i<=m;i++){
		ans=min(ans,f[n][i]);
	}
	printf("%d\n",ans);
	return 0;
}
