#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=5e4+5;
int q[MAXN],l,r;
int n,m;
ll f[MAXN];
struct rec{
	ll x,y;
} a[MAXN];
bool cmp(rec a,rec b){
	return a.x==b.x?a.y<b.y:a.x<b.x; 
}
double slop(int x,int y){
	double l=f[y]-f[x];
	double r=a[x+1].y-a[y+1].y;
	return l/r;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld%lld",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++){
		while (m&&a[i].y>=a[m].y) m--;
		a[++m]=a[i];
	}
	for (int i=1;i<=m;i++){
		while (l<r&&slop(q[l],q[l+1])<a[i].x) l++;
		f[i]=f[q[l]]+a[q[l]+1].y*a[i].x;
		while (l<r&&slop(q[r],i)<slop(q[r],q[r-1])) r--;
		q[++r]=i;
	}
	printf("%lld\n",f[m]);
	return 0;
}
		
