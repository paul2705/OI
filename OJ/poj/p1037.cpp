#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int MAXN=25;
const int DOWN=1,UP=0;
ll C[MAXN][MAXN][2];
void Init(int n){
	memset(C,0,sizeof(C));
	C[1][1][UP]=C[1][1][DOWN]=1;
	for (int i=2;i<=n;i++){
		for (int k=1;k<=i;k++){
			for (int M=k;M<i;M++) C[i][k][UP]+=C[i-1][M][DOWN];
			for (int N=1;N<k;N++) C[i][k][DOWN]+=C[i-1][N][UP];
		}
	}
}
void print(int n,ll cc){
	ll sk=0;
	int seq[MAXN],used[MAXN];
	memset(used,0,sizeof(used));
	for (int i=1;i<=n;i++){
		ll ov=sk;
		int k,no=0;
		for (k=1;k<=n;k++){
			ov=sk;
			if (!used[k]){
				no++;
				if (i==1) sk+=C[n][no][UP]+C[n][no][DOWN];
				else {
					if (k>seq[i-1]&&(i<=2||seq[i-2]>seq[i-1])) sk+=C[n-i+1][no][DOWN];
					else if (k<seq[i-1]&&(i<=2||seq[i-2]<seq[i-1])) sk+=C[n-i+1][no][UP];
				}
				if (sk>=cc) break;
			}
		}
		used[k]=true; seq[i]=k; sk=ov;
	}
	for (int i=1;i<=n;i++){
		if (i<n) printf("%d ",seq[i]);
		else printf("%d",seq[i]);
	}
	printf("\n");
}
int main(){
	int T,n;
	ll c;
	Init(20);
	scanf("%d",&T);
	while (T--){
		scanf("%d %lld",&n,&c);
		print(n,c);
	}
	return 0;
}	
