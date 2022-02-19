#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
const int MAXM=2e4+5;
int b[MAXN],c[MAXN],f[MAXM],q[MAXM],w[MAXM];
int n,m;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	scanf("%d",&m); memset(f,63,sizeof(f));
	f[0]=0;
	for (int i=1;i<=n;i++){
		for (int j=0;j<b[i];j++){
			int l=1,r=0;
			for (int k=j;k<=m;k+=b[i]){
				while (l<=r&&w[l]<k-c[i]*b[i]) l++;
				while (l<=r&&f[k]-(k-w[l])/b[i]<=q[r]) r--;
				q[++r]=f[k]; w[r]=k;
				f[k]=min(f[k],q[l]+(k-w[l])/b[i]);
			}
		}
	}
	printf("%d\n",f[m]);
	return 0;
}
