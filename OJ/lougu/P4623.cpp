#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+5;
int n,m;
int x[MAXN],y[MAXN];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int mxx=0,mxy=0,mnx=1e9,mny=1e9;
		for (int j=1,x,y;j<=3;j++){
			scanf("%d%d",&x,&y);
			mxx=max(mxx,x); mnx=min(mnx,x);
			mxy=max(mxy,y); mny=min(mny,y);
		}
		x[mnx+1]++; x[mxx]--;
		y[mny+1]++; y[mxy]--;
	}
	for (int i=1;i<=1e6;i++) x[i]+=x[i-1],y[i]+=y[i-1];
	scanf("%d",&m);
	for (int i=1,a;i<=m;i++){
		char c,cc; cin>>c>>cc>>a;
//		cout<<c<<" "<<a<<endl;
		if (c=='x') printf("%d\n",x[a]);
		else printf("%d\n",y[a]);
	}
	return 0;
}
