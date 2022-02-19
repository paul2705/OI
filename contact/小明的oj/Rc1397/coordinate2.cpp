#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+6;
int n,ans=1e9,ret=0;
int gcd(int a,int b){
	if (b==0){
		ret=1e9;
		return a;
	}
	if (b==1||a==1){
		if (a==1) ret+=b-1;
		else ret+=a-1;
		return 1;
	}
	ret+=a/b;
	return gcd(b,a%b);
}
int main(){
	freopen("coordinate.in","r",stdin);
	freopen("coordinate.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		ret=0;
		int d=gcd(n,i);
		ans=min(ans,ret);
	}
	printf("%d\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
