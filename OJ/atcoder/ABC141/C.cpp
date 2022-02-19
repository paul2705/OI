#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int n,k,q;
int sc[MAXN];
int main(){
	scanf("%d%d%d",&n,&k,&q);
	for (int i=1;i<=q;i++){
		int x; scanf("%d",&x);
		sc[x]++;
	}
	for (int i=1;i<=n;i++){
		sc[i]+=k-q;
//		printf("%d\n",sc[i]);
		if (sc[i]>0) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
