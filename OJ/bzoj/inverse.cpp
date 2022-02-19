#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e2+res<<endl;
	return cnt==res;
}
void dg(int d){
	if (d==n+1) ans+=check();
	for (int i=1;i<=n;i++){
		if (!use[i]){
			use[i]=1; b[d]=i;
			dg(d+1);
			use[i]=0;
		}
	}
}
int main(){
	scanf("%d",&T);
	while (T--){
		memset(use,0,sizeof(use));
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		dg(1);
		printf("%d\n",ans);
	}
	return 0;
}
