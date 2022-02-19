#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e3+5;
int n,m,a[MAXN],ans,pos;
int use[MAXN][MAXN],res[MAXN][MAXN];
int main(){
	freopen("message.in","r",stdin);
	freopen("message1.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),use[i][i]=1;
	while (1){
		ans++;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++) res[i][j]=0;
		}
		for (int i=1;i<=n;i++){
			for (int j=i;j<=n;j++){
				if (use[i][j]) res[a[i]][j]=1;
			}
		}
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (res[i][j]==1) use[i][j]++;
			}
		}
		bool f=0;
		for (int i=1;i<=n;i++){
			if (use[i][i]==2) pos=i,f=1;
		}
		if (f) break;
	}
	printf("%d\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
