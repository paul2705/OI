#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+6;
int n,nxt[MAXN];
char a[MAXN],b[MAXN];
int la,lb;
int main(){
	scanf("%s\n",a+1);
	scanf("%s\n",b+1);
	la=strlen(a+1); lb=strlen(b+1);
	nxt[1]=0;
	for (int i=2;i<=n;i++){
		int j=nxt[i-1];
		while (j>0&&b[j]!=b[i]) j=nxt[j];
		nxt[i]=j+1;
	}

