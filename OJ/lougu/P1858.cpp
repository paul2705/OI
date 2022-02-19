#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int f[5005][55];
int n,V,K,v[205],w[205];
int q[505],ans;
int main(){
	memset(f,-63,sizeof(f));
	scanf("%d%d%d",&K,&V,&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&v[i],&w[i]);
	f[0][1]=0;
	for (int i=1;i<=n;i++){
		for (int j=V;j>=v[i];j--){
			int l=1,r=1,cnt=1;
			while (cnt<=K+1){
				if (f[j][l]>f[j-v[i]][r]+w[i]) q[cnt++]=f[j][l++];
				else q[cnt++]=f[j-v[i]][r++]+w[i];
			}
			for (int k=1;k<=K;k++){
				f[j][k]=q[k];
//				printf("%d %d %d\n",j,k,f[j][k]);
			}
		}
	}
	for (int i=1;i<=K;i++) ans+=f[V][i];
	printf("%d\n",ans);
	return 0;
}
