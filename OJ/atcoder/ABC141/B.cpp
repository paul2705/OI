#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e2+5;
char s[MAXN];
int main(){
	cin>>s;
	int n=strlen(s);
	for (int i=0;i<n;i++){
		if (i%2==0&&s[i]=='L') return printf("No\n"),0;
		if (i%2==1&&s[i]=='R') return printf("No\n"),0;
	}
	printf("Yes\n");
	return 0;
}
