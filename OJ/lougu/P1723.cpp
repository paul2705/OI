#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1e5+5;
char str[MAXN],tmp[MAXN<<1];
int len[MAXN<<1];
int manacher(char *st,int l){
	int mx=0,ans=0,po=0;
	for (int i=1;i<=l;i++){
		if (mx>i) len[i]=min(mx-i+1,len[2*po-i]);
		else len[i]=1;
		while (st[i-len[i]]==st[i+len[i]]) len[i]++;
		if (len[i]+i-1>mx) mx=len[i]+i-1,po=i;
		ans=max(ans,len[i]);
	}
	return ans-1;
}
int main(){
	int T; scanf("%d",&T);
	while (T--){
		cin>>str;
		int l=strlen(str);
		tmp[0]='@';
		for (int i=1;i<=2*l;i+=2) tmp[i]='#',tmp[i+1]=str[i/2];
		tmp[2*l+1]='#'; tmp[2*l+2]='$';
		cout<<manacher(tmp,2*l+1)<<endl;
	}
	return 0;
}
