#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=4e2+5;
const int MAXK=1e6+6;
int a[MAXN][MAXN],id[MAXN];
int n,m,K;
ll ans,cnt[MAXK];
int main(){
	scanf("%d%d%d",&n,&m,&K);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
			a[i][j]=a[i][j]%K>=0?a[i][j]%K:a[i][j]%K+K;
		}
	}
	for (int i=1;i<=m;i++){
		for (int j=i;j<=m;j++){
			for (int k=1;k<=n;k++){
				int sum=a[k][j]-a[k][i-1];
				sum=(sum+K)%K;
				id[k]=sum;
				cnt[id[k]]=0;
			}
			for (int k=1;k<=n;k++){
				if (id[k]==0) ans++;
				ans+=cnt[id[k]]; cnt[id[k]]++;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
