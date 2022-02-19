#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int MAXN=61;
map<ll,int> mp;
ll n,K,A[MAXN];
struct rec{
	ll w,cnt,id;
} a[MAXN];
int haf;
int main(){
	freopen("x4.in","r",stdin);
//	freopen("x4.out","w",stdout);
	scanf("%lld%lld",&n,&K);
	for (int i=1;i<=10;i++) scanf("%lld",&A[i]);
	for (int i=0;i<n;i++) scanf("%lld%lld",&a[i].w,&a[i].cnt),a[i].id=i;
	int cnt=0;
	haf=22;
	while (1){
		cnt++; cout<<cnt<<" :";
		random_shuffle(a,a+n); mp.clear();
//		for (int i=0;i<n;i++) cout<<a[i].id<<" ";
//		cout<<endl;
		for (int s=0;s<(1<<haf);s++){
			ll ret=0;
			for (int i=0;i<haf;i++){
				if (s&(1<<i)) ret+=a[i].w;
			}
			mp[ret]=1;
		}
		int stp=haf;
		ll pos_val=0,pos_st=-1;
		for (int s=0;s<(1<<haf);s++){
			ll ret=0;
			for (int i=0;i<haf;i++){
				if (s&(1<<i)) ret+=a[i+stp].w;
			}
			if (mp[K-ret]){
				pos_st=s; pos_val=K-ret;
				break;
			}
		}
		if (pos_st==-1){
			printf("Wrong\n");
			continue;
		}
		ll ans_haf=-1;
		for (int s=0;s<(1<<haf);s++){
			ll ret=0;
			for (int i=0;i<haf;i++){
				if (s&(1<<i)) ret+=a[i].w;
			}
			if (ret==pos_val){
				ans_haf=s;
				break;
			}
		}
		ll ans=0;
		for (int i=0;i<stp;i++){
			if (ans_haf&(1<<i)) printf("%lld ",a[i].id),ans+=a[i].w;
		}
		for (int i=0;i<haf;i++){
			if (pos_st&(1<<i)) printf("%lld ",a[i+stp].id),ans+=a[i+stp].w;
		}
		printf("ans: %lld\n",ans);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
