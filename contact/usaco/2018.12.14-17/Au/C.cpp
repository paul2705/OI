#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e4+5;
int f[MAXN],a[MAXN],n,k;
int main(){
	freopen("teamwork.in","r",stdin);
	freopen("teamwork.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++){
		int mx=a[i];
		for (int j=i-1;j>=max(0,i-k);j--){
//			mx=max(mx,a[j]);
			f[i]=max(f[i],f[j]+mx*(i-j));
			mx=max(mx,a[j]);
		}
	}
	printf("%d\n",f[n]);
	fclose(stdin); fclose(stdout);
	return 0;
}
