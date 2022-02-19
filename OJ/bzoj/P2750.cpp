#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[10][10][10][10][10];
int main(){
	char c;
	scanf("%c",&c);
	if (c=='W'){
		char s[50];
		cin>>s;
		for (int i=0;i<25;i++){
			for (ans[i]='A';ans[i]<s[i];ans[i]++){
				memset(dp,0,sizeof(dp));
				int tmp=dfs(0,0,0,0,0);

