#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int n,m,a,t[MAXN],l[MAXN];
int ans;
int main(){
	scanf("%d%d%d",&n,&m,&a);
	for (int i=1;i<=n;i++) scanf("%d%d",&t[i],&l[i]);
	t[0]=0;t[n+1]=m;
	for (int i=1;i<=n+1;i++){
		int las=t[i]-t[i-1]-l[i-1];
		ans+=las/a;
	}
	cout<<ans<<endl;
	return 0;
}
