#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll inf=1e18;
const int MAXN=4e5+5;
int a[MAXN];
ll g[MAXN][65];
int pos[MAXN];
ll n,m;
int main(){
	scanf("%lld%lld",&n,&m);
	for (int i=0;i<n;i++) scanf("%d",&a[i]),a[i+n]=a[i];
	for (int i=0;i<2*n;i++) pos[i]=-1;
	for (int i=0;i<2*n;i++){
//		if (i==5) cout<<pos[a[i]]<<" "<<a[i]<<endl;
		if (pos[a[i]]!=-1){
//			cout<<i<<"-<"<<pos[a[i]]<<" "<<a[i]<<endl;
			g[pos[a[i]]][0]=i-pos[a[i]]+1;
			pos[a[i]]=i;
		}
		else pos[a[i]]=i;
	}
	for (int i=0;i<n;i++){
		if (g[i][0]==0) g[i][0]=n*m+1;
//		cout<<i<<" "<<g[i][0]<<endl;
	}
	for (int k=1;k<=60;k++){
		for (int i=0;i<n;i++){
			g[i][k]=min(n*m+1,g[i][k-1]+g[(i+g[i][k-1])%n][k-1]);
		}
	}
	ll now=0;
	for (int k=60;k>=0;k--){
//		cout<<now<<" "<<g[now%n][k]<<endl;
		if (now+g[now%n][k]<n*m) now+=g[now%n][k];
//		cout<<k<<" "<<now<<endl;
	}
//	cout<<endl<<now<<endl;
	for (ll i=now;i<n*m;i++){
//		cout<<i<<endl;
		ll x=i%n;
		if (x+g[x][0]<=n) i=i+g[x][0]-1;
		else printf("%d ",a[x]);
	}
	printf("\n");
	return 0;
}
