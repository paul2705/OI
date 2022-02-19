#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3e5+5;
char s[MAXN];
double f[MAXN],l[MAXN];
int n;
int main(){
	scanf("%d%s",&n,s);
	for (int i=0;i<n;i++){
		if (s[i]=='o') f[i]=f[i-1]+l[i-1]*2+1,l[i]=l[i-1]+1;
		else if (s[i]=='x') f[i]=f[i-1],l[i]=0;
		else f[i]=f[i-1]+(l[i-1]*2+1)/2,l[i]=(l[i-1]+1)/2;
	}
	printf("%.4lf\n",f[n-1]);
	return 0;
}
