#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=76;
int n,cnt[10],tot;
int f[3][16][16][16][16][16][6];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x; scanf("%d",&x);
		cnt[x]++;
		tot+=x;
	}
	n=tot;
	f[1][cnt[1]-1][cnt[2]][cnt[3]][cnt[4]][cnt[5]][1]=cnt[1];
	f[1][cnt[1]+1][cnt[2]-1][cnt[3]][cnt[4]][cnt[5]][2]=cnt[2];
	f[1][cnt[1]][cnt[2]+1][cnt[3]-1][cnt[4]][cnt[5]][3]=cnt[3];
	f[1][cnt[1]][cnt[2]][cnt[3]+1][cnt[4]-1][cnt[5]][4]=cnt[4];
	f[1][cnt[1]][cnt[2]][cnt[3]][cnt[4]+1][cnt[5]-1][5]=cnt[5];
	for (int i=2;i<=n;i++){
		for (int j=0;j<=15;j++){
		for (int k=0;k<=15;k++){
		for (int l=0;l<=15;l++){
		for (int m=0;m<=15;m++){
		for (int r=0;r<=15;r++){
		for (int x=1;x<=5;x++){
			for (int y=1;y<=5;y++){
			int now=i&1; int pre=now^1;
			if (j>0&&x==1&&x+1==y) f[now][j-1][k][l][m][r][x]+=f[pre][j][k][l][m][r][y]*(j-1);
			if (j>0&&x==1&&x+1!=y) f[now][j-1][k][l][m][r][x]+=f[pre][j][k][l][m][r][y]*j;
			if (k>0&&x==2&&x+1==y) f[now][j+1][k-1][l][m][r][x]+=f[pre][j][k][l][m][r][y]*(k-1);
			if (k>0&&x==2&&x+1!=y) f[now][j+1][k-1][l][m][r][x]+=f[pre][j][k][l][m][r][y]*k;
			if (l>0&&x==3&&x+1==y) f[now][j][k+1][l-1][m][r][x]+=f[pre][j][k][l][m][r][y]*(l-1);
			if (l>0&&x==3&&x+1!=y) f[now][j][k+1][l-1][m][r][x]+=f[pre][j][k][l][m][r][y]*l;
			if (m>0&&x==4&&x+1==y) f[now][j][k][l+1][m-1][r][x]+=f[pre][j][k][l][m][r][y]*(m-1);
			if (m>0&&x==4&&x+1!=y) f[now][j][k][l+1][m-1][r][x]+=f[pre][j][k][l][m][r][y]*m;
			if (r>0&&x==5&&x+1==y) f[now][j][k][l][m+1][r-1][x]+=f[pre][j][k][l][m][r][y]*(r-1);
			if (r>0&&x==5&&x+1!=y) f[now][j][k][l][m+1][r-1][x]+=f[pre][j][k][l][m][r][y]*r;
			}
		}
		}
		}
		}
		}
		}
	}
	int ans=0;
	for (int i=0;i<=15;i++){
		for (int j=0;j<=15;j++){
			for (int k=0;k<=15;k++){
				for (int l=0;l<=15;l++){
					for (int m=0;m<=15;m++){
						for (int x=1;x<=5;x++){
							ans+=f[n&1][i][j][k][l][m][x];
						}
					}
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
