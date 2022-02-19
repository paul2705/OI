#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e3+5;
int f[MAXN][MAXN][3],pre[MAXN][MAXN][3][10];
int n,m,mp[MAXN][MAXN];
ll X,Y,Z,P[MAXN];
void prt(int l,int r,int c){
//	cout<<__func__<<" "<<l<<" "<<r<<" "<<c<<endl;
	if (l+1==r) printf("%d %d\n",l,r);
	if (pre[l][r][c][2]){
		printf("%d %d\n",pre[l][r][c][2],r);
		prt(l,pre[l][r][c][2],c);
		prt(pre[l][r][c][2]+1,r-1,c);
	}
	else if (pre[l][r][c][1]){
		prt(l,pre[l][r][c][1],c);
		prt(pre[l][r][c][1],r,c);
	}
	else if (pre[l][r][c][0]){
		prt(l,pre[l][r][c][0],c);
		prt(pre[l][r][c][0]+1,r,c);
	}
	else if (pre[l][r][c][3]){
		printf("%d %d\n",l,r);
		prt(l+1,r-1,c);
	}
	else if (pre[l][r][c][4]){
		/*int pos=l;
		for (int i=l+1;i<=r;i++){
			if (mp[l][i]==c) pos=i;
		}*/
		printf("%d %d\n",l,l+1);
		prt(l+1,r,c);
	}
	else if (pre[l][r][c][5]){
		/*int pos=l;
		for (int i=l;i<r;i++){
			if (mp[i][r]==c) pos=i;
		}*/
		printf("%d %d\n",r-1,r);
		prt(l,r-1,c);
	}
	else if (pre[l][r][c][6]){
		printf("%d %d\n",l,pre[l][r][c][6]);
		prt(l+1,pre[l][r][c][6]-1,c);
		prt(pre[l][r][c][6],r,c);
	}
	else if (pre[l][r][c][7]){
		printf("%d %d\n",l,r);
		prt(l,r-1,c);
	}
	else if (pre[l][r][c][8]){
		printf("%d %d\n",l,r);
		prt(l+1,r,c);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int a,b,c; scanf("%d%d%d",&a,&b,&c);
		mp[a][b]=mp[b][a]=c;
	}
	scanf("%lld%lld%lld",&X,&Y,&Z);
	for (int i=1;i<=n;i++) scanf("%lld",&P[i]);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (mp[i][j]) continue;
			ll mn=min(i,j),mx=max(i,j);
			mp[i][j]=((mn*X+mx*Y)%Z>=(P[i]+P[j]));
		}
	}
	for (int i=1;i<=n;i++) f[i][i-1][0]=f[i][i-1][1]=1;
	for (int i=1;i<n;i++) f[i][i+1][mp[i][i+1]]=1;
	for (int l=2;l<=n;l++){
		for (int c=0;c<=1;c++){
			for (int i=1;i<=n;i++){
				int j=i+l; if (j>n) break;
				for (int k=i+1;k<j;k++){
					if (mp[k][j]==c){
						int tmp=f[i][j][c];
						f[i][j][c]|=f[i][k][c]&f[k+1][j-1][c];
						if (tmp+f[i][j][c]==1) pre[i][j][c][2]=k;
					}
					if (mp[i][k]==c){
						int tmp=f[i][j][c];
						f[i][j][c]|=f[i+1][k-1][c]&f[k][j][c];
						if (tmp+f[i][j][c]==1) pre[i][j][c][6]=k;
					}
					int tmp=f[i][j][c];
					f[i][j][c]|=f[i][k][c]&f[k][j][c];
					if (tmp+f[i][j][c]==1) pre[i][j][c][1]=k;
					f[i][j][c]|=f[i][k][c]&f[k+1][j][c];
					if (tmp+f[i][j][c]==1) pre[i][j][c][0]=k;
				}
				int tmp=f[i][j][c];
				f[i][j][c]|=(mp[i][j]==c)&f[i+1][j-1][c];
				if (tmp+f[i][j][c]==1) pre[i][j][c][3]=1;
				tmp=f[i][j][c];
				f[i][j][c]|=(mp[i][j]==c)&f[i][j-1][c];
				if (tmp+f[i][j][c]==1) pre[i][j][c][7]=1;
				tmp=f[i][j][c];
				f[i][j][c]|=(mp[i][j]==c)&f[i+1][j-1][c];
				if (tmp+f[i][j][c]==1) pre[i][j][c][8]=1;
				if (mp[i][i+1]==c){
					int tmp=f[i][j][c];
					f[i][j][c]|=f[i+1][j][c];
					if (tmp+f[i][j][c]==1) pre[i][j][c][4]=1;
				}
				if (mp[j-1][j]==c){
					int tmp=f[i][j][c];
					f[i][j][c]|=f[i][j-1][c];
					if (tmp+f[i][j][c]==1) pre[i][j][c][5]=1;
				}
			}
		}
	}
//	printf("%d %d %d %d\n",f[1][2][0],f[2][3][0],f[2][4][0],f[3][4][0]);
	if (f[1][n][1]) prt(1,n,1);
	else if (f[1][n][0]) prt(1,n,0);
	else printf("No solution\n");
	return 0;
}
