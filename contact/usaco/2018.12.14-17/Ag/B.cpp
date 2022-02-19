#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e5+5;
struct rec{
	int id,s,t;
	bool operator < (const rec& b) const {
		return id<b.id;
	}
	bool operator > (const rec& b) const {
		return id>b.id;
	}
} a[MAXN],b[MAXN];
priority_queue<rec,vector<rec>,greater<rec> > q;
int n,ans=0;
bool cmp(rec a,rec b){ return a.s<b.s; }
int main(){
	freopen("convention2.in","r",stdin);
	freopen("convention2.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].s,&a[i].t),a[i].id=i;
	sort(a+1,a+n+1,cmp);
//	for (int i=1;i<=n;i++) cout<<a[i].s<<" "<<a[i].t<<" "<<a[i].id<<endl;
	int tim=a[1].s;
	for (int i=1;i<=n;i++){
//		cout<<"fuck: "<<i<<" "<<tim<<endl;
		if (a[i].s<=tim||q.empty()) q.push(a[i]);
		else {
			rec x=q.top(); q.pop();
//			cout<<x.id<<" "<<x.s<<" "<<x.t<<endl;
//			cout<<ans<<" "<<tim<<" "<<tim-x.s<<endl;
			if (tim<x.s) tim=x.s;
			ans=max(ans,tim-x.s);
			tim+=x.t;
			i--;
//			q.push(a[i]);
		}
	}
//	cout<<"done "<<ans<<endl;
	while (!q.empty()){
		rec x=q.top(); q.pop();
//		cout<<x.id<<" "<<x.s<<" "<<x.t<<endl;
		ans=max(ans,tim-x.s);
		tim+=x.t;
	}
//	cout<<"fone"<<endl;
	printf("%d\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
