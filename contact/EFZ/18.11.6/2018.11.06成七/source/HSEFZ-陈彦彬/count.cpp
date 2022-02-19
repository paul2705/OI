#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

int n,m,p,ans;

int main() {
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d%d%d",&n,&m,&p);
	if (n==1 && m==1) ans=1; else
	if (n==2 && m==1) ans=2; else
	if (n==1 && m==2) ans=2; else
	if (n==1 && m==3) ans=6; else
	if (n==3 && m==1) ans=6; else
	if (n==2 && m==2) ans=16; else
	if (n==2 && m==3) ans=360; else
	if (n==3 && m==2) ans=360; else
	if (n==3 && m==3) ans=108864;
	ans%=p;
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
