#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1e5+5;
typedef long long ll;
int a[MAXN],r[MAXN];
int n,m;
ll t[MAXN*20];
ll c1[MAXN],c2[MAXN],c3[MAXN],c4[MAXN];
ll s1,s2,ans;
void add(int x){
	for (;x<=m;x+=x&-x) t[x]++;
}
int query(int x){
	ll ret=0;
	for (;x>0;x-=x&-x) ret+=t[x];
	return ret;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),r[i]=a[i];
	sort(r+1,r+n+1);
	m=unique(r+1,r+n+1)-r-1;
	for (int i=1;i<=n;i++){
		a[i]=lower_bound(r+1,r+m+1,a[i])-r;
//		cout<<a[i]<<endl;
	}
	for (int i=1;i<=n;i++) c1[i]=query(a[i]-1),s1+=c1[i],add(a[i]);
	memset(t,0,sizeof(t));
	for (int i=n;i>0;i--) c2[i]=query(a[i]-1),add(a[i]);
	memset(t,0,sizeof(t));
	for (int i=1;i<=n;i++) c3[i]=query(m)-query(a[i]),s2+=c3[i],add(a[i]);
	memset(t,0,sizeof(t));
	for (int i=n;i>0;i--) c4[i]=query(m)-query(a[i]),add(a[i]);
	ans=s1*s2;
	for (int i=1;i<=n;i++){
		ans-=c1[i]*c2[i];
		ans-=c1[i]*c3[i];
		ans-=c2[i]*c4[i];
		ans-=c3[i]*c4[i];
	}
	printf("%lld\n",ans);
	return 0;
}
