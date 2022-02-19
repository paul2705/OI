#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e5+5;
int a[MAXN],n,k,x,ans=0;
int gcd(int a,int b){ return b==0?a:gcd(b,a%b); }
int main(){
	freopen("
	scanf("%d%d",&n,&k); x=k;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]); x=gcd(x,a[i]);
	}
	for (int i=0;i<k;i+=x) ans++;
	printf("%d\n",ans);
	for (int i=0;i<k;i+=x) printf("%d ",i);
	return 0;
}
