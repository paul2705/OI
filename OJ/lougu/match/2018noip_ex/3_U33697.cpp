#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=8e5+5;
const ll mod=998244353;
struct rec{
	ll x[5],c;
} a[MAXN];
ll f[MAXN],cnt[MAXN];
int n,m;
bool cmp(rec a,rec b){
/*	if (a.x[1]==b.x[1])
		if (a.x[2]==b.x[2])
			if (a.x[3]==b.x[3]) return a.x[4]<b.x[4];
			else return a.x[3]<b.x[3];
		else return a.x[2]<b.x[2];
	else return a.x[1]<b.x[1];
*/
	return a.x[1]>b.x[1]||a.x[2]>b.x[2]||a.x[3]>b.x[3]||a.x[4]>b.x[4];
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=4;j++) scanf("%lld",&a[i].x[j]);
//		sort(a[i].x+1,a[i].x+5);
		scanf("%lld",&a[i].c);
	}
	sort(a+1,a+n+1,cmp);
	ll mx=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=4;j++) printf("%lld ",a[i].x[j]);
		cout<<a[i].c<<endl;
	}
	return 0;
}
