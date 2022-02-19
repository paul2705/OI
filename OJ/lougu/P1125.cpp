#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN=105;
char s[MAXN];
int cnt[MAXN];
int main(){
	scanf("%s",s);
	for (int i=0;i<26;i++) cnt[i]=-1;
	for (int i=0;i<strlen(s);i++){
		cnt[s[i]-'a']++;
	}
	int mx=0,mn=105;
	for (int i=0;i<26;i++){
		if (cnt[i]==-1) continue;
//		cout<<i<<" "<<cnt[i]<<endl;
		mx=max(mx,cnt[i]);
		mn=min(mn,cnt[i]);
	}
	int tmp=mx-mn,fg=1;
	for (int i=2;i*i<=tmp;i++){
		if (tmp%i==0) fg=0;
	}
	if (fg&&tmp>1) printf("Lucky Word\n%d",tmp);
	else printf("No Answer\n0");
	return 0;
}
