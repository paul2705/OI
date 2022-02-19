#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> ma;
const ll MAXN=1e3+5;
const ll mod=65521;
const ll T[10]={1,1,1,3,16,125};
ll k,n;
ll a[MAXN];
ma mat(MAXN,vec(MAXN));
ll lik[MAXN][10],cnt=0;
ll res[MAXN],b[MAXN];
ll f[MAXN],ans;
map<ll,ll> mp;
void dfs(){
	ll tmp=0;
	for (ll i=1;i<=k;i++) a[i]=res[i];
	for (ll i=1;i<=k+1;i++) b[i]=0;
	ll cn=0;
	for (ll i=1;i<=k;i++){
		if (b[a[i]]>0) continue;
		b[a[i]]=++cn;
	}
	for (ll i=1;i<=k;i++) a[i]=b[a[i]];
	for (ll i=1;i<=k;i++) tmp=tmp*10+a[i];
	if (mp[tmp]>0) return;
	else mp[tmp]=cnt+1;
	cnt++;
//	cout<<cnt<<endl;
	for (ll i=1;i<=k;i++) lik[cnt][i]=a[i];
	for (ll i=1;i<=k;i++){
		for (ll j=i+1;j<=k;j++){
			if (res[i]==res[j]) continue;
			ll a=res[i],b=res[j];
			ll mn=min(res[i],res[j]);
			res[i]=res[j]=mn;
			dfs();
			res[i]=a; res[j]=b;
		}
	}
}
ma mul(ma a,ma b){
	ma r(cnt+5,vec(cnt+5));
	for (ll i=1;i<=cnt;i++){
		for (ll j=1;j<=cnt;j++) r[i][j]=0;
	}
	for (ll k=1;k<=cnt;k++){
		for (ll i=1;i<=cnt;i++){
			for (ll j=1;j<=cnt;j++){
				r[i][j]=(r[i][j]+a[i][k]*b[k][j]%mod)%mod;
			}
		}
	}
	return r;
}
ma tmp(cnt+5,vec(cnt+5));
void mod_pow(ll n){
	tmp=mat; n--;
	while (n){
		if (n&1) tmp=mul(tmp,mat);
		mat=mul(mat,mat);
		n>>=1;
	}
	return;
}
int main(){
	scanf("%lld%lld",&k,&n);
	for (ll i=1;i<=k;i++) res[i]=i;
	dfs();
	for (ll i=1;i<=cnt;i++) f[i]=1;
//	cout<<cnt<<endl;
//	for (ll i=1;i<=cnt;i++){
//		for (ll j=1;j<=k;j++) cout<<lik[i][j]<<" ";
//		cout<<endl;
//	}
	for (ll s=0;s<(1<<k);s++){
		for (ll i=1;i<=cnt;i++){
			if (s==0){
				for (ll j=0;j<=k;j++) a[j]=0;
				for (ll j=1;j<=k;j++) a[lik[i][j]]++;
				for (ll j=0;j<=k;j++) f[i]=f[i]*T[a[j]]%mod;
			}
			ll mn=k+1;
			for (ll j=0;j<k;j++){
				if (s&(1<<j)) mn=min(mn,lik[i][j+1]);
				res[j]=lik[i][j+1];
			}
			for (ll j=0;j<=k+1;j++) a[j]=0;
			for (ll j=0;j<k;j++){
				if (s&(1<<j)){
					a[res[j]]++;
					res[j]=mn;
				}
			}
			res[k]=mn;
			for (ll j=0;j<=k+1;j++){
				if (a[res[j]]>0) res[j]=mn;
			}
			bool flag=0,f1=1;
			for (ll j=0;j<=k+1;j++){
				if (a[j]>1) f1=0;
			}
			if (!f1) continue;
			for (ll j=1;j<=k;j++){
				if (res[0]==res[j]) flag=1;
			}
			if (!flag) continue;
			ll cn=0;
			for (ll j=0;j<=k+1;j++) a[j]=0;
			for (ll j=1;j<=k+1;j++){
				if (a[res[j]]>0) continue;
				a[res[j]]=++cn;
			}
			for (ll j=1;j<=k;j++) res[j]=a[res[j]];
			ll tmp=0;
			for (ll j=1;j<=k;j++) tmp=tmp*10+res[j];
			ll id=mp[tmp];
			mat[i][id]++;
		}
	}
//	for (ll i=1;i<=cnt;i++){
//		for (ll j=1;j<=cnt;j++) cout<<mat[i][j]<<" ";
//		cout<<endl;
//	}
//	cout<<"fuck"<<endl;
	mod_pow(n-k);
//	cout<<"fuck"<<endl;
	ll pos=1;
	for (ll i=1;i<=cnt;i++){
		bool flag=1;
		for (ll j=1;j<=k;j++){
			if (lik[i][j]!=1) flag=0;
		}
		if (flag){
			pos=i;
			break;
		}
	}
	for (ll i=1;i<=cnt;i++) ans=(ans+tmp[i][pos]*f[i]%mod)%mod;
	cout<<ans<<endl;
	return 0;
}
