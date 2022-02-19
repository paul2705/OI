#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=2e2+5;
double x[MAXN],y[MAXN];
int n,fa[MAXN];
struct ed{
	int u,v;
	double w;
} e[MAXN*MAXN];
int edge;
double sq(double x){ return x*x; }
double dis(int i,int j){
	return sqrt(sq(x[i]-x[j])+sq(y[i]-y[j]));
}
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
void uion(int x,int y){ fa[find(x)]=find(y); }
bool cmp(ed a,ed b){ return a.w<b.w; }
bool check(double x){
    for (int i=1;i<=n;i++) fa[i]=i;
    for (int i=1;i<=edge;i++){
//    	cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<endl;
        if (e[i].w>x) break;
        uion(e[i].u,e[i].v);
    }
    return find(1)==find(2);
}
int main(){
	freopen("B.in","r",stdin);
	freopen("B1.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lf%lf",&x[i],&y[i]);
    double mx=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
//			if (i==j) continue;
			edge++;
			e[edge]=(ed){i,j,dis(i,j)};
//			cout<<i<<" "<<j<<" "<<e[edge].w<<endl;
			mx=max(mx,e[edge].w);
		}
	}
//	cout<<edge<<endl;
	sort(e+1,e+edge+1,cmp);
//	cout<<check(130.920)<<endl;
    double l=0,r=mx,mid=0;
    while (r-l>1e-5){
//		cout<<l<<" "<<r<<endl;
		mid=(l+r)/2.0;
        if (check(mid)) r=mid;
        else l=mid;
    }
	printf("%.3lf\n",r);
	fclose(stdin); fclose(stdout);
	return 0;
}
