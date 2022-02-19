#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+5;
const int MAXM=MAXN*3;
struct rec{
	int len,fail;
	int nxt[30];
} st[MAXM];
int n,m,last=1,sz=2;
char s[MAXN];
void ins(int c){
	int cur=sz++;
	st[cur].len=st[last].len+1;
	int p=last;
	while (p!=-1&&st[p].nxt[c]==0){
		st[p].nxt[c]=cur;
		p=st[p].fail;
	}
	if (p==-1){
		st[cur].fail=1;
	}
	else {
		int q=st[p].nxt[c];
		if (st[p].len+1==st[q].len){
			st[cur].fail=q;
		}
		else {
			int clone=sz++;
			st[clone].len=st[p].len+1;
			st[clone].fail=st[q].fail;
			for (int i=1;i<=26;i++) st[clone].nxt[i]=st[p].nxt[i];
			while (p!=-1&&st[p].nxt[c]==q){
				st[p].nxt[c]=clone;
				p=st[p].fail;
			}
			st[cur].fail=st[q].fail=clone;
		}
	}
	last=cur;
}
void dfs(int u){
	printf("id:%d fail:%d\n",u,st[u].fail);
	for (int i=1;i<=26;i++){
		if (st[u].nxt[i]>0) dfs(st[u].nxt[i]);
	}
}
int main(){
	st[1].len=0; st[1].fail=-1;
	scanf("%s",s);
	int l=strlen(s);
	for (int i=0;i<l;i++) ins(s[i]-'a'+1);
	dfs(1);
	return 0;
}
