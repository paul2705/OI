#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5000;
const int mod=1e9+7;
struct rec{
	int a[MAXN][MAXN];
} A,B;
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=10;i++){
		for (int j=0;j<m;j++){
			for (int k=1;k<=i;k++){
				for (int l=0;l<m;l++){
					A.a[(i-1)*10+j][(k-1)*10+l]++;
				}
			}
		}
	}
	B=mod_pow(A,n);
	int ans=0;
	for (int i=1;i<=
