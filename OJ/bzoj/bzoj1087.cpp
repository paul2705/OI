#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define bitset<int> bs;
int f[10][100][(1<<9)+5];
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) dp[1][1][(1<<i)]=1;
	for (int i=1;i<=n;i++){
		for (bs s=0;s<(1<<n);s++){
			int cnt=s.count();
			
