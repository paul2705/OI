#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3e5+5;
struct rec{
	int x,id;
} st[MAXN];
int s[MAXN],top;
int n,gain,d[MAXN],c[MAXN];
int main(){
	scanf("%d%d",&n,&gain);
	for (int i=1;i<=n;i++) scanf("%d%d",&d[i],&c[i]);
	for (int i=1;i<=n;i++) s[i]+=s[i-1]+gain-c[i];
	for (int i=1;i<n;i++){
		int res=(d[i+1]-d[i])*(d[i+1]-d[i]);
		while (top>0&&st[top].x<res) top--;
		st[++top]=(rec){res,i};


