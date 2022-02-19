#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e3+5;
const int MAXC=63;
ll p[MAXC],bin[MAXC],ans;
struct rec{
	ll x,y;
} a[MAXN];
int n;
bool cmp(rec a,rec b){ return a.y>b.y; }
int main(){
	scanf("%d",&n);
	bin[0]=1;
	for (int i=1;i<=62;i++) bin[i]=bin[i-1]*2;
	for (int i=1;i<=n;i++) scanf("%lld%lld",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++){
		ll x=a[i].x,y=a[i].y;
		if (y<0) continue;
		for (int i=62;i>=0;i--){
			if (x&bin[i]){
				if (!p[i]){
					p[i]=x;
					break;
				}
				x^=p[i];
			}
		}
		if (x==0) continue;
		ans+=y;
	}
	printf("%lld\n",ans);
	return 0;
}
