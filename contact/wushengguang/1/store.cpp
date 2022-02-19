#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
ll n,m;
struct rec{
	ll a,b;
} a[MAXN];
int main(){
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%lld%lld",&a[i].a,&a[i].b);
	}

