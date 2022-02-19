#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<bitset>
using namespace std;
typedef long long ll;
const double eps=1e-8;
const int MAXN=21;
const int MAXS=1<<MAXN;
int f[MAXS];
int n,c[MAXN];
ll sc;
//bitset<4> t1,t2;
bool chk(double sum,double V,ll nxt){
	double rest=sum-floor(sum/V)*V;
	double nxt_rest=V-rest;
	if (rest>eps&&c[nxt]<nxt_rest) return 0;
	else return 1;
}
bool check(ll mid){
	double V=(double)sc/(double)mid;
	for (int s=0;s<(1<<n);s++) f[s]=0;
	for (int i=0;i<n;i++) f[(1<<i)]=1;
	for (int s=0;s<(1<<n);s++){
		if (!f[s]) continue;
		ll sum=0;
		for (int i=0;i<n;i++){
			if (s&(1<<i)) sum+=c[i];
		}
		for (int i=0;i<n;i++){
			if (!(s&(1<<i))){
				int st=s|(1<<i);
				f[st]|=f[s]*chk(sum,V,i);
			}
		}
	}
	return f[(1<<n)-1];
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d",&c[i]);
		sc+=c[i];
	}
	for (int i=1;i<=n;i++){
		if (check(i)){
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}
