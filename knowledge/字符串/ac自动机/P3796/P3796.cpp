#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=2e4+5;
int t[MAXN][30],fail[MAXN];
vector<int> lis[MAXN];
int cnt[205];
int n,M=0,rt=0;
char s[1000006],a[155][105];
queue<int> q;
void ins(char s[],int len,int id){
	int u=rt;
	for (int i=0;i<len;i++){
		int x=s[i]-'a';
		if (!t[u][x]) t[u][x]=++M;
		u=t[u][x];
	}
	lis[u].push_back(id);
}
void bdfail(){
	for (int i=0;i<26;i++){
		int v=t[rt][i];
		if (v){
			fail[v]=0;
			q.push(v);
		}
	}
	while (!q.empty()){
		int u=q.front(); q.pop();
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
//		cout<<s[i]<<endl;
		int tmp=t[u][x];
		while (tmp){
			for (int j=0;j<lis[tmp].size();j++){
				int v=lis[tmp][j];
//				cout<<i<<" "<<v<<endl;
				cnt[v]++;
			}
			tmp=fail[tmp];
		}
		u=t[u][x];
	}
}
int main(){
	scanf("%d",&n);
	while (n!=0){
		for (int i=1;i<=n;i++){
			scanf("%s",a[i]);
			int len=strlen(a[i]);
			ins(a[i],len,i);
		}
		bdfail();
		scanf("%s",s);
		int len=strlen(s);
		qry(s,len);
		int mx=0;
		for (int i=1;i<=n;i++){
			mx=max(mx,cnt[i]);
		}
		printf("%d\n",mx);
		for (int i=1;i<=n;i++){
//			cout<<i<<" "<<cnt[i]<<endl;
			if (cnt[i]==mx){
				printf("%s\n",a[i]);
			}
		}
		for (int i=0;i<=M;i++){
			fail[i]=0;
			lis[i].clear();
			for (int j=0;j<26;j++) t[i][j]=0;
		}
		for (int i=1;i<=n;i++) cnt[i]=0;
		M++;
		scanf("%d",&n);
	}
	return 0;
}
