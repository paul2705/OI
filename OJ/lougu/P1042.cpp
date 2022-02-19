#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=7e4+5;
int a[MAXN],cnt=0;
int ans[5];
int main(){
	char c;
	c=getchar();
	while (c!='E'){
		if (c=='W') a[++cnt]=0;
		if (c=='L') a[++cnt]=1;
		c=getchar();
	}
	ans[0]=ans[1]=0;
	for (int i=1;i<=cnt;i++){
		ans[a[i]]++;
		if (abs(ans[0]-ans[1])>=2&&(ans[0]>=11||ans[1]>=11)){
			printf("%d:%d\n",ans[0],ans[1]);
			ans[0]=ans[1]=0;
		}
	}
	printf("%d:%d\n\n",ans[0],ans[1]);
	ans[0]=ans[1]=0;
	for (int i=1;i<=cnt;i++){
		ans[a[i]]++;
		if (abs(ans[0]-ans[1])>=2&&(ans[0]>=21||ans[1]>=21)){
			printf("%d:%d\n",ans[0],ans[1]);
			ans[0]=ans[1]=0;
		}
	}
	printf("%d:%d\n",ans[0],ans[1]);
	return 0;
}
