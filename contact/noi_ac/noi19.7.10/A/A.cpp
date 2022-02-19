#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXT=1e6+6;
int t[MAXT][30],str[MAXT];
int f[MAXT],g[MAXT];
int n,rt,M;
char s[MAXT];
void ins(){
	int n=strlen(s);
	int u=rt;
	for (int i=n-1;i>=0;i--){
		int x=s[i]-'A';
		if (!t[u][x]) t[u][x]=++M;
		u=t[u][x];
	}
	str[u]++;
}
void dfs(int u){
	if (str[u]) g[u]+=str[u];
	for (int i=0;i<26;i++){
		int v=t[u][i];
		if (!v) continue;
		dfs(v);
		f[u]+=f[v]; g[u]+=g[v];
	}
	if (u!=0){
		if (g[u]>=2){
			g[u]-=2;
			f[u]++;
		}
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%s",s);
		ins();
	}
	dfs(0);
	printf("%d\n",f[0]*2);
	return 0;
}
