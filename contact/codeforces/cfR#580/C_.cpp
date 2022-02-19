#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e2;
int n,a[MAXN];
bool use[MAXN];
void dfs(int d){
	if (d==n+1){
		int s=a[1]+a[2]+a[3];
		for (int i=1;i<=n;i++) a[n+i]=a[i];
		for (int i=2;i<=n+1;i++){
			int ns=s-a[i-1]+a[i+2];
			if (abs(ns-s)>1) return;
			s=ns;
		}
		for (int i=1;i<=n;i++) printf("%d ",a[i]);
		printf("\n");
		return;
	}
	for (int i=1;i<=n;i++){
		if (use[i]) continue;
		use[i]=1; a[d]=i;
		dfs(d+1);
		use[i]=0;
	}
}
int main(){
	scanf("%d",&n); n*=2;
//	cout<<n<<endl;
	dfs(1);
	return 0;
}
