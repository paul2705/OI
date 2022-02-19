#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int MAXN=5e3+5;
const int bas=23;
int a[MAXN],b[MAXN];
int n,m;
int lisa[MAXN],lisb[MAXN],cnta,cntb;
map<ll,int> mp,mp1;
ll ans;
void solve1(){
	for (int s=1;s<(1<<n);s++){
		ll hasa=0;
		cnta=0;
		for (int i=0;i<n;i++){
			if (s&(1<<i)){
				lisa[++cnta]=a[i+1];
				hasa=hasa*bas+a[i+1];
			}
		}
		if (mp[hasa]) continue;
		else mp[hasa]++;
		mp1.clear();
		for (int t=1;t<(1<<m);t++){
			ll hasb=0;
			cntb=0;
			for (int i=0;i<m;i++){
				if (t&(1<<i)){
					lisb[++cntb]=b[i+1];
					hasb=hasb*bas+b[i+1];
				}
			}
			if (mp1[hasb]) continue;
			else mp1[hasb]++;
			if (cnta>cntb){
//				bitset<5> t1=s,t2=t;
//				cout<<"1:"<<endl<<t1<<endl<<t2<<endl<<endl;
				ans=(ans+1)%mod;
				continue;
			}
			if (cnta<cntb) continue;
			for (int i=1;i<=cnta;i++){
				if (lisa[i]>lisb[i]){
//					bitset<5> t1=s,t2=t;
//					cout<<"2:"<<endl<<t1<<endl<<t2<<endl<<endl;
					ans=(ans+1)%mod;
					break;
				}
				if (lisa[i]<lisb[i]) break;
			}
		}
	}
	printf("%lld\n",(ans%mod+mod)%mod);
}
void solve2(){

}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++) scanf("%d",&b[i]);
	if (n+m<=20) solve1();
	else solve2();
	return 0;
}
