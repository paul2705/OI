#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int mod=998244353;
const int MAXN=1e3+5;
const int MAXM=1e5+5;
const int MAXL=1e2+5;
int n,l,m;
struct tnode{
	int l,r,cl,cr,dat;
} t[MAXN*MAXL*8];
char a[MAXN][MAXL];
map<int,int> cnt;
int ans[MAXN];
int has[MAXN];
int main(){
	scanf("%d%d%d",&n,&l,&m);
	for (int i=1;i<=n;i++){
		scanf("%s",&a[i]);
		
