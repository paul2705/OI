#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXS=1e2+5;
const int MAXN=5e3+5;
int n;
char s[MAXN][MAXS];
void solve1(){
	int p1=strlen(s[1])-1,p2=strlen(s[2])-1;
	for (;p1>=0&&p2>=0;p1--,p2--){
		if (s[1][p1]!=s[2][p2]) break;
	}
	if (p1==strlen(s[1])-1&&p2==strlen(s[2])-1) printf("0\n");
	else printf("2\n");
}
void solve2(){

}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%s",s[i]);
	if (n==2) solve1();
	else solve2();
	return 0;
}
