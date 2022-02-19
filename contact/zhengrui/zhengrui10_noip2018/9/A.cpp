#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=3e5+5;
const int MAXM=1e6+6;
int edge,head[MAXN],nex[MAXM],tail[MAXM],w[MAXM];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1,l,r;i<=n;i++){
		scanf("%d%d",&l,&r);
		add(
