#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const double M=1e6;
const int MAXN=1e6+6;
double f[MAXN][3],g[MAXN];
int n;
double p[MAXN];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lf",&p[i]),p[i]/=M;
	for (int i=1;i<=n;i++){
		f[i][0]=max(f[i-1][0],f[i-1][1]*(1-p[i])+g[i-1]*p[i]);
		f[i][0]=max(f[i][0],p[i]);
		if (f[i-1][1]*(1-p[i])+g[i-1]*p[i]>p[i]){
			f[i][1]=f[i-1][1]*(1-p[i])+g[i-1]*p[i];
			g[i]=g[i-1]*(1-p[i]);
		}
		else{
			f[i][1]=p[i];
			g[i]=1-p[i];
		}
//		cout<<f[i][0]<<" "<<f[i][1]<<endl;
	}
	printf("%0.lf\n",f[n][0]*M);
	return 0;
}
