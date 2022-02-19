#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e4+5;
typedef long long ll;
const ll mod1=998244353;
const ll mod=1e9+7;
ll has[MAXN];
int n;
char s[MAXN];
int main(){
	scanf("%d",&n);
	memset(has,1,sizeof(has));
	for (int i=1;i<=n;i++){
		cin>>s;
		for (int j=0;j<strlen(s);j++){
			has[i]=(has[i]*27%mod%mod1+s[j])%mod%mod1;
		}
	}
	sort(has+1,has+n+1);
	int ans=n;
	for (int i=1;i<=n;i++){
		if (has[i]==has[i-1]) ans--;
	}
	printf("%d\n",ans);
	return 0;
}
