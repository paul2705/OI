#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=4e3+5;
int a[MAXN],b[MAXN],c[MAXN];
char tmp[MAXN];
int main(){
	cin>>tmp;
	a[0]=strlen(tmp);
	for (int i=1;i<=a[0];i++){
		a[i]=tmp[a[0]-i]-'0';
	}
	cin>>tmp;
	b[0]=strlen(tmp);
	for (int i=1;i<=b[0];i++){
		b[i]=tmp[b[0]-i]-'0';
	}
	for (int i=1;i<=a[0];i++){
		for (int j=1;j<=b[0];j++){
			c[i+j-1]+=a[i]*b[j];
		}
	}
	int n=a[0]+b[0];
	for (int i=1;i<n;i++){
		c[i+1]+=c[i]/10;
		c[i]%=10;
	}
	while (c[n]==0&&n>1) n--;
	for (int i=n;i>=1;i--) printf("%d",c[i]);
	printf("\n");
	return 0;
}
