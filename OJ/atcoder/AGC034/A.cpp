#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
int a[MAXN];
int n,A,B,C,D;
bool fl;
int main(){
	scanf("%d",&n);
	scanf("%d%d%d%d",&A,&B,&C,&D);
	for (int i=1;i<=n;i++){
		char c=getchar(); while (c!='.'&&c!='#') c=getchar();
		a[i]=(c=='#');
	}
	for (int i=A;i<C;i++){
		if (a[i]&&a[i+1]) fl=1;
	}
	for (int i=B;i<D;i++){
		if (a[i]&&a[i+1]) fl=1;
	}
	if (fl||C==D) return printf("No\n"),0;
	if (C<D) return printf("Yes\n"),0;
	fl=1;
	for (int i=B;i<=D;i++){
		if (!a[i-1]&&!a[i]&&!a[i+1]) fl=0;
	}
	if (fl) printf("No\n");
	else printf("Yes\n");
	return 0;
}
