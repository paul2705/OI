#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
struct rec{
	int x,y;
} a[MAXN],b[MAXN];
int n;
int ansx,ansy;
bool cmp(rec a,rec b){ return a.x==b.x?a.y<b.y:a.x<b.x; }
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
	for (int i=1;i<=n;i++) scanf("%d%d",&b[i].x,&b[i].y);
	sort(a+1,a+n+1,cmp); sort(b+1,b+n+1,cmp);
	printf("%d %d\n",a[1].x+b[n].x,a[1].y+b[n].y);
	return 0;
}
