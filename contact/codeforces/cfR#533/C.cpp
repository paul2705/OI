#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
const int mod=1e9+7;
int n,l,r;
ll f[MAXN][5];
ll cnt[5];
int main(){
	scanf("%d%d%d",&n,&l,&r);
	int cl=(l/3+1)*3,cr=(r/3)*3;
	cnt[0]=(cr/3-cl/3+1);
	cnt[1]=cnt[2]=(cr/3-cl/3);
	for (int i=l;i<cl;i++) cnt[i%3]++;
	for (int i=cr+1;i<=r;i++) cnt[i%3]++;
//	cout<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<endl;
	for (int i=0;i<3;i++) cnt[i]%=mod,f[1][i]=cnt[i];
	for (int i=2;i<=n;i++){
		for (int j=0;j<3;j++){
			for (int k=0;k<3;k++) 
				f[i][(j+k)%3]=(f[i][(j+k)%3]+f[i-1][j]*cnt[k]%mod)%mod;
		}
//		cout<<f[i][0]<<" "<<f[i][1]<<" "<<f[i][2]<<endl;
	}
//	printf("%d\n",f[n][0]);
	cout<<f[n][0]<<endl;
	return 0;
}
