/*
ID: paul1202
LANG: C++
TASK: sprime
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstring>
using namespace std;
const int MAXN=10;
int n;
bool check(int x){
	if (x==1) return 0;
	for (int i=2;i*i<=x;i++){
		if (x%i==0) return 0;
	}
	return 1;
}
void dfs(int d,int val){
	if (!check(val)) return;
	if (d==n){
		bool flag=1;
		int ans=val;
		while (val>0){
			flag&=check(val);
			val/=10;
			if (!flag) break;
		}
		if (flag) printf("%d\n",ans);
		return;
	}
	int lb=0;
	if (d==0) lb=2;
	for (int i=lb;i<=9;i++){
		if (d>0&&i%2==0) continue;
		if (d>0&&i==0) continue;
		if (d>0&&i==5) continue;
		int x=val*10+i;
		dfs(d+1,x);
	}
}
int main(){
	freopen("sprime.in","r",stdin);
	freopen("sprime.out","w",stdout);
	scanf("%d",&n);
	dfs(0,0);
	fclose(stdin); fclose(stdout);
	return 0;
}
