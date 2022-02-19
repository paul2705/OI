#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
typedef long long ll;
char s[MAXN],b[MAXN];
int n,f[MAXN];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	int cnt=0;
	for (int i=1;i<=n;){
		if (s[i]=='A') f[i]=f[i-1]+1,i++;
		else if (s[i]=='B'&&s[i+1]=='C') f[i+1]=f[i]=f[i-1],i+=2;
		else f[i]=0,i++;
//		cout<<i<<" "<<s[i]<<" "<<f[i]<<endl;
	}
	ll ans=0;
	for (int i=1;i<n;i++){
		if (s[i]=='B'&&s[i+1]=='C') ans+=f[i];
	}
	printf("%lld\n",ans);
	return 0;
}
