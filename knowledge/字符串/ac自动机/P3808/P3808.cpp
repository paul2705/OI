#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e6+6;
int t[MAXN][30],w[MAXN],fail[MAXN];
int n,M=0,rt=0,ans;
char s[MAXN];
queue<int> q;
void ins(char s[],int len){
	int u=rt;
	for (int i=0;i<len;i++){
		int x=s[i]-'a';
		if (!t[u][x]) t[u][x]=++M;
		u=t[u][x];
	}
	w[u]++;
}
void bdfail(){
	for (int i=0;i<26;i++){
		int v=t[rt][i];
		if (v){
			fail[v]=rt;
			q.push(v);
		}
	}
	while (!q.empty()){
		int u=q.front(); q.pop();
//		cout<<u<<endl;
		for (int i=0;i<26;i++){
			int v=t[u][i];
			if (v){
				fail[v]=t[fail[u]][i];
				q.push(v);
			}
			else t[u][i]=t[fail[u]][i];
		}
	}
}
void qry(char s[],int len){
	int u=rt;
	for (int i=0;i<len;i++){
		int x=s[i]-'a';
		int tmp=t[u][x];
		while (tmp!=0&&w[tmp]!=-1){
			ans+=w[tmp];
			w[tmp]=-1;
			tmp=fail[tmp];
		}
		u=t[u][x];
	}
}
void prt(int u){
	for (int i=0;i<26;i++){
		if (!t[u][i]) continue;
		printf("%d->(%c) %d fail:%d w:%d\n",u,(char)i+'a',t[u][i],fail[t[u][i]],w[t[u][i]]);
		prt(t[u][i]);
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%s",s);
		int len=strlen(s);
		ins(s,len);
	}
	bdfail();
//	prt(0);
	scanf("%s",s);
	int len=strlen(s);
	qry(s,len);
	printf("%d\n",ans);
	return 0;
}
