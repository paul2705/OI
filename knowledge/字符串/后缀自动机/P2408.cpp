#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN=1e5+5;
struct rec{
	int len,fail;
	int nxt[30];
} st[MAXN*3];
int sz=2,last=1,n;
int f[MAXN*3];
void ins(int c){
	int cur=sz++;
//	cout<<c<<endl;
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
			int coln=sz++;
			st[coln].len=st[p].len+1;
			st[coln].fail=st[q].fail;
//			st[coln].nxt=st[q].nxt;
			for (int i=1;i<=26;i++) st[coln].nxt[i]=st[q].nxt[i];
			while (p!=-1&&st[p].nxt[c]==q){
				st[p].nxt[c]=coln;
				p=st[p].fail;
			}
			st[q].fail=st[cur].fail=coln;
		}
	}
	last=cur;
}
void dfs(int u){
//	getchar();
	printf("id:%d fail:%d len:%d\n",u,st[u].fail,st[u].len);
//	for (char c=1;c<=26;c++){
//		if (st[u].nxt[c]) printf("(%d,%d) ",st[u].nxt[c],c);
//	}
//	cout<<endl;
	for (char c=1;c<=26;c++){
		if (st[u].nxt[c]) dfs(st[u].nxt[c]);
	}
}
/*void dfs(int u){
//	bool flag=0;
//	cout<<u<<endl;
	f[u]=1;
	for (int c=1;c<=26;c++){
		if (st[u].nxt[c]>0){
//			flag=1;
			dfs(st[u].nxt[c]);
			f[u]+=f[st[u].nxt[c]];
		}
	}
//	if (flag==0) f[u]=1;
}*/
char s[MAXN];
int main(){
	st[1].len=0; st[1].fail=-1;
	scanf("%d",&n);
	scanf("%s",s);
	for (int i=0;i<n;i++){
//		char c=getchar();
//		while (c<'a'||c>'z') c=getchar();
		ins(s[i]-'a'+1);
	}
//	dfs(1);
	dfs(1);
	printf("%d\n",f[1]-1);
	return 0;
}
