#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=15;
const int MAXC=1e7+5;
int n,cnt[MAXC],mx;
int gcd(int a,int b){ return b==0?a:gcd(b,a%b); }
int lcm(int a,int b){ return a*b/gcd(a,b); }
void dfs(int n,int las,int l){
	if (n<=1){
		cnt[l]++;
		mx=max(mx,l);
		return;
	}
	for (int i=las;i<=n;i++){
//		cout<<l<<" "<<i<<" "<<lcm(l,i)<<endl;
		dfs(n-i,i,lcm(l,i));
	}
}
int main(){
//	scanf("%d",&n);
	n=1;
	while (n<=50){
		memset(cnt,0,sizeof(cnt));
		dfs(n,1,1);
		int ans=0;
		for (int i=1;i<=mx;i++){
			ans+=(cnt[i]>0);
		}
		printf("%d %d\n",n,ans);
//		printf("%d\n",ans);
		n++;
	}
	return 0;
}
