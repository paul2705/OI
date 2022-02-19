#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=2e5+5;
int n,T,ans;
struct rec{
	int w,t;
} a[MAXN];
priority_queue<int> q;
bool cmp(rec a,rec b){ return a.t<b.t; }
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].w,&a[i].t);
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++){
		if (T+a[i].w>a[i].t){
			if (a[i].w<q.top()){
				T-=q.top(); q.pop();
				q.push(a[i].w); T+=a[i].w;
			}
		}
		else{ q.push(a[i].w); ans++; T+=a[i].w; }
	}
	printf("%d\n",ans);
	return 0;
}
