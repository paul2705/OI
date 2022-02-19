#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=35;
int a[MAXN][MAXN];
struct rec{
	int x,y;
} d[MAXN*MAXN];
int n,cnt;
struct qi{
	int x1,y1,x2,y2,x3,y3;
} q[MAXN*MAXN];
double cal(int x1,int y1,int x2,int y2,int x3,int y3){
    x2-=x1,y2-=y1,x3-=x1,y3-=y1;
    if(x2*y3-y2*x3==0)return 180;
    int t=x2*x3+y2*y3;
    double v=acos(t/sqrt((x2*x2+y2*y2)*(x3*x3+y3*y3)));
    for(int i=2;i;i--){
        x1=x3,x3=-x2,x2=x1-x2;
        y1=y3,y3=-y2,y2=y1-y2;
        t=x2*x3+y2*y3;
        v=max(v,acos(t/sqrt((x2*x2+y2*y2)*(x3*x3+y3*y3))));
    }
    return v*57.29577951308232;
}
int Get(int x,int y){ return (x-1)*n+y; }
bool cmp(rec a,rec b){ return a.x==b.x?a.y<b.y:a.x<b.x; }
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if (a[i][j]!=Get(i,j)) d[cnt++]=(rec){i,j};
		}
	}
	int ans=0,lim=0;
	double ret=0;
	while (lim<cnt){
		int x=d[lim].x,y=d[lim].y;
		lim++;
		if (a[x][y]==Get(x,y)) continue;
		ans++;
		int px,py;
		for (int i=lim;i<cnt;i++){
			int nx=d[i].x,ny=d[i].y;
			if (a[nx][ny]==Get(x,y)){
				px=nx; py=ny;
				break;
			}
		}
		double mn=181;
		int ppx,ppy;
		for (int i=lim;i<cnt;i++){
			int nx=d[i].x,ny=d[i].y;
			if ((nx==px&&ny==py)||(nx==x&&ny==y)) continue;
			double tmp=cal(x,y,px,py,nx,ny);
			if (tmp<mn){
				mn=tmp;
				ppx=nx; ppy=ny;
			}
		}
//		ret=max(ret,mn);
		int tmp=a[x][y];
		a[x][y]=a[px][py];
		a[px][py]=a[ppx][ppy];
		a[ppx][ppy]=tmp;
		q[ans]=(qi){x,y,ppx,ppy,px,py};
//		printf("%d %d %d %d %d %d\n",x,y,ppx,ppy,px,py);
	}
	printf("%d\n",ans);
	for (int i=1;i<=ans;i++){
		printf("%d %d %d %d %d %d\n",q[i].x1,q[i].y1,q[i].x2,q[i].y2,q[i].x3,q[i].y3);
	}
//	printf("%.6lf\n",ret);
/*	cout<<" : :  :"<<endl;
	bool flag=1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			printf("%d ",a[i][j]);
			if (a[i][j]!=Get(i,j)) flag=0;
		}
		cout<<endl;
	}
	if (!flag) printf("No\n");
	else printf("Yes\n");
	cout<<lim<<" "<<cnt<<endl;
*/	return 0;
}
