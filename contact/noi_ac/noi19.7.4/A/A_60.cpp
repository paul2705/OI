#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=8e3+5;
const ll mod=1e9+7;
ll f[3][MAXN];
int n,m;
int s[MAXN],vs[MAXN];
int kx[MAXN],ky[MAXN];
int main(){
	scanf("%d%d",&n,&m);
	bool flag=1; vs[n]=n; s[n]=n;
	for (int i=1;i<=n;i++) kx[i]=ky[i]=1;
	for (int i=1;i<=m;i++){
		int x,y; scanf("%d%d",&x,&y);
		if (!s[x]) s[x]=y;
		else flag=0;
		if (!vs[y]) vs[y]=x;
		else flag=0;
		kx[x]=0; ky[y]=0;
	}
	if (s[n]!=n&&s[n]!=0) flag=0;
	if (!flag) return printf("0\n"),0;
	for (int i=1;i<=n;i++) kx[i]+=kx[i-1],ky[i]+=ky[i-1];
	if (s[1]) f[1][s[1]]=1;
	else for (int i=1;i<n;i++) f[1][i]=1;
//	cout<<f[1][2]<<endl;
	for (int i=2;i<=n;i++){
		int c=i&1; int o=c^1;
		ll sum=0;
		for (int j=1;j<=n;j++) f[c][j]=0;
		for (int j=1;j<n;j++){
			if (vs[j]>i-1) continue;
			if (s[i]){
				if (s[i]>j) f[c][s[i]]=(f[c][s[i]]+f[o][j]*2%mod)%mod;
				else f[c][j]=(f[c][j]+f[o][j])%mod;
			}
			else {
//				cout<<i<<" "<<j<<endl;
//				for (int k=j+1;k<=(i==n?n:n-1);k++){
//					f[i][k]=(f[i][k]+f[i-1][j]*2%mod)%mod;
//				}
				f[c][j]=(f[c][j]+sum*2%mod)%mod;
				sum+=f[o][j];
				if (ky[j]>kx[i-1]) f[c][j]=(f[c][j]+(ll)(ky[j]-kx[i-1])*f[o][j]%mod)%mod;
			}
		}
//		for (int j=1;j<=n;j++) cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
	}
	printf("%lld\n",f[n&1][n]);
	return 0;
}
