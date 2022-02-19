#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int x[MAXN],y[MAXN],n;
struct rec{
	int x,y;
} a[MAXN];
int getsum(int tx,int ty){
	int ans=0;
	for (int i=1;i<=n;i++) ans+=abs(tx-x[i])+abs(ty-y[i]);
	return ans;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]),a[i]=(rec){x[i],y[i]};
	sort(x+1,x+n+1); sort(y+1,y+n+1);
	if (n%2==0){
		int lx=x[n/2],rx=x[n/2+1];
		int ly=y[n/2],ry=y[n/2+1];
		int sum=(rx-lx+1)*(ry-ly+1);
		for (int i=1;i<=n;i++) if (a[i].x>=lx&&a[i].x<=rx&&a[i].y>=ly&&a[i].y<=ry) sum--;
		printf("%d %d\n",getsum(lx,ly),sum);
	}
	else{
		int tx=x[n/2+1],ty=y[n/2+1];
		int ans=23333333,cnt=0;
		for (int i=0;i<4;i++){
			int x=tx+dx[i],y=ty+dy[i];
			int sum=getsum(x,y);
			if (sum<ans) ans=sum,cnt=1;
			else if (sum==ans) cnt++;
		}
		printf("%d %d\n",ans,cnt);
	}
	return 0;
}
