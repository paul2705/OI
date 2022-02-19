#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=205;
char a[MAXN][MAXN];
int l[MAXN][MAXN],r[MAXN][MAXN];
int n,m,ans;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			char c=getchar(); while (c!='.'&&c!='X') c=getchar();
			a[i][j]=c;
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (a[i][j]=='.'){
				l[i][j]=j==1?1:l[i][j-1];
				r[i][j]=i==1?1:r[i-1][j];
			}
			else l[i][j]=j+1,r[i][j]=i+1;
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			int ml=0,las=0;
			for (int k=1;k<=m;k++){
				if (r[j][k]<=i){
					if (l[i][k]<=las&&l[j][k]<=las) ml=max(ml,k-las+1);
					else las=k;
				}
			}
			ans=max(ans,(j-i+1)*ml);
		}
	}
	printf("%d\n",ans);
	return 0;
}
