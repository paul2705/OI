#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=6e2+6;
const int MAXK=65;
int f[MAXN][MAXN][MAXK];
int a[MAXN][MAXN],n,k;
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++) scanf("%d",&a[i][j]);
	}
	for (int 
