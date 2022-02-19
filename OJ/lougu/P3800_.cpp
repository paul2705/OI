#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=4e3+5;
struct rec{ int x,y,w; } a[MAXN];
int f[MAXN],n,m,k,t,ans;
bool cmp(rec a,rec b){ return a.x<b.x; }
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&t);
	for (int i=1;i<=k;i++) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].w);
	sort(a+1,a+k+1,cmp); f[1]=a[1].w;
	for (int i=1;i<=k;i++){
		for (int j=0;j<i;j++){
			if (abs(a[i].y-a[j].y)<=t*abs(a[i].x-a[j].x)){
				f[i]=max(f[i],f[j]+a[i].w);
				ans=max(ans,f[i]);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
