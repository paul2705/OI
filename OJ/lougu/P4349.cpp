#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e6+6;
const int mod=1e9+7;
int n,m,ans;
ll sum,t;
char c[MAXN];
int main(){
	scanf("%d%d",&n,&m);
	cin>>c;
	for (int i=0;i<n;i++){
		t=(t*10+c[i]-'0')%m;
		if (!t) ans++;
	}
	if (t) return printf("0\n"),0;
	ans--;
	sum=1,t=2;
	while (ans){
		if (ans%2==1) sum=(sum*t)%mod;
		t=(t*t)%mod;
		ans>>=1;
	}
	printf("%lld\n",sum);
	return 0;
}
