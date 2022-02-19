#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e5+5;
struct rec{
	int t,w;
} a[MAXN];
int n,m,ans,ret,all;
priority_queue<int,vector<int>,greater<int> > q;
bool cmp(rec a,rec b){ return a.t>b.t; }
int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].t,&a[i].w);
	sort(a+2,a+n+1,cmp);
	for (int i=2;i<=n;i++){
		if (a[i].t>a[1].t) q.push(a[i].w+1-a[i].t),m=i,ret++;
	}
	ans=ret; all=a[1].t;
	while (!q.empty()){
		int x=q.top(); q.pop();
		if (all<x) break;
		all-=x; ret--;
//		cout<<all<<" "<<x<<" "<<ret<<" "<<ans<<endl;
		for (int i=m+1;i<=n;i++){
			if (a[i].t>all) q.push(a[i].w+1-a[i].t),m=i,ret++;
			else break;
		}
//		cout<<ret<<endl;
		ans=min(ans,ret);
	}
	printf("%d\n",ans+1);
	fclose(stdout); fclose(stdin);
	return 0;
}
