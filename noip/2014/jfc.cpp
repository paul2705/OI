#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e2+5;
int n,m,a[MAXN];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++){
		int ret=i,ans=0;
		for (int j=0;j<=n;j++){
			ans+=ret*a[j];
			ret=ret*ret;
		}
		cout<<ans<<endl;
		if (ans==0) printf("%d\n",i);
	}
	return 0;
}
