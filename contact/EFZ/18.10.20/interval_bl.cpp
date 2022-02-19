#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
const ll mod=666623333;
int n,m,l[MAXN],r[MAXN];
bitset<100000000> use;
ll cnt,ans,inv[mod];
ll exgcd(ll a,ll b,ll &x,ll &y){
	if (b==0){
		x=1;y=0;
		return a;
	}
	ll q=exgcd(b,a%b,x,y);
	ll t=x;
	x=y%mod;
	y=(t-(a/b)*y%mod)%mod;
	return q;
}
int main(){
	freopen("interval.in","r",stdin);
	freopen("interval.out","w",stdout);
	scanf("%d%d",&n,&m);
//	inv[1]=1;
//	cout<<"fuck"<<endl;
//	for (int i=2;i<=mod;i++){
//		inv[i]=(-inv[mod%i]*(mod/i)%mod+mod)%mod;
//	}
//	cout<<"fuck"<<endl;
	for (int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
//	cout<<"fuck"<<endl;
	for (int i=1,L,R;i<=m;i++){
		scanf("%d%d",&L,&R);
		cnt=0; ans=0;
		for (int j=L;j<=R;j++){
			for (int k=j;k<=R;k++){
				cnt++;
//				cout<<ans<<" "<<cnt<<endl;
				int mn=1e9,mx=0;
				for (int sc=j;sc<=k;sc++){
					mn=min(mn,l[sc]); mx=max(mx,r[sc]);
					for (int pos=l[sc];pos<r[sc];pos++) use[pos]=1;
				}
//				cout<<"fuck"<<endl;
//				cout<<j<<" "<<k<<" "<<mn<<" "<<mx<<endl;
				for (int pos=mn;pos<=mx;pos++){
//					cout<<use[pos];
					if (use[pos]==1) ans=(ans+1)%mod;
					use[pos]=0;
				}
//				cout<<endl;
			}
		}
		ll x=0,y=0;
//		cout<<ans<<" "<<cnt<<endl;
		ll d=exgcd(cnt,mod,x,y);
		printf("%lld\n",(ans*x%mod+mod)%mod);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
