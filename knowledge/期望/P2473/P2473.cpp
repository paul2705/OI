#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXK=1e2+5;
const int MAXN=16;
const int MAXS=1<<16;
double f[MAXK][MAXS];
int n,k,rd[MAXN];
int a[MAXN];
int main(){
	scanf("%d%d",&k,&n);
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
		int x;scanf("%d",&x);
		while (x!=0){
			x--; rd[i]|=1<<x;
			scanf("%d",&x);
		}
	}
	f[n][(1<<n)-1]=0;
	for (int i=k;i>=1;i--){
		for (int s=(1<<n)-1;s>=0;s--){
			for (int j=0;j<n;j++){
				if ((s&rd[j])==rd[j]) f[i][s]+=max(f[i+1][s],f[i+1][s|(1<<j)]+a[j]);
				else f[i][s]+=f[i+1][s];
			}
			f[i][s]/=n;
		}
	}
	printf("%.6lf\n",f[1][0]);
	return 0;
}
