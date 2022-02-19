#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e3+5;
int a[MAXN][MAXN],sum[MAXN][MAXN];
int ans,n,m,t,r,T;
priority_queue<int> q;
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d%d",&n,&m,&t,&r);
		ans=0;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++) sum[i][j]=0;
		}
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				char c=getchar(); while (c!='*'&&c!='X'&&c!='O')c=getchar();
				cout<<c<<" ";
				if (c=='*') a[i][j]=0;
				if (c=='X') a[i][j]=1;
				if (c=='O'){
					a[i][j]=2;
					int x=i-r,y=j;
					int k=i,l=j-r;
					for (;k<=i+r&&l<=j;x++,y++,k++,l++){
						int kk=k,ll=l,xx=x,yy=y;
						while (ll<1) kk--,ll++;
						while (xx<1) xx++,yy--;
						cout<<kk<<" "<<ll<<" "<<xx<<" "<<yy<<endl;
						if (kk<xx+1) xx=kk-1,yy=ll+1;
//						if (kk>=xx+1)
							cout<<kk<<" "<<ll+1<<" "<<xx+1<<" "<<yy<<endl;
						sum[kk+ll][ll]++; sum[kk+ll][yy+1]--;
						if (kk>=xx+1)
							sum[kk+ll+1][ll+1]++,sum[kk+ll+1][yy+1]--;
					}
				}
			}
			cout<<endl;
		}
		for (int i=1;i<=2*n;i++){
			int x=i,y=1;
			for (;y<=i;y++,x--){
				sum[x+y][y]+=sum[x+y][y-1];
				cout<<x<<" "<<y<<" "<<sum[x+y][y]<<endl;
				if (x<=n&&y<=n&&a[x][y]==2) q.push(sum[x+y][y]);
			}
		}
		for (int i=1;i<=t;i++) ans+=q.top(),q.pop();
		while (!q.empty()) q.pop();
		printf("%d\n",ans);
	}
	return 0;
}
