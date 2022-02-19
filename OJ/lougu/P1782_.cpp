#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e4+5;
const int MAXC=1e4+5;
typedef long long ll;
ll f[MAXC];
int n,m,c;
int main(){
	scanf("%d%d%d",&n,&m,&c);
	for (int i=1,v,w,d;i<=n;i++){
		scanf("%d%d%d",&v,&w,&d);
		if (d*v>c){
			for (int j=v;j<=c;j++){
				f[j]=max(f[j],f[j-v]+w);
			}
			continue;
		}
		for (int k=1;k<=d;k*=2){
			for (int j=c;j>=v*k;j--){
				f[j]=max(f[j],f[j-v*k]+w*k);
			}
			d-=k;
		}
		if (d){
			for (int j=c;j>=v*d;j--){
				f[j]=max(f[j],f[j-v*d]+w*d);
			}
		}
	}
	for (int i=1,a,b,d;i<=m;i++){
		scanf("%d%d%d",&a,&b,&d);
		for (int j=c;j>=0;j--){
			for (int k=0;k<=j;k++){
				f[j]=max(f[j],f[j-k]+a*k*k+b*k+d);
			}
		}
	}
	printf("%lld\n",f[c]);
	return 0;
}
