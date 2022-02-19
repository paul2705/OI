#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int MAXN=2e6+5;
ll id1[MAXN],id2[MAXN];
ll n,Sq,w[MAXN],g[MAXN];
ll pri[MAXN],cnt;
bool use[MAXN];
int main(){
	scanf("%lld",&n); Sq=sqrt(n);
	for (ll i=2;i<=Sq;i++){
		if (!use[i]) pri[++pri[0]]=i;
//		cout<<i<<":";
		for (ll j=1;j<=pri[0]&&pri[j]*i<=Sq;j++){
			use[i*pri[j]]=1;
//			cout<<i*pri[j]<<" ";
			if (i%pri[j]==0) break;
		}
//		cout<<endl;
	
	}
//	for (int j=1;j<=pri[0];j++) cout<<pri[j]<<endl;
//	return 0;
//	cout<<pri[0]<<endl;
	for (ll i=1,j=1;i<=n;i=j+1){
		j=n/(n/i); w[++cnt]=n/i;
//		cout<<w[cnt]<<" "<<n/w[cnt]<<endl;
		if (w[cnt]<=Sq) id1[w[cnt]]=cnt;
		else id2[n/w[cnt]]=cnt;
		g[cnt]=w[cnt]-1;
	}
//	cout<<cnt<<" "<<pri[0]<<endl;
//	cout<<"cnt: "<<cnt<<endl;
//	for (int i=1;i<=pri[0];i++) cout<<pri[i]<<endl;
	for (int j=1;j<=pri[0];j++){
//		cout<<j<<endl;
		for (int i=1;i<=cnt&&(ll)pri[j]*(ll)pri[j]<=w[i];i++){
//			cout<<w[i]/pri[j]<<endl;
			int k=w[i]/pri[j]<=Sq?id1[w[i]/pri[j]]:id2[n/(w[i]/pri[j])];
			g[i]=g[i]-g[k]+j-1;
		}
	}
	printf("%lld\n",g[1]);
	return 0;
}
