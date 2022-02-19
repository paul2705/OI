#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e2+5;
double a[MAXN][MAXN];
double val[MAXN];
int n,lis[MAXN];
bool use[MAXN];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n+1;j++) scanf("%lf",&a[i][j]);
	}
	int lin=0;
	bool fl=false;
	for (int i=1;i<=n;i++){
		lin++;
		int pos=0;
		for (int j=1;j<=n;j++){
			if (a[j][i]!=0&&!use[j]){
				pos=j;
				break;
			}
		}
		if (pos==0){
			fl=true;
			break;
		}
		use[pos]=1; lis[i]=pos;
		double x=a[pos][i];
		for (int j=i;j<=n+1;j++) a[pos][j]/=x;
		for (int j=1;j<=n;j++){
			if (use[j]) continue;
			if (a[j][i]!=0){
				double ex1=a[j][i];
				for (int k=i;k<=n+1;k++){
					a[j][k]-=a[pos][k]*ex1;
				}
			}
		}
	}
	if (fl) return printf("No Solution"),0;
	lin=n+1;
	for (int i=n;i>=1;i--){
		int pos=lis[i];
		if (a[pos][i]!=0){
			double tmp=0;
			for (int k=i+1;k<=n;k++) tmp+=val[k]*a[pos][k];
			val[i]=(a[pos][n+1]-tmp)/a[pos][i];
		}
	}
	for (int i=1;i<=n;i++) printf("%.2lf\n",val[i]);
	return 0;
}
