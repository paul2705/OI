#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=35;
int a[MAXN],b[10];
int n;
int main(){
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	scanf("%d",&n);
	for (int i=1;i<=7;i++){
		int tmp; scanf("%d",&tmp);
		a[tmp]=1;
	}
	for (int i=1;i<=n;i++){
		int cnt=0;
		for (int j=1;j<=7;j++){
			int tmp; scanf("%d",&tmp);
			cnt+=a[tmp];
		}
		b[cnt]++;
	}
	for (int i=7;i>=1;i--) printf("%d ",b[i]);
	printf("\n");
	return 0;
}
