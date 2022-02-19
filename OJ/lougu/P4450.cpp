#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+6;
int pri[MAXN],phi[MAXN];
int n,m,ans=1,d;
bool use[MAXN];
int gcd(int a,int b){ return b==0?a:gcd(b,a%b); }
int main(){
	scanf("%d%d%d",&n,&m,&d); phi[1]=1;
	n/=d; m/=d;
	if (n>m) swap(n,m);
	for (int i=2;i<=n;i++){
		if (!use[i]){
			pri[++pri[0]]=i;
			phi[i]=i-1;
		}
		for (int j=1;j<=pri[0];j++){
			if (i*pri[j]>n) break;
			use[i*pri[j]]=1;
			if (i%pri[j]==0){
				phi[i*pri[j]]=phi[i]*pri[j];
				break;
			}
			else phi[i*pri[j]]=phi[i]*phi[pri[j]];
		}
//		cout<<i<<" "<<phi[i]<<endl;
		ans+=phi[i]*2;
	}
	for (int i=n+1;i<=m;i++){
		for (int j=1;j<=n;j++){
			if (gcd(i,j)==1) ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
