#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#define mpr make_pair
#define debug() puts("okkkkkkkk")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9,maxn=1e6+5;

int n,te;
int fa[maxn];
struct point{
	int x,y;
	point(){}
	point(int x,int y):x(x),y(y){}
	bool operator<(const point &b)const{
		if(x!=b.x)return x<b.x;
		return y<b.y;
	}
};
struct edge{
	int x1,y1,x2,y2;
	edge(){}
	edge(int x1,int y1,int x2,int y2):x1(x1),y1(y1),x2(x2),y2(y2){}
	bool operator<(const edge &b)const{
		if(x1!=b.x1)return x1<b.x1;
		if(y1!=b.y1)return y1<b.y1;
		if(x2!=b.x2)return x2<b.x2;
		return y2<b.y2;
	}
};
set<edge>E;
map<point,int>P;
int tot=0;
void insp(point x){
	if(!P.count(x)){
		P[x]=++tot;
		fa[tot]=tot;
	}
}
int find(int x){return fa[x]==x?fa[x]:fa[x]=find(fa[x]);}
int cnt=1,ty,lstans;
void inse(edge x){
	if(!E.count(x)){
//		printf("-- curedge: (%d,%d) - (%d,%d)\n",)
		int fx=find(P[point(x.x1,x.y1)]),fy=find(P[point(x.x2,x.y2)]);
		if(fx==fy)++cnt;fa[fy]=fx;
		E.insert(x);
	}
}

signed main(){
	scanf("%d%d",&n,&ty);	
	for(int i=1;i<=n;i++){
		int x,y;scanf("%d%d",&x,&y);
		x^=(ty*lstans), y^=(ty*lstans);
		insp(point(x,y)),insp(point(x-1,y)),insp(point(x,y-1)),insp(point(x-1,y-1));
//		printf("test it:%d %d %d\n",P[point(-1,-1)],P[point(0,-2)],P[point(0,-1)]);
		inse(edge(x-1,y,x,y)),inse(edge(x,y-1,x,y));
		inse(edge(x-1,y-1,x-1,y)),inse(edge(x-1,y-1,x,y-1));
//		printf("cnt=%d %d %d\n",cnt,x,y);
		lstans=cnt-i;
		printf("%d\n",lstans);
	}

	return 0;
}
