#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=2e5+5;
const int MAXS=2e5+5;
int n,k,ans;
int dsr[MAXN],bel[MAXN];
int st[MAXN],top;
char s[MAXS];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1); k=sqrt(n);
	for (int i=1;i<=n;++i){
		if (s[i]=='0') st[++top]=i;
		bel[i]=top;
	}
	int pos=0;
	for (int i=n;i>=1;--i){
		dsr[i]=pos;
		if (s[i]=='1') pos=i;
	}
	for (int gs=1;gs<=top;++gs){
		int pos=dsr[st[gs]],tmp=gs;
		if (!pos) continue;
		for (;pos;pos=dsr[pos]){
			if (bel[pos]+gs>top) break;
			pos=st[bel[pos]+gs];
			tmp+=gs+1;
		} 
		if (tmp!=gs) ans=max(ans,tmp);
	}
	printf("%d\n",ans);
	return 0;
}
