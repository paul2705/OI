#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3e5+5;
const int MAXM=6e5+5;
int edge,head[MAXN],nex[MAXM],tail[MAXM];
int n,m,a[MAXN];
int main(){
	scanf("%d%d",&n,&m);
	
