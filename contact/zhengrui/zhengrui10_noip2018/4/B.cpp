#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=505;
double f[MAXN][3];
int n,m;
struct rec{
	int x,y,l,r;
} a[MAXN];
int Find(int l,int r,int x,int id){
	int mid;
	if (id==0){
		if (a[l].y>x) return 0;
		r++;
		while (l+1<r){
			mid=(l+r)>>1;
			if (a[mid].y<=x) l=mid;
			else r=mid;
		}
		return l;
	}
	else{
		if (a[r].y<x) return n+1;
		l--;	
		while (l+1<r){
			mid=(l+r)>>1;
			if (a[mid].y<x) l=mid;
			else r=mid;
		}
		return r;
	}
}
double sq(double a){ return a*a; }
double dis(int y,int x,int id){
	if (id==0&&a[y].x!=a[x].x){
		if (y<x) return (double)m-a[y].y;
		else return (double)a[y].y;
	}
	else {
		return (double)sqrt(sq(a[y].x-a[x].x)+sq(a[y].y-a[x].y));
	}
}
bool cmp(rec a,rec b){ return a.x==b.x?a.y<b.y:a.x<b.x; }
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n+1;i++) f[i][0]=f[i][1]=1e9;
	int l=1,r=1,x=a[1].x;
	for (int i=1;i<=n;i++) 
		if (a[i].x==a[1].x) r=i;
		else break;
	int rl=l,rr=r; l=r+1;
	a[n+1].x=a[n].x+1;
	for (int i=r+1;i<=n+1;i++){
		if ((a[i-1].x==x)||(a[i].x==a[i-1].x)) a[i].l=rl,a[i].r=rr,r=i;
		else if (a[i-1].x!=x&&a[i].x!=a[i-1].x){
			x=a[i-1].x; rl=l,rr=r;
			a[i].l=rl; a[i].r=rr;
			l=r+1;
		}
	}
	for (int i=1;i<=n;i++){
		if (a[i].l+a[i].r==0) continue;
		int x=i;
		for (int j=i;j<=n+1;j++){ if (a[j].x!=a[i].x){ x=j; break; } }
//		cout<<x<<" "<<a[x].l<<" "<<a[x].r<<endl;
//		cout<<"a: "<<a[i].l<<" "<<a[i].r<<endl;
		int l=Find(a[i].l,a[i].r,a[i].y,0);
		int r=Find(a[i].l,a[i].r,a[i].y,1);
//		cout<<"b: "<<l<<" "<<r<<" "<<a[i].y<<endl;
		int lp=Find(a[x].l,a[x].r,a[l].y,1);
		int rp=Find(a[x].l,a[x].r,a[r].y,0);
//		cout<<lp<<" "<<rp<<endl;
		if (l!=0){
			double mn=dis(l,i,1);
			for (int j=i;j<=lp;j++) mn=min(mn,dis(l,j,1));
			if (a[i-1].x==a[i].x){
				f[i][0]=max(min(f[l][0],min(dis(l,l+1,0),dis(r,i,1))),min(f[l][1],min(dis(l,i,1),min(dis(l,l-1,0),dis(r,i,1)))));
				f[i][1]=max(min(f[l][0],min(dis(l,l+1,0),dis(l,i,1))),min(f[l][1],dis(l,l-1,0)));	
			}
			else {
				for (int j=l;j>=a[i].l;j--){
					mn=min(mn,dis(j,i,1));
					f[i][0]=max(min(f[j][0],min(dis(j,j+1,0),dis(r,i,1))),min(f[j][1],min(mn,min(dis(j,j-1,0),dis(r,i,1)))));
					f[i][1]=max(min(f[j][0],min(dis(j,j+1,0),mn)),min(f[j][1],dis(j,j-1,0)));
				}
			}
		}
		if (r!=n+1){
			double mn=dis(r,i,1);
			for (int j=rp;j<=i;j++) mn=min(mn,dis(r,j,1));
//			cout<<"r: "<<mn<<endl;
			if (a[i+1].x==a[i].x){
				f[i][0]=max(min(f[r][0],dis(r,r+1,0)),min(f[r][1],min(dis(r,i,1),dis(r,r-1,0))));
				f[i][1]=max(min(f[r][0],min(dis(r,r+1,0),min(dis(r,i,1),dis(l,i,1)))),min(f[r][1],min(dis(r,r-1,0),dis(l,i,1))));
			}
			else {
				for (int j=r;j<=a[i].r;j++){
					mn=min(mn,dis(j,i,1));
					f[i][0]=max(min(f[j][0],dis(j,j+1,0)),min(f[j][1],min(mn,dis(j,j-1,0))));
					f[i][1]=max(min(f[j][0],min(dis(j,j+1,0),min(mn,dis(l,i,1)))),min(f[j][1],min(dis(j,j-1,0),dis(l,i,1))));
				}
			}
		}
	}
	double ans=0;
	if (a[n+1].l==1){
		for (int j=1;j<=n;j++){
			ans=max(ans,max(dis(j,j-1,0),dis(j,j+1,0)));
		}
	}
	else for (int j=a[n+1].l;j<=a[n+1].r;j++){
//		cout<<"c: "<<f[j][1]<<" "<<f[j][0]<<endl;
		if (f[j][1]==1e9) f[j][1]=0;
		if (f[j][0]==1e9) f[j][0]=0;
		ans=max(ans,max(min(f[j][1],dis(j,j-1,0)),min(f[j][0],dis(j,j+1,0))));
	}
	printf("%.3lf\n",ans);
	return 0;
}
