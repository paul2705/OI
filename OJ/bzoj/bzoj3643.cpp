#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int MAXN=1e6+6;
int chk[MAXN],pri[MAXN];
int n,m;
ll ans;
bool isprime(int x){
	for (int i=2;i*i<=x;i++){
		if (x%i==0) return 0;
	}
	return 1;
}
void search(int s,int y,ll x){
	if (x>=ans) return;
	if (y==1){ ans=x; return; }
	if (y>m&&isprime(y+1)){ ans=min(ans,x*(ll)(y+1)); return; }
	for (int i=s;i<=pri[0];i++){
		if (y%(pri[i]-1)==0){
			int cnt=y/(pri[i]-1); ll res=x*(ll)pri[i]; 
			search(i+1,cnt,res);
			while (cnt%pri[i]==0){
				cnt/=pri[i]; res*=(ll)pri[i];
				search(i+1,cnt,res);
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	int m=sqrt(n)+1; ans=(1ll<<31);
	for (int i=2;i<=m;i++){
		if (!chk[i]) pri[++pri[0]]=i;
		for (int j=1;j<=pri[0];j++){
			if (i*pri[j]>m) break;
			chk[i*pri[j]]=1;
			if (i%pri[j]==0) break;
		}
	}
	search(1,n,1);
	printf("%lld\n",ans==(1ll<<31)?-1:ans);
	return 0;
}
