#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
const int MAXN=2e5+5;
int n,m,ans,posl,posr,t[MAXN];
struct rec{
	int l,r;
} a[MAXN];
multiset<int> s;
bool cmp(rec a,rec b){return a.r==b.r?a.l<b.l:a.r<b.r; }
int main(){
	freopen("dream.in","r",stdin);
	freopen("dream.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].l,&a[i].r);
	for (int i=1;i<=m;i++) scanf("%d",&t[i]),s.insert(t[i]);
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++){
		set<int>::iterator it=s.lower_bound(a[i].l);
//		cout<<(*it)<<endl;
		if (it!=s.end()&&(*it)<=a[i].r) s.erase(it),ans++;
	}
	printf("%d\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
