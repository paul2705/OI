#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=1e3+5;
const int N=20;
int f[N],SG[MAXN],S[MAXN];
void getSG(int n){
	memset(SG,0,sizeof(SG));
	for (int i=1;i<=n;i++){
		memset(S,0,sizeof(S));
		for (int j=0;f[j]<=i&&j<=N;j++) S[SG[i-f[j]]]=1;
		for (int j=0;;j++) if (!S[j]){
			SG[i]=j;
			break;
		}
	}
}
int main(){
	int n,m,k;
	f[0]=f[1]=1;
	for (int i=2;i<=16;i++) f[i]=f[i-1]+f[i-2];
	getSG(1000);
	while (scanf("%d%d%d",&m,&n,&k),m||n||k){
		if (SG[n]^SG[m]^SG[k]) printf("Fibo\n");
		else printf("Nacci\n");
	}
	return 0;
}
