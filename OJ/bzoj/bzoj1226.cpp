#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define f(a,b,c) (g[a][b][c+8])
using namespace std;
const int inf=1e9;
const int MAXN=1e3+5;
const int MAXS=1<<8;
int g[MAXN][MAXS][19];
int n,T;
int a[MAXN],b[MAXN];
int bin[20];
int cal(int x,int y){
	if (x==0||y==0) return 0;
	return a[x]^a[y];
}
int main(){
	bin[0]=1;
	for (int i=1;i<=18;i++) bin[i]=bin[i-1]*2;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
		for (int i=1;i<=n+1;i++){
			for (int s=0;s<bin[8];s++){
				for (int j=-8;j<=7;j++){
					f(i,s,j)=inf;
				}
			}
		}
		f(1,0,-1)=0;
		for (int i=1;i<=n;i++){
			for (int s=0;s<bin[8];s++){
				for (int j=-8;j<=7;j++){
					if (f(i,s,j)>=inf) continue;
					if (s&1) f(i+1,s>>1,j-1)=min(f(i+1,s>>1,j-1),f(i,s,j));
					else {
						int r=inf;
						for (int k=0;k<=7;k++){
							if (!(s&bin[k])){
								if (i+k>r) break;
								r=min(r,i+b[i+k]+k);
								f(i,s|bin[k],k)=min(f(i,s|bin[k],k),f(i,s,j)+cal(i+j,i+k));
							}
						}
					}
				}
			}
		}
		int ans=inf;
		for (int k=-8;k<=-1;k++){
			ans=min(ans,f(n+1,0,k));
		}
		printf("%d\n",ans);
	}
	return 0;
}
