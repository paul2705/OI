#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXV=1e5+5;
const int MAXN=2e2;
int f[MAXN][MAXN];
int n;
int lis[MAXN],cnt;
int main(){
	scanf("%d",&n);
	for (int i=0;i<=128;i++){
		for (int j=0;j<=128;j++) f[i][j]=1e9;
	}
	for (int i=1;i<=n;i++){
		int x; scanf("%d",&x);
		cnt=0; int now=0;
		while (x){
			if (x&1){
				lis[cnt++]=now;
				for (int i=0;i<cnt;i++){
					f[lis[i]][now+64]=f[now+64][lis[i]]=1;
					f[now][lis[i]+64]=f[lis[i]+64][now]=1;
				}
				cout<<now<<" ";
			}
			x>>=1; now++;
		}
		cout<<endl;
	}
	for (int i=0;i<=64;i++) f[i][i+64]=f[i+64][i]=1e9;
	for (int k=0;k<=128;k++){
		for (int i=0;i<=128;i++){
			for (int j=0;j<=128;j++){
				if (f[i][j]>f[i][k]+f[k][j]){
					f[i][j]=f[i][k]+f[k][j];
				}
			}
		}
	}
	int ans=1e9;
	for (int i=0;i<=64;i++) ans=min(ans,min(f[i][i+64],f[i+64][i]));
	for (int i=0;i<=64;i++) cout<<i<<" "<<f[i][i+64]<<" "<<f[i+64][i]<<endl;
	printf("%d\n",ans==1e9?-1:ans+1);
	return 0;
}
