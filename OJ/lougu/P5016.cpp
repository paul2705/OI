#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
ll c[MAXN],cnt[2];
int n,m;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&c[i]);
	ll p,s;
	scanf("%d%lld%lld",&m,&p,&s);
	c[p]+=s;
	for (int i=1;i<=n;i++){
		if (i<m) cnt[0]+=c[i]*(m-i);
		else if (i>m) cnt[1]+=c[i]*(i-m);
	}
	ll ans=abs(cnt[0]-cnt[1]),pos=m;
	scanf("%lld",&s);
	for (int i=1;i<=n;i++){
		if (i<m) cnt[0]+=s*(m-i);
		else if (i>m) cnt[1]+=s*(i-m);
		ll tmp=abs(cnt[0]-cnt[1]);
//		cout<<i<<" "<<tmp<<endl;
		if (tmp<ans){ ans=tmp; pos=i; }
		else if (tmp==ans&&pos==m&&i<m) pos=i;
		if (i<m) cnt[0]-=s*(m-i);
		else if (i>m) cnt[1]-=s*(i-m);
	}
	printf("%lld\n",pos);
	return 0;
}
