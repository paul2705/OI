#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
const int b[10]={0,100,50,20,10,5,1};
int mon[4][10];
int x1,x2,x3,s[4];
int sum;
int f[7][MAXN][MAXN];
int main(){
	scanf("%d%d%d",&x1,&x2,&x3);
	for (int i=1;i<=3;i++){
		for (int j=1;j<=6;j++){
			scanf("%d",&mon[i][j]);
			sum+=mon[i][j]*b[j];
		}
	}
//	cout<<"done"<<endl;
	for (int i=1;i<=3;i++){
		for (int j=1;j<=6;j++) s[i]+=mon[i][j]*b[j];
	}
	if (s[1]-x1+x3>sum||s[2]+x1-x2>sum||s[3]-x3+x2>sum) return printf("impossible\n"),0;
	memset(f,63,sizeof(f)); f[0][s[1]][s[2]]=0;
	for (int i=1;i<=6;i++){
		for (int j=0;j<=sum;j++){
			for (int k=0;k+j<=sum;k++){
				if (f[i-1][j][k]>=1e9) continue;
				int cnt=mon[1][i]+mon[2][i]+mon[3][i];
				for (int x=0;x<=cnt;x++){
					for (int y=0;y+x<=cnt;y++){
						int z=cnt-x-y;
						int lx=mon[1][i]-x;
						int ly=mon[2][i]-y;
						int lz=mon[3][i]-z;
						int chg=(abs(lx)+abs(ly)+abs(lz))/2;
						if (j-lx*b[i]+k-ly*b[i]>sum) continue;
						if (j<lx*b[i]||k<ly*b[i]) continue;
						f[i][j-lx*b[i]][k-ly*b[i]]=min(f[i][j-lx*b[i]][k-ly*b[i]],f[i-1][j][k]+chg);
					}
				}
			}
		}
	}
	int ans=f[6][s[1]-x1+x3][s[2]-x2+x1];
	if (ans>=1e9) printf("impossible\n");
	else printf("%d\n",ans);
	return 0;
}
