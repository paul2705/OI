#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int MAXN=40;
map<ll,int> mp;
ll n,K,a[MAXN],w[MAXN],cnt[MAXN];
int main(){
	freopen("x3.in","r",stdin);
	freopen("x3.out","w",stdout);
	scanf("%lld%lld",&n,&K);
	for (int i=1;i<=10;i++) scanf("%lld",&a[i]);
	for (int i=0;i<n;i++) scanf("%lld%lld",&w[i],&cnt[i]);
	for (int s=0;s<(1<<(n/2));s++){
		ll ret=0;
		for (int i=0;i<n/2;i++){
			if (s&(1<<i)) ret+=w[i];
		}
		mp[ret]=1;
	}
	int rest=n-(n/2),stp=n/2;
	ll pos_val=0,pos_st=0;
	for (int s=0;s<(1<<rest);s++){
		ll ret=0;
		for (int i=0;i<rest;i++){
			if (s&(1<<i)) ret+=w[i+stp];
		}
		if (mp[K-ret]){
			pos_st=s; pos_val=K-ret;
			break;
		}
	}
	ll ans_haf=0;
	for (int s=0;s<(1<<stp);s++){
		ll ret=0;
		for (int i=0;i<stp;i++){
			if (s&(1<<i)) ret+=w[i];
		}
		if (ret==pos_val){
			ans_haf=s;
			break;
		}
	}
	ll ans=0;
	for (int i=0;i<stp;i++){
		if (ans_haf&(1<<i)) printf("1\n"),ans+=w[i];
		else printf("0\n");
	}
	for (int i=0;i<rest;i++){
		if (pos_st&(1<<i)) printf("1\n"),ans+=w[i+stp];
		else printf("0\n");
	}
	printf("%lld\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
