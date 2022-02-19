#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=55;
int n,k;
int ans=1e9;
struct dot{
	int x,y;
} a[MAXN];
struct rec{
	int lx,ly,rx,ry;
	int mxx(){ return lx>rx?lx:rx; }
	int mnx(){ return lx<rx?lx:rx; }
	int mxy(){ return ly<ry?ry:ly; }
	int mny(){ return ly>ry?ry:ly; }
} res[10];
bool use[MAXN];
bool cmp(dot a,dot b){ return a.x==b.x?a.y<b.y:a.x<b.x; }
bool check(int id){
	for (int i=1;i<=k;i++){
		if (a[id].x>=res[i].mnx()&&a[id].x<=res[i].mxx()){
			if (a[id].y>=res[i].mny()&&a[id].x<=res[i].mxy()) return 1;
		}
	}
	return 0;
}
void dfs(int d,int sz){
//	cout<<d<<" "<<sz<<endl;
	if (sz>ans) return;
	int cnt=0;
	for (int i=1;i<=n;i++){
		if (use[i]) cnt++;
	}
//	cout<<cnt<<endl;
	if (cnt==n||d==k+1){
		bool f=1;
		for (int i=1;i<=n;i++){
			if (!check(i)) f=0;
		}
		if (f) ans=min(ans,sz);
		return;
	}
//	cout<<"fuck"<<endl;
	for (int i=1;i<=n;i++){
		if (use[i]) continue;
		for (int j=1;j<=n;j++){
			if (use[j]) continue;
			use[i]=use[j]=1;
			res[d]=(rec){a[i].x,a[i].y,a[j].x,a[j].y};
			for (int k=1;k<=n;k++){
				if (check(k)) use[k]=1;
			}
			int st=abs(a[i].x-a[j].x)*abs(a[i].y-a[j].y);
//			cout<<i<<" "<<j<<endl;
			dfs(d+1,sz+st);
			res[d]=(rec){0,0,0,0};
			for (int k=1;k<=n;k++){
				if (!check(k)) use[k]=0;
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}
