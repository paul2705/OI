#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=2e6+6;
const int MAXM=2e3+5;
int n,m,M;
int t[MAXM][30],fail[MAXM],ed[MAXM];
int f[MAXN];
char s[MAXN];
queue<int> q;
void ins(){
	int len=strlen(s);
	int u=0;
	for (int i=0;i<len;i++){
		int x=s[i]-'a';
		if (!t[u][x]) t[u][x]=++M;
		u=t[u][x];
	}
	ed[u]=len;
}
void build(){
	for (int i=0;i<26;i++){
		int v=t[0][i];
		if (v) q.push(v);
	}
	while (!q.empty()){
		int u=q.front(); q.pop();
		for (int i=0;i<26;i++){
			int v=t[u][i];
			if (!v){
				t[u][i]=t[fail[u]][i];
				continue;
			}
			fail[v]=t[fail[u]][i];
			q.push(v);
		}
	}
}
void mth(){
	int len=strlen(s);
	int u=0;
	for (int i=0;i<len;i++){
		int x=s[i]-'a';
		int v=t[u][x];
		while (v){
			f[i+1]|=f[i+1-ed[v]];
			v=fail[v];
		}
		u=t[u][x];
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%s",s);
		ins();
	}
	build();
	for (int i=1;i<=m;i++){
		scanf("%s",s);
		int len=strlen(s);
		memset(f,0,sizeof(f)); f[0]=1;
		mth();
		for (int j=len;j>=0;j--){
			if (f[j]){
				printf("%d\n",j);
				break;
			}
		}
	}
	return 0;
}
