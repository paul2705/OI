#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e6+6;
ll pri[MAXN];
ll n,b;
bool use[MAXN];
ll a[MAXN],c[MAXN],cnt;
ll mn=1e18;
ll calc(ll n,ll x){
	ll res=0;
	while (n){
		res+=n/x;
		n/=x;
	}
	return res;
}
int main(){
	cin>>n>>b;
	for (int i=2;i<=1e6;i++){
		if (!use[i]) pri[++pri[0]]=i;
		for (int j=1;j<=pri[0]&&i*pri[j]<=1e6;j++){
			use[i*pri[j]]=1;
			if (i%pri[j]==0) break;
		}
	}
	for (int i=1;i<=pri[0];i++){
		if (b%pri[i]==0){
			ll cn=0;
			a[cnt++]=pri[i];
			while (b%pri[i]==0){
				b/=pri[i];
				cn++;
			}
			c[cnt-1]=cn;
		}
		if (b==1) break;
	}
	if (b>1) a[cnt++]=b,c[cnt-1]=1;
//	for (int i=0;i<cnt;i++) cout<<a[i]<<" "; cout<<endl;
	for (int i=0;i<cnt;i++){
//		cout<<calc(n,a[i])/c[i]<<endl;
		mn=min(mn,calc(n,a[i])/c[i]);
	}
	cout<<mn<<endl;
	return 0;
}
