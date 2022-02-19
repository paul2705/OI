#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int mod=1e9+7;
int a[MAXN],t[MAXN];
int n,s[MAXN];
int sum(int x){
	int res=0;
	for (;x;x-=x&(-x)) res+=t[x],res%=mod;
	return res;
}
void add(int x,int val){
	for (;x<=MAXN;x+=x&(-x)) t[x]+=val,t[x]%=mod;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++){
		s[i]=sum(a[i]-1)+1;
		add(a[i],s[i]);
	}
	int ans=0;
	for (int i=1;i<=n;i++) ans+=s[i],ans%=mod;
	printf("%d\n",(ans+mod)%mod);
	return 0;
}
