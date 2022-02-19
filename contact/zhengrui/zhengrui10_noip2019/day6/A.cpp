#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int n,ans;
int main(){
	scanf("%d",&n); n--;
	for (int i=1;i<=n;i++){
		if (n%i==0) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
