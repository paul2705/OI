#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2e5+5;
int l[MAXN],r[MAXN],n;
int f[MAXN][3];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
	f[1][0]=r[1]*2-l[1]-1,f[1][1]=r[1]-1;
	for (int i=2;i<=n;i++){
		f[i][0]=min(f[i-1][0]+abs(l[i-1]-r[i])+r[i]-l[i]+1,f[i-1][1]+abs(r[i-1]-r[i])+r[i]-l[i]+1);
		f[i][1]=min(f[i-1][0]+abs(l[i-1]-l[i])+r[i]-l[i]+1,f[i-1][1]+abs(r[i-1]-l[i])+r[i]-l[i]+1);	
	}
	printf("%d\n",min(f[n][0]+n-l[n],f[n][1]+n-r[n]));
	return 0;
}	
