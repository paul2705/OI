#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int n,m;
struct rec{
	int x,y,val;
} t[MAXN],a[MAXN];
bool cmp(rec a,rec b){ return a.x<b.x; }
bool cmp1(rec a,rec b){ return a.y<b.y; }
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i].x),a[i].y=i;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&t[i].x,&t[i].y);
	}
	sort(a+1,a+n+1,cmp);
	sort(t+1,t+m+1,cmp);
	int l=1,r=0,sum=0;
	for (int i=1;i<=n;i++){
		while (r<m&&a[i].x>=t[r+1].x){
			r++;
			sum+=t[r].y;
		}
		a[i].val=sum;
	}
	sort(a+1,a+n+1,cmp1);
	for (int i=1;i<=n;i++) printf("%d ",a[i].val);
	return 0;
}
