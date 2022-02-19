#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=1e5+5;
int f[5][MAXN],n;
int main(){
	scanf("%d",&n);
	int b=0;
	for (int i=0;i<=1e5;i++) f[0][i]=f[1][i]=-100001;
	f[0][0]=0;
	for (int i=0,x;i<n;i++){
		scanf("%d",&x);
		for (int j=0;j<=b;j++) f[(i+1)&1][j]=f[i&1][j];
		for (int j=0;j<=b;j++){
			f[(i+1)&1][j+x]=max(f[(i+1)&1][j+x],f[i&1][j]+x);
			f[(i+1)&1][abs(j-x)]=max(f[(i+1)&1][abs(j-x)],f[i&1][j]+x);
		}
		b+=x;
	}
	printf("%d\n",f[n&1][0]<=0?0:(f[n&1][0]/2));
	return 0;
}
