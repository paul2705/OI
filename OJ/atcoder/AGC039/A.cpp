#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e2+5;
char s[MAXN];
ll n,k;
bool fl;
int main(){
	scanf("%s",s+1);
	scanf("%lld",&k);
	n=strlen(s+1);
	for (int i=2;i<=n;i++){
		if (s[i]!=s[i-1]) fl=1;
	}
	for (int i=1;i<=n;i++) s[i+n]=s[i];
	ll cnt1=0,cnt2=0;
	for (int i=1;i<=n;i++){
		if (s[i]==s[i-1]) s[i]='#',cnt1++;
	}
	for (int i=n+1;i<=2*n;i++){
		if (s[i]==s[i-1]) s[i]='#',cnt2++;
	}
	if (!fl) printf("%lld\n",cnt1*((k+1ll)/2ll)+cnt2*(k/2ll));
	else printf("%lld\n",cnt1+cnt2*(k-1ll));
	return 0;
}
