#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
int n,b;
ll t[3][2*MAXN],s,ans;
int main(){
	scanf("%d%d",&n,&b);
	bool f=0; t[0][n]=1;
	for (int i=1,x;i<=n;i++){
		scanf("%d",&x);
		if (x<b) s--;
		else if (x>b) s++;
		f|=(x==b);
		t[f][s+n]++;
	}
	for (int i=0;i<=2*n;i++) ans+=t[0][i]*t[1][i];
	printf("%lld\n",ans);
	return 0;
}
