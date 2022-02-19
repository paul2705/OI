#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
const int MAXN=1e5+5;
typedef long long ll;
set<ll> s;
int n,k;
ll a[MAXN];
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
		if (a[i]%k||s.find(a[i]/k)==s.end())
			s.insert(a[i]);
	printf("%lld\n",(ll)s.size());
	return 0;
}
