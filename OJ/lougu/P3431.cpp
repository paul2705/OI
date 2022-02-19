#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int K=1e5+5;
struct point{
	int x,y,p;
} a[K];
int n,m,k,cnt;
int t[K];
bool cmp1(point a,point b){ return a.y<b.y; }
bool cmp2(point a,point b){ return a.x==b.x?a.y<b.y:a.x<b.x; }
void add(int x,int k){
	for (;x<=cnt;x+=x&-x) t[x]=max(t[x],k);
}
int query(int x){
	int ans=-1;
	for (;x;x-=x&-x) ans=max(ans,t[x]);
	return ans;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=k;i++) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].p);
	sort(a+1,a+k+1,cmp1);
	int t=a[1].y; cnt=0;
	a[1].y=++cnt;
	for (int i=2;i<=k;i++){
		if (a[i].y!=t) t=a[i].y,a[i].y=++cnt;
		else a[i].y=cnt;
	}
	sort(a+1,a+k+1,cmp2);
	int ans=-1;
	for (int i=1;i<=k;i++){
		t=query(a[i].y)+a[i].p;
		ans=max(t,ans);
		add(a[i].y,t);
	}
	printf("%d\n",ans);
	return 0;
}
