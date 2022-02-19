#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e4+5;
int n,k,x,t;
bool f[MAXN][110];
int gen(int x){
	x%=k; if (x<0) x+=k;
	return x;
}
int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d%d",&n,&k);
		memset(f,0,sizeof(f));
		scanf("%d",&x);
		f[0][gen(x)]=f[0][gen(-x)]=1;
		for (int i=1;i<n;i++){
			scanf("%d",&x);
			for (int j=0;j<k;j++) f[i][j]=f[i-1][gen(j-x)]|f[i-1][gen(j+x)];
		}
		if (f[n-1][0]) printf("Divisible\n");
		else printf("Not divisible\n");
	}
	return 0;
}
