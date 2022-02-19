#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
char s[MAXN];
int n,st[MAXN],top;
int ans;
int get(char c){
	switch (c){
		case '{': return -3;
		case '[': return -2;
		case '(': return -1;
		case ')': return 1;
		case ']': return 2;
		case '}': return 3;
	}
	return 0;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++){
		int x=get(s[i]);
		if (top>0&&x>0&&get(s[st[top]])+x==0) top--;
		else st[++top]=i;
//		cout<<i<<" "<<st[top]<<endl;
		ans=max(ans,i-st[top]);
	}
	printf("%d\n",ans);
	return 0;
}
