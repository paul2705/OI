#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() puts("okkkkkkkk")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
using namespace std;
typedef long long LL;
const int inf = 1 << 30;
int T;
char s[2333],ap[2333],bp[2333],t[2333];
int main(){
	scanf("%d",&T);
	while (T--){
		int ts=0,tp=0;
		memset(ap,0,sizeof ap);
		memset(bp,0,sizeof bp);
		for (int i=1;i<=6;i++){
			scanf("%s",s+1);
			if (s[2]=='J')++ts;
		}
		for (int i=1;i<=6;i++){
			scanf("%s",s+1);
			if (s[2]=='J')++tp;
		}
		for (int i=1;i<=7;i++){
			for (int j=1;j<=6;j++){
				scanf("%s",s+1);
			}
		}
		scanf("%s",t+1);
		if (tp==2) puts("First");
		else puts("Second");
	}
	return 0;
}
