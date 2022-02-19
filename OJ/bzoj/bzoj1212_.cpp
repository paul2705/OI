#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<bitset>
using namespace std;
const int MAXN=2e6+6;
const int MAXT=1e3+5;
int t[MAXT][30],fail[MAXT],ed[MAXT];
bool f[MAXN];
int n,m,M=1;
char s[MAXN];
int ans=0;
queue<int> q;
void ins(){
	int len=strlen(s);
	int u=0;
	for (int i=0;i<len;i++){
		int x=s[i]-'a';
		if (!t[u][x]) u=t[u][x]=++M;
		else u=t[u][x];
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
//		cout<<u<<endl;
		for (int i=0;i<26;i++){
			int v=t[u][i];
			if (v==0){
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
		int y=t[u][x];
		while (y){
			f[i+1]|=f[i+1-ed[y]];
			y=fail[y];
		}
		u=t[u][x];
	}
	return;
}
int main(){
	scanf("%d%d\n",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%s",s);
		ins();
	}
	build();
	for (int i=1;i<=m;i++){
		scanf("%s",s);
		memset(f,0,sizeof(f)); f[0]=1;
		mth();
		int len=strlen(s);
		for (int i=len;i>=0;i--){
			if (f[i]){
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
