#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
const ll mod=998244353;
const ll mod1=19260817;
int a[MAXN],b[MAXN],c[MAXN],id[MAXN*3];
ll has[MAXN],has1[MAXN];
int mx1,mx2;
int n,m,f[MAXN];
ll pow[MAXN];
map<ll,bool> mp;
/*bool check(int x){
	mp.clear();
	for (int i=1;i<=n;i++){
		int j=i+x-1;
		if (j>n) break;
		ll x=((has[j]-has[i-1]*pow[j-i+1]%mod)%mod+mod)%mod;
//		cout<<x<<" ";
		mp[x]=1;
	}
//	cout<<endl;
	for (int i=1;i<=n;i++){
		int j=i+x-1;
		if (j>n) break;
		ll x=((has1[j]-has1[i-1]*pow[j-i+1]%mod)%mod+mod)%mod;
//		cout<<x<<" ";
		if (mp[x]) return 1;
	}
//	cout<<endl;
	return 0;
i}*/
int main(){
	freopen("new.in","r",stdin);
	freopen("new.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),id[a[i]]=i;
	pow[0]=has[0]=has1[0]=1;
	for (int i=1;i<=n;i++) pow[i]=pow[i-1]*mod1%mod;
	for (int i=1;i<=n;i++) has[i]=(has[i-1]*mod1%mod+a[i]%mod)%mod;
	while (m--){
		for (int i=1;i<=n;i++) scanf("%d",&b[i]),c[i]=id[b[i]];
//		for (int i=1;i<=n;i++) cout<<b[i]<<endl;
		for (int i=1;i<=n;i++) has1[i]=(has1[i-1]*mod1%mod+b[i]%mod)%mod;
		for (int i=1;i<=n;i++) f[i]=1e9;
		f[0]=0; int len=0;
		for (int i=1;i<=n;i++){
			if (c[i]==0) continue;
			if (c[i]>=f[len]) f[++len]=c[i];
			else {
				int x=lower_bound(f+1,f+len+1,c[i]+1)-f;
				f[x]=min(f[x],c[i]);
			}
		}
//		cout<<len<<endl;
		mx1=max(mx1,len);
/*		int l=-1,r=n+1,mid;
		while (l+1<r){
			mid=(l+r)>>1;
			if (check(mid)) l=mid;
			else r=mid;
		}
		mx2=max(mx2,l);*/
		for (int i=1;i<=n;i++) b[i]=c[i]-c[i-1];
		for (int i=1;i<=n;i++){
			int l=i,r=i;
			if (b[l]!=1) continue;
			for (;r<=n;r++){
				if (b[r]!=1) break;
			}
//			cout<<l<<" "<<r<<endl;
			mx2=max(mx2,r-l+1);
			i=r-1;
		}
	}
	printf("%d\n%d\n",mx1,mx2);
	fclose(stdin); fclose(stdout);
	return 0;
}
