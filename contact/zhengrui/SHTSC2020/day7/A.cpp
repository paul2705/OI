# include <cstdio>
# include <iostream>
# include <algorithm>
# include <cmath>
# define R register int
using namespace std;
const int N=105;
const double eps=1e-7;
const double Pi=acos(-1);
const double Pi2=2*acos(-1);
int n,m,vis[N],cnt,tp;
struct cir{
	int x,y,r;
}a[N],b[N];
struct point{
	double x,y;
	point (double a=0,double b=0){
		x=a,y=b;
	}
}p[2*N*N],tb[2*N*N];
int d2 (int x_1,int y_1,int x_2,int y_2){
	return (x_1-x_2)*(x_1-x_2)+(y_1-y_2)*(y_1-y_2);
}
int sgn (double x){
	if(x<-eps) return -1;
	if(x>eps) return 1;
	return 0;
}
int point_cir (int id,double x,double y){
	double dis=(x-b[id].x)*(x-b[id].x)+(y-b[id].y)*(y-b[id].y);
	return sgn(dis-b[id].r*b[id].r);
}
bool cmp (point a,point b){
	if(sgn(a.x-b.x)==0) return a.y<b.y;
	return a.x<b.x;
}
bool inn (point p){
	for (R i=1;i<=m;++i)
		if(point_cir(i,p.x,p.y)==-1) return 1;
	return 0;
}
void get_p (cir a,cir b){
	if(a.r<b.r) swap(a,b);
	double d=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);	
	double ve=atan2(b.y-a.y,b.x-a.x);
	double an=acos((a.r-b.r)/sqrt(d));
	p[++cnt]=point(a.x+a.r*cos(ve+an),a.y+a.r*sin(ve+an)); if(inn(p[cnt])) cnt--;
	p[++cnt]=point(b.x+b.r*cos(ve+an),b.y+b.r*sin(ve+an)); if(inn(p[cnt])) cnt--;
	p[++cnt]=point(a.x+a.r*cos(ve-an),a.y+a.r*sin(ve-an)); if(inn(p[cnt])) cnt--;
	p[++cnt]=point(b.x+b.r*cos(ve-an),b.y+b.r*sin(ve-an)); if(inn(p[cnt])) cnt--;
}
point operator - (point a, point b) { 
	return point(a.x-b.x,a.y-b.y); 
}
double cross (point a,point b){
	return a.x*b.y-a.y*b.x;
}
int check (int x,int y){
	for (R i=1;i<=m;++i)
		if(point_cir(i,tb[x].x,tb[x].y)==0&&point_cir(i,tb[y].x,tb[y].y)==0) 
			return i;
	return 0;
}
double dot (point a,point b){
	return a.x*b.x+a.y*b.y;
}
double len (point a){
	return sqrt(dot(a,a));
}
double an (point a,point b){
	return acos(dot(a,b)/len(a)/len(b));
}
void solve(){
	scanf("%d",&n);
	cnt=tp=m=0;
	for (R i=1;i<=n;++i)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].r);
	for (R i=1;i<=n;++i) vis[i]=1;
	for (R i=1;i<=n;++i)
		for (R j=i+1;j<=n;++j)
			if(a[i].x==a[j].x&&a[i].y==a[j].y&&a[i].r==a[j].r)
				vis[j]=0;
	for (R i=1;i<=n;++i){
		if(!vis[i]) continue;
		for (R j=1;j<=n;++j){
			if(!vis[j]) continue;
			if(i==j) continue;
			if(a[i].r<=a[j].r) continue;
			if(d2(a[i].x,a[i].y,a[j].x,a[j].y)<=(a[i].r-a[j].r)*(a[i].r-a[j].r))
				vis[j]=0;
		}
	}
	for (R i=1;i<=n;++i){
		if(!vis[i]) continue;
		++m; b[m].x=a[i].x; b[m].y=a[i].y; b[m].r=a[i].r;
	}
	if(m==1) { printf("%.10lf\n",Pi2*b[1].r); return; }
	for (R i=1;i<=m;++i)
		for (R j=i+1;j<=m;++j)
			get_p(b[i],b[j]);
	sort(p+1,p+1+cnt,cmp);
	for (R i=1;i<=cnt;++i){
		while(tp-1>0&&sgn(cross(tb[tp]-tb[tp-1],p[i]-tb[tp-1]))<=0) tp--;
		tb[++tp]=p[i];
	}
	int k=tp;
	for (R i=cnt-1;i>=1;--i){
		while(tp-1>=k&&sgn(cross(tb[tp]-tb[tp-1],p[i]-tb[tp-1]))<=0) tp--;
		tb[++tp]=p[i];
	}
	if(sgn(tb[tp].x-tb[1].x)==0&&sgn(tb[tp].y-tb[1].y)==0) tp--;
	tb[0]=tb[tp];
	double ans=0;
	for (R i=0;i<tp;++i){
		point x=tb[i],y=tb[i+1];
		int opt=check(i,i+1);
		if(opt){
			point yx=point(b[opt].x,b[opt].y);
			int s=sgn(cross(y-yx,x-yx));
			if(s<=0) ans+=an(y-yx,x-yx)*b[opt].r;
			else ans+=(Pi2-an(y-yx,x-yx))*b[opt].r;
		}
		else
			ans+=sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));
	}
	printf("%.10lf\n",ans);
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}
