#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e3+5;
double f[MAXN][MAXN],p;
int n,t;
int main(){
	scanf("%d%lf%d",&n,&p,&t);
	f[0][0]=1.0;
	for (int i=0;i<t;i++){
		f[i+1][n]+=f[i][n];
		for (int j=0;j<n;j++){
			f[i+1][j+1]+=f[i][j]*p;
			f[i+1][j]+=f[i][j]*(1-p);
		}
	}
	double ans=0;
	for (int i=0;i<=n;i++) ans+=i*f[t][i];
	printf("%.6lf\n",ans);
	return 0;
}
