#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int mx=1,n,m;
int main(){
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i*i<=m&&i<=n;i++){
		if (m%i==0){
			mx=max(mx,i);
			if (m/i<=n) mx=max(mx,m/i);
		}
	}
	printf("%d\n",mx);
	fclose(stdin); fclose(stdout);
	return 0;
}
