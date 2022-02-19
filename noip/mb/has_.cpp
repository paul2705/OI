#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+6;
typedef long long ll;
const ll mod1=998244353;
const ll mod=1e9+7;
ll has[MAXN],pow[MAXN];
ll has1[MAXN],pow1[MAXN];
char s[MAXN],s1[MAXN];
ll ha,ha1,nxt[MAXN];
int n,m;
int main(){
	freopen("has.in","r",stdin);
	freopen("has.out","w",stdout);
	cin>>(s+1); n=strlen(s+1);
	cin>>(s1+1); m=strlen(s1+1);
//	cout<<s[1]<<" "<<s1[1]<<endl;
//	cout<<(s+1)<<" "<<(s1+1)<<endl;
	pow[0]=has[0]=pow1[0]=has1[0]=1;
	for (int i=1;i<=n;i++) pow[i]=pow[i-1]*27%mod;
	for (int i=1;i<=n;i++) has[i]=(has[i-1]*27%mod+s[i])%mod;
	for (int i=1;i<=n;i++) pow1[i]=pow1[i-1]*27%mod1;
	for (int i=1;i<=n;i++) has1[i]=(has1[i-1]*27%mod1+s[i])%mod1;
//	cout<<"fuck"<<endl;
	for (int i=1;i<=m;i++) ha=(ha*27%mod+s1[i])%mod;
	for (int i=1;i<=m;i++) ha1=(ha1*27%mod1+s1[i])%mod1;
	int j=1,k=0; nxt[1]=0;
//	cout<<"fuck"<<endl;
	while (j<=m){
		if (k==0||s1[j]==s1[k]) nxt[++j]=++k;
		else k=nxt[k];
	}
//	cout<<"fuck"<<endl;
	for (int i=1;i<=n;i++){
		int j=i+m-1;
		if (j>n) break;
		ll x=((has[j]-has[i-1]*pow[j-i+1]%mod)%mod+mod)%mod;
		ll x1=((has1[j]-has1[i-1]*pow1[j-i+1]%mod1)%mod1+mod1)%mod1;
		if (x==ha&&x1==ha1) printf("%d\n",i);
	}
	for (int i=2;i<=m+1;i++) printf("%lld ",nxt[i]-1);
	return 0;
}
