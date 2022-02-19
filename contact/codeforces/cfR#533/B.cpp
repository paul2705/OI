#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=2e5+5;
int n,k,ans;
int s[MAXN],res[30],cnt;
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		char c=getchar(); while(c<'a'||c>'z') c=getchar();
		s[i]=c-'a'+1;
		if (s[i]==s[i-1]) cnt++;
		else res[s[i-1]]+=cnt/k,cnt=1;
	}
	res[s[n]]+=cnt/k;
	for (int i=1;i<=26;i++) ans=max(ans,res[i]);
	printf("%d\n",ans);
	return 0;
}
