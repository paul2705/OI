#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e3+5;
ll f[MAXN];
int n;
int main(){
	scanf("%d",&n);
	f[0]=1;
	for (int i=1;i<=n;i++){
		for (int j=0;j<=i/2;j++) f[i]+=f[j];
	}
	printf("%lld\n",f[n]);
	return 0;
}
