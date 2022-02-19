#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=15;
int ans=-1,a[MAXN][MAXN],b[MAXN][MAXN],c[MAXN][MAXN];
bool f1[MAXN][MAXN],f2[MAXN][MAXN],f3[MAXN][MAXN];
void dfs(int step){
    int xx,yy,zz=10;
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            if (a[i][j]==0){
				int s=0;
				for(int k=1;k<=9;k++)
                    if (!f1[c[i][j]][k]&&!f2[i][k]&&!f3[j][k]) s++;
                if (s<zz) zz=s,xx=i,yy=j;
            }
        }
    }
    if (zz==10){
		int k=0;
		for(int i=1;i<=9;i++)
            for(int j=1;j<=9;j++) k+=a[i][j]*b[i][j];
        ans=max(ans,k);
        return;
    }
    if (zz==0) return;
    for(int k=1;k<=9;k++){
        if (!f1[c[xx][yy]][k]&&!f2[xx][k]&&!f3[yy][k]){
            a[xx][yy]=k;
            f1[c[xx][yy]][k]=f2[xx][k]=f3[yy][k]=1;
            dfs(step+1);
            a[xx][yy]=0;
            f1[c[xx][yy]][k]=f2[xx][k]=f3[yy][k]=0;
        }
    }
}
int main(){
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            scanf("%d",&a[i][j]);
            b[i][j]=10-max(abs(i-5),abs(j-5));
            c[i][j]=(i-1)/3*3+(j-1)/3+1;
            f1[c[i][j]][a[i][j]]=1;
            f2[i][a[i][j]]=1;
            f3[j][a[i][j]]=1;
        }
    }
    dfs(1);
    printf("%d\n",ans);
    return 0;
}
