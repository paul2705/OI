#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+6;
typedef long long ll;
const ll mod1=1e9+7;
const ll mod=998244353;
ll has[MAXN],pow[MAXN];
char s[MAXN],s1[MAXN];
ll ha,nxt[MAXN];
int n,m;
int main(){
	freopen("has.in","r",stdin);
	freopen("has.out","w",stdout);
	cin>>(s+1); n=strlen(s+1);
	cin>>(s1+1); m=strlen(s1+1);
//	cout<<s[1]<<" "<<s1[1]<<endl;
//	cout<<(s+1)<<" "<<(s1+1)<<endl;
	pow[0]=has[0]=1;
	for (int i=1;i<=n;i++) pow[i]=pow[i-1]*27%mod;
	for (int i=1;i<=n;i++) has[i]=(has[i-1]*27%mod+s[i])%mod;
//	cout<<"fuck"<<endl;
	for (int i=1;i<=m;i++) ha=(ha*27%mod+s1[i])%mod;
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
		if (x==ha) printf("%d\n",i);
	}
	for (int i=2;i<=m+1;i++) printf("%lld ",nxt[i]-1);
	return 0;
}
