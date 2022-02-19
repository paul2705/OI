#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int cnt;
char c;
int main(){
	c=getchar();
	while (c!='@'){
		if (c=='(') cnt++;
		if (c==')') cnt--;
		if (cnt<0) return printf("NO\n"),0;
		c=getchar();
	}
	if (cnt!=0) printf("NO\n");
	else printf("YES\n");
	return 0;
}
