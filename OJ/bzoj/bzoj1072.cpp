#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXS=1024+5;
const int MAXN=1e3+5;
int T,n,d;
int f[MAXS][MAXN];
int cnt[MAXN],fac[MAXN];
char S[MAXN];
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%s",S);
		int n=strlen(S);
		scanf("%d",&d);
		for (int i=0;i<=9;i++) fac[i]=1,cnt[i]=0;
		for (int i=0;i<n;i++){
			int x=S[i]-'0';
			cnt[x]++;
			fac[x]*=cnt[x];
		}
		memset(f,0,sizeof(f));
		f[0][0]=1;
		for (int s=0;s<(1<<n);s++){
			for (int j=0;j<d;j++){
				if (f[s][j]){
					for (int k=0;k<n;k++){
						if (!(s&(1<<k))){
							f[s|(1<<k)][(j*10%d+(int)S[k]-'0')%d]+=f[s][j];
						}
					}
				}
			}
		}
		for (int i=0;i<=9;i++) f[(1<<n)-1][0]/=fac[i];
		printf("%d\n",f[(1<<n)-1][0]);
	}
	return 0;
}
