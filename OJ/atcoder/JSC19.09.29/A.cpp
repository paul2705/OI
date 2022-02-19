#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e6+5;
int n,m;
int a[MAXN],b[MAXN];
int use[MAXN];
int posx[MAXN],posy[MAXN];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++) scanf("%d",&b[i]);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			int tmp=a[i]+b[j];
			if (use[tmp]) return printf("%d %d %d %d\n",posx[tmp]-1,posy[tmp]-1,i-1,j-1),0;
			else use[tmp]=1,posx[tmp]=i,posy[tmp]=j;
		}
	}
	printf("-1\n");
	return 0;
}
