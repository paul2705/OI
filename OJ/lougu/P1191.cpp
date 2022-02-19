#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e2+5;
bool a[MAXN][MAXN][MAXN];
int ans,n;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			char c=getchar(); while (c!='W'&&c!='B') c=getchar();
			a[i][j][j]=(c=='W');
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			for (int k=j+1;k<=n;k++){
				if (a[i][j][k-1]&&a[i][k][k]) a[i][j][k]=1;
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			int t=0;
			for (int k=1;k<=n;k++){
				if (a[k][i][j]) t++;
				else ans+=(t*(t+1))>>1,t=0;
			}
			ans+=(t*(t+1))>>1;
		}
	}
	printf("%d\n",ans);
	return 0;
}
