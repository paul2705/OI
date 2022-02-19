#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e4+5;
struct rec{
	int x,y;
} a[MAXN],b[5],c[5];
int n,up,dn,rig,lef;
bool use[MAXN],res[MAXN];
bool solve(int L){
	up=dn=rig=lef=0;
	for (int i=1;i<=n;i++){
		if (use[i]) continue;
		if (a[up].y<a[i].y||up==0) up=i;
		if (a[dn].y>a[i].y||dn==0) dn=i;
		if (a[rig].x<a[i].x||rig==0) rig=i;
		if (a[lef].x>a[i].x||lef==0) lef=i;
	}
	if (up==0) return 1;
	c[1]=(rec){a[lef].x,a[up].y};
	c[2]=(rec){a[rig].x,a[up].y};
	c[3]=(rec){a[rig].x,a[dn].y};
	c[4]=(rec){a[lef].x,a[dn].y};
//	cout<<"sol2:"<<endl;
//	for (int i=1;i<=4;i++){
//		cout<<" "<<i<<" "<<c[i].x<<" "<<c[i].y<<endl;
//	}
	bool flag=0;
	for (int i=1;i<=4;i++){
//		cout<<" tp2: "<<i<<endl;
		int dx=1,dy=1;
		if (i==1) dy=-1;
		if (i==2) dx=-1,dy=-1;
		if (i==3) dx=-1;
		int x=c[i].x,y=c[i].y;
		int nx=x+dx*L,ny=y+dy*L;
		int xl=min(x,nx),xr=max(x,nx);
		int yl=min(y,ny),yr=max(y,ny);
		for (int j=1;j<=n;j++) res[j]=use[j];
//		cout<<" cvr2: ";
		for (int j=1;j<=n;j++){
			if (res[j]) continue;
			if (a[j].x<xl||a[j].x>xr) continue;
			if (a[j].y<yl||a[j].y>yr) continue;
			res[j]=1;// cout<<j<<" ";
		}
//		cout<<endl;
		up=dn=lef=rig=0;
		for (int j=1;j<=n;j++){
			if (res[j]) continue;
			if (a[up].y<a[j].y||up==0) up=j;
			if (a[dn].y>a[j].y||dn==0) dn=j;
			if (a[lef].x>a[j].x||lef==0) lef=j;
			if (a[rig].x<a[j].x||rig==0) rig=j;
		}
		if (up==0) return 1;
		int tmp=max(a[up].y-a[dn].y,a[rig].x-a[lef].x);
//		cout<<" endLen: "<<tmp<<endl;
		flag|=(tmp<=L);
	}
	return flag;
}
bool check(int L){
	bool flag=0;
	for (int i=1;i<=4;i++){
//		cout<<L<<" tp: "<<i<<endl;
		int dx=1,dy=1;
		if (i==1) dy=-1;
		if (i==2) dx=-1,dy=-1;
		if (i==3) dx=-1;
		int x=b[i].x,y=b[i].y;
		int nx=x+dx*L,ny=y+dy*L;
		int xl=min(x,nx),xr=max(x,nx);
		int yl=min(y,ny),yr=max(y,ny);
//		cout<<"cvr: ";
		for (int j=1;j<=n;j++){
			use[j]=0;
			if (a[j].x<xl||a[j].x>xr) continue;
			if (a[j].y<yl||a[j].y>yr) continue;
			use[j]=1;// cout<<j<<" ";
		}
//		cout<<endl;
//		cout<<"flg: "<<solve(L)<<endl;
		flag|=solve(L);
	}
	return flag;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
	for (int i=1;i<=n;i++){
		if (a[up].y<a[i].y||up==0) up=i;
		if (a[dn].y>a[i].y||dn==0) dn=i;
		if (a[rig].x<a[i].x||rig==0) rig=i;
		if (a[lef].x>a[i].x||lef==0) lef=i;
	}
	b[1]=(rec){a[lef].x,a[up].y};
	b[2]=(rec){a[rig].x,a[up].y};
	b[3]=(rec){a[rig].x,a[dn].y};
	b[4]=(rec){a[lef].x,a[dn].y};
//	for (int i=1;i<=4;i++){
//		cout<<i<<" "<<b[i].x<<" "<<b[i].y<<endl;
//	}
//	cout<<endl;
	int l=0,r=max(a[up].y-a[dn].y,a[rig].x-a[lef].x),mid;
	while (l+1<r){
		mid=(l+r)>>1;
		if (check(mid)) r=mid;
		else l=mid;
	}
	printf("%d\n",r);
	return 0;
}
