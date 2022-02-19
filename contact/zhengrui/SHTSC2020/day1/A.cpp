#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=int(b)-1;i>=a;i--)
using namespace std;
typedef long long ll;

string dir[8]={"N","NE","E","SE","S","SW","W","NW"};
int dx[]={0,1,1,1,0,-1,-1,-1},dy[]={1,1,0,-1,-1,-1,0,1};
int d,n;
ll cost[10];
int px[55],py[55]; 
char op[10];
ll dist(int x,int y) {
	if (x==0&&y==0) return 0;
	ll ans=1ll<<60;
	rep(i,0,8) {
		int d=0;
		if (dx[i]*y==dy[i]*x) {
			d=dx[i]?x/dx[i]:y/dy[i];
			if (d>=0) ans=min(ans,cost[i]*d);
		}
	}
	rep(i,0,4) rep(j,i+1,4) {
		int c1=x*dy[j]-y*dx[j],c2=dx[i]*y-dy[i]*x,c3=dx[i]*dy[j]-dx[j]*dy[i];
		if (c1%c3!=0||c2%c3!=0) continue;
		int d1=c1/c3,d2=c2/c3;
		ll f1=cost[i],f2=cost[j];
		if (d1<0) f1=cost[i+4],d1*=-1;
		if (d2<0) f2=cost[j+4],d2*=-1;
		ans=min(ans,f1*d1+f2*d2);
	}
	return ans;
}
ll disto(int x,int y) {
	ll ans=dist(x,y);
	for (int i=0;i<8;i++) ans=min(ans,dist(x-dx[i],y-dy[i])+cost[i]);
	return ans;
}
ll eval(int x,int y) {
	ll ret=0;
	rep(j,0,n) ret+=disto(x-px[j],y-py[j]);
	//printf("%d %d %lld\n",x,y,ret);
	return ret;
}
ll gao(int x,int py) {
	int l=-2000001,r=2000001;
	ll ans=1ll<<60;
	while (l+5<r) {
		int pl=(l+l+r)/3,pr=(l+r+r)/3;
		ll fl=eval(x,2*pl+py),fr=eval(x,2*pr+py);
		if (fl>fr) l=pl; else r=pr;
//		printf("yy %d %lld %d %lld\n",pl,fl,pr,fr);
	}
	rep(k,l,r+1) ans=min(ans,eval(x,2*k+py));
	return ans;
}
int main() {
	scanf("%d",&d);
	rep(i,0,8) cost[i]=1<<30;
	rep(i,0,d) {
		scanf("%s",op);
		string s=op;
		rep(j,0,8) if (s==dir[j]) cost[j]=1;
	}
	scanf("%d",&n);
	rep(i,0,n) scanf("%d%d",px+i,py+i);
	ll ans=1ll<<60;
/*	rep(x,-500,501) rep(y,-500,501) {
		ll ret=0;
		rep(j,0,n) ret+=disto(x-px[j],y-py[j]);
		ans=min(ans,ret);
	}*/
	rep(px,0,2) rep(py,0,2) {
		int l=-2000001,r=2000001;
		while (l+5<r) {
			int pl=(l+l+r)/3,pr=(l+r+r)/3;
			ll fl=gao(2*pl+px,py),fr=gao(2*pr+px,py);
//			printf("%d %lld %d %lld\n",pl,fl,pr,fr);
			if (fl>fr) l=pl; else r=pr;
		}
		rep(k,l,r+1) ans=min(ans,gao(2*k+px,py));
	}
	printf("%lld\n",ans);
}
