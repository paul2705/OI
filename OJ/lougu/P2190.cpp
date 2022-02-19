#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e6*2+5;
typedef long long ll;
ll b[MAXN],n,m,x,y,z,sm,ss;
int main(){
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&x,&y,&z);
		if (x<y) b[x]+=z,b[y]-=z;
		else b[x]+=z,b[1]+=z,b[y]-=z;
	}
	for (int i=1;i<=n;i++){
		ss+=b[i];
		sm=max(sm,ss);
	}
	printf("%lld\n",(sm+35)/36);
	return 0;
}	
