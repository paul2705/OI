#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+6;
char st[MAXN];
int top;
char s[MAXN];
int n,ans;
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++){
		top=0;
		for (int j=i;j<=n;j++){
			if (top>0&&st[top]==s[j]) top--;
			else st[++top]=s[j];
			if (top==0) ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
