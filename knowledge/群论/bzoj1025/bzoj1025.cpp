#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e3+4;
int pri[MAXN];
bool use[MAXN];
int n;
ll f[MAXN][MAXN];
int main(){
	scanf("%d",&n);
	for (int i=2;i<=n;i++){
		if (!use[i]) pri[++pri[0]]=i;
		for (int j=1;j<=pri[0]&&i*pri[j]<=n;j++){
			use[i*pri[j]]=1;
			if (i%pri[j]==0) break;
		}
	}
//	cout<<pri[0]<<endl;
	f[0][0]=1;
	for (int i=1;i<=pri[0];i++){
		for (int j=0;j<=n;j++) f[i][j]=f[i-1][j];
		for (int j=pri[i];j<=n;j*=pri[i]){
			for (int k=0;k<=n-j;k++){
				f[i][j+k]+=f[i-1][k];
			}
		}
	}
	ll ans=0;
	for (int i=0;i<=n;i++) ans+=f[pri[0]][i];
	printf("%lld\n",ans);
	return 0;
}
