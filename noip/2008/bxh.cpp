#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int cnt[30];
char s[105];
bool check(int x){
	if (x==0||x==1) return 0;
	for (int i=2;i*i<=x;i++){
		if (x%i==0) return 0;
	}
	return 1;
}
int main(){
	cin>>s;
	for (int i=0;i<strlen(s);i++){
//		cout<<s[i]-96<<endl;
		cnt[s[i]-96]++;
	}
	int mx=0,mn=1e9;
	for (int i=1;i<=26;i++){
		mx=max(mx,cnt[i]);
		if (cnt[i]>0) mn=min(mn,cnt[i]);
	}
	if (check(mx-mn)) printf("Lucky Word\n%d\n",mx-mn);
	else printf("No Answer\n0\n");
	return 0;
}
