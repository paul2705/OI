#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf=1e9;
const int MAXN=1e5+5;
const int MAXS=1<<5;
int f[MAXN][MAXS],num[MAXN][MAXS];
int n,m,lis[10];
int bin[10],ans;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int pos,a,b;
		scanf("%d%d%d",&pos,&a,&b);
		for (int j=0;j<=5;j++) lis[j]=0;
		for (int j=1;j<=a;j++){
			int x; scanf("%d",&x); x-=pos;
			if (x<0) x+=n;
			lis[x]=-1;
		}
		for (int j=1;j<=b;j++){
			int x; scanf("%d",&x); x-=pos;
			if (x<0) x+=n;
			lis[x]=1;
		}
		for (int s=0;s<(1<<5);s++){
			bool flag=0;
			for (int j=0;j<5;j++){
				if (s&(1<<(4-j))){
					if (lis[j]==1) flag|=1;
				}
				else if (lis[j]==-1) flag|=1;
			}
			num[(pos+3)%n+1][s]+=flag;
		}
	}
	bin[0]=1;
	for (int i=1;i<=n+5;i++){
		for (int s=0;s<(1<<5);s++) f[i][s]=-inf;
	}
	for (int i=1;i<=5;i++) bin[i]=bin[i-1]*2;
	for (int i=n+1;i<=n+4;i++){
		for (int s=0;s<bin[5];s++) num[i][s]=num[i-n][s];
	}
	for (int st=0;st<bin[5];st++){
		for (int s=0;s<bin[5];s++) f[4][s]=-inf;
		f[4][st]=0;
		for (int i=5;i<=n+4;i++){
			for (int s=0;s<bin[5];s++){
				f[i][s]=max(f[i-1][s>>1],f[i-1][s>>1|bin[4]])+num[i][s];
			}
		}
		ans=max(ans,f[n+4][st]);
	}
	printf("%d\n",ans);
	return 0;
}
