#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN=1e5+5;
struct rec{
	int len,fail;
	map<char,int> nxt;
} st[MAXN*3];
int sz=1,last=0,n;
int f[MAXN*3];
void ins(char c){
	int cur=sz++;
	st[cur].len=st[last].len+1;
	int p=last;
	while (p!=-1&&!st[p].nxt.count(c)){
		st[p].nxt[c]=cur;
		p=st[p].fail;
	}
	if (p==-1){
		st[cur].fail=0;
	}
	else {
		int q=st[p].nxt[c];
		if (st[p].len+1==st[q].len){
			st[cur].fail=q;
		}
		else {
			int coln=sz++;
			st[coln].len=st[p].len+1;
			st[coln].fail=st[q].fail;
			st[coln].nxt=st[q].nxt;
			while (p!=-1&&st[p].nxt[c]==q){
				st[p].nxt[c]=coln;
				p=st[p].fail;
			}
			st[q].fail=st[cur].fail=coln;
		}
	}
	last=cur;
}
/*void dfs(int u){
	getchar();
	printf("id:%d fail:%d len:%d\n",u,st[u].fail,st[u].len);
	for (char c='a';c<='z';c++){
		if (st[u].nxt.count(c)) printf("(%d,%c) ",st[u].nxt[c],c);
	}
	cout<<endl;
	for (char c='a';c<='z';c++){
		if (st[u].nxt.count(c)) dfs(st[u].nxt[c]);
	}
}*/
void dfs(int u){
//	bool flag=0;
	f[u]=1;
	for (char c='a';c<='z';c++){
		if (st[u].nxt.count(c)){
//			flag=1;
			dfs(st[u].nxt[c]);
			f[u]+=f[st[u].nxt[c]];
		}
	}
//	if (flag==0) f[u]=1;
}
char s[MAXN];
int main(){
	st[0].len=0; st[0].fail=-1;
	scanf("%d",&n);
	scanf("%s",s);
	for (int i=0;i<n;i++){
//		char c=getchar();
//		while (c<'a'||c>'z') c=getchar();
		ins(s[i]);
	}
//	dfs(1);
	dfs(0);
	printf("%d\n",f[0]-1);
	return 0;
}
