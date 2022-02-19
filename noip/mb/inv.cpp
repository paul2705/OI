#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3e6+6;
typedef long long ll;
ll inv[MAXN],n,p;
int main(){
		scanf("%lld%lld",&n,&p);
		inv[1]=1; cout<<1<<endl;
		for (int i=2;i<=n;i++){
			inv[i]=(p-inv[p%i]*(p/i)%p)%p;
			printf("%lld\n",inv[i]);
		}
		return 0;
}
