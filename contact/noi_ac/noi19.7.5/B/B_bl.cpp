#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<bitset>
using namespace std;
const double inf=1e8;
const int MAXN=5e2+5;
const double eps=1e-8;
int n,m,cnt;
const int dx[16]={0,0,1,-1,1,1,-1,-1,-2,-2,-1,-1,1,1,2,2};
const int dy[16]={1,-1,0,0,-1,1,-1,1,-1,1,-2,2,-2,2,-1,1};
double ans=0,aS;
//bitset<5> st;
struct rec{
	double x,y;
	double operator * (const rec& b) const {
		return x*b.y-y*b.x;
	}
	rec operator - (const rec& b) const {
		return (rec){x-b.x,y-b.y};
	}
} a[MAXN],bd[MAXN],lis[MAXN];
bool cmp(rec a,rec b){ return a.x==b.x?a.y<b.y:a.x<b.x; }
int jud(rec x,rec y){
	int cnt1=0,cnt2=0;
	for (int i=1;i<=m;i++){
		double t=(x-y)*(a[i]-y);
		if (t>eps) cnt1++;
		if (t<-eps) cnt2++;
		if (cnt1*cnt2>0) return 0;
	}
	if (cnt1==0&&cnt2==0) return 3;
	if (cnt1>0) return 1;
	if (cnt2>0) return 2;
	return 4;
}
// 0:wrong 1:all-left 2:all-right 3:all-inline
rec ext[5];
int cnte=0,pose[5];
rec exter(rec l1,rec r1,rec l2,rec r2){
	double k1=(l1.y-r1.y+eps)/(l1.x-r1.x+eps);
	double b1=l1.y-k1*l1.x;
	double k2=(l2.y-r2.y+eps)/(l2.x-r2.x+eps);
	double b2=l2.y-k2*l2.x;
	double x=(b2-b1+eps)/(k1-k2+eps);
	double y=k1*x+b1;
	double oxl=min(l1.x,r1.x);
	double oxr=max(l1.x,r1.x);
	double oyl=min(l1.y,r1.y);
	double oyr=max(l1.y,r1.y);
	if (l1.x==r1.x&&l2.y==r2.y){
		return (rec){l1.x,l2.y};
	}
	if (l1.y==r1.y&&l2.x==r2.x){
		return (rec){l2.x,l1.y};
	}
	if (l1.x==r1.x){
		if (l2.x==r2.x) return (rec){-inf,-inf};
		double y=k2*l1.x+b2;
//		cout<<"1x=: "<<b2<<endl;
		if (y<oyl||y>oyr) y=-inf;
		return (rec){l1.x,y};
	}
	else if (l2.x==r2.x){
		double y=k1*l2.x+b1;
		if (y<oyl||y>oyr) y=-inf;
		return (rec){l2.x,y};
	}
	if (l1.y==r1.y){
		if (l2.y==r2.y) return (rec){-inf,-inf};
		double x=(l1.y-b2)/k2;
		if (x<oxl||x>oxr) x=-inf;
		return (rec){x,l1.y};
	}
	else if (l2.y==r2.y){
		double x=(l2.y-b1)/k1;
		if (x<oxl||x>oxr) x=-inf;
		return (rec){x,l2.y};
	}
	if (x<oxl||x>oxr) x=-inf;
	if (y<oyl||y>oyr) y=-inf;
	return (rec){x,y};
}
double S(rec x,rec y,int tp){
	double ret=0;
	rec t=x-y;
	cnte=0;
	for (int i=1;i<=n;i++){
		int j=i+1; if (i==n) j=1;
		rec tmp=exter(bd[i],bd[j],x,y);
//		cout<<bd[i].x<<" "<<bd[i].y<<" "<<bd[j].x<<" "<<bd[j].y<<" "<<x.x<<" "<<x.y<<" "<<y.x<<" "<<y.y<<" "<<tmp.x<<" "<<tmp.y<<endl;
		if (tmp.x!=-inf&&tmp.y!=-inf){
//			cout<<"get "<<cnte<<endl;
			ext[++cnte]=tmp;
			pose[cnte]=i;
		}
	}
//	cout<<"ext: "<<cnte<<" :";
//	for (int i=1;i<=cnte;i++) printf("(%.4lf %.4lf %d) ",ext[i].x,ext[i].y,pose[i]);
//	cout<<"done"<<endl;
	if (tp==1){
		if ((y.x-x.x)*(y.x-ext[1].x)<0||(y.y-x.y)*(y.y-ext[1].y)<0) swap(ext[1],ext[2]),swap(pose[1],pose[2]);
	}
	else {
		if ((y.x-x.x)*(y.x-ext[1].x)>0||(y.y-x.y)*(y.y-ext[1].y)>0) swap(ext[1],ext[2]),swap(pose[1],pose[2]);
	}
	for (int i=pose[1],j=0;i!=pose[2];i=j){
		j=i+1; if (j>n) j=1;
		rec t1=bd[i],t2=bd[j];
		if (i==pose[1]) t1=ext[1];
		double res=(t1-y)*(t2-t1);
//		cout<<y.x<<" "<<y.y<<" "<<t1.x<<" "<<t1.y<<" "<<t2.x<<" "<<t2.y<<" "<<res<<endl;
		ret+=fabs(res)/2.0;
	}
	rec t2=ext[2],t1=bd[pose[2]];
	double res=(t1-y)*(t2-t1);
//	cout<<y.x<<" "<<y.y<<" "<<t1.x<<" "<<t1.y<<" "<<t2.x<<" "<<t2.y<<" "<<res<<endl;
	ret+=fabs(res)/2.0;
	return ret;
}
void solve1(){
	sort(a+1,a+m+1,cmp);
	for (int s=0;s<(1<<m);s++){
		cnt=0;
//		cout<<s<<endl;
		for (int i=0;i<m;i++){
			if (s&(1<<i)) lis[cnt++]=a[i+1];
		}
		for (int i=0;i<cnt;i++){
			for (int j=0;j<cnt;j++){
				if (i==j) continue;
				int tp=jud(lis[i],lis[j]);
//				cout<<tp<<endl;
				if (tp==0) continue;
				double res=S(lis[i],lis[j],tp);
				double x=cnt,y=m;
//				st=s;
//				cout<<"1: "<<st<<" "<<x<<" "<<res<<" "<<x/y-res/aS<<endl;
				ans=max(ans,x/y-res/aS);
				if (tp==3) ans=max(ans,x/y-(aS-res)/aS);
			}
		}
		for (int i=0;i<cnt;i++){
			for (int k=0;k<8;k++){
				int nx=lis[i].x+dx[k],ny=lis[i].y+dy[k];
				rec tmp=(rec){nx,ny};
				int tp=jud(tmp,lis[i]);
				if (tp==0) continue;
				double res=S(tmp,lis[i],tp);
				double x=cnt,y=m;
//				st=s;
//				cout<<lis[i].x<<" "<<lis[i].y<<" "<<nx<<" "<<ny<<endl;
//				cout<<"2: "<<st<<" "<<x<<" "<<res<<" "<<x/y-res/aS<<" "<<tp<<endl;
				ans=max(ans,x/y-res/aS);
				if (tp==3) ans=max(ans,x/y-(aS-res)/aS);
			}
		}
	}
	printf("%.7lf\n",ans);
//	cout<<ans<<endl;
}
void solve2(){

}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%lf%lf",&bd[i].x,&bd[i].y);
	for (int i=1;i<=m;i++) scanf("%lf%lf",&a[i].x,&a[i].y);
	for (int i=1;i<=n;i++){
		int j=i+1; if (j>n) j=1;
		rec t1=bd[i],t2=bd[j];
		double res=(t1-a[1])*(t2-t1);
		aS+=fabs(res)/2;
	}
//	printf("%.10lf\n",aS);
	if (n<=10) solve1();
	else solve2();
	return 0;
}
