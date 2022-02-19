#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1e5+5;
struct rec{
	int s,v;
} a[MAXN];
int n,m,s[MAXN],l[MAXN];
bool cmp_v(rec a,rec b){ return a.v>b.v; }
bool cmp_l(rec a,rec b){ return a.s>b.s; }
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i].s);
	for (int i=1;i<=n;i++) scanf("%d",&a[i].v);
	sort(a+1,a+n+1,cmp_l);
	for (int i=1;i<=n;i++) l[i]=max(l[i-1],a[i].v+a[i].s*2);
	sort(a+1,a+n+1,cmp_v);
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i].v;
	for (int i=1;i<=n;i++) printf("%d\n",max(s[i]+a[i].s*2,s[i-1]+l[i]));
	return 0;
}
