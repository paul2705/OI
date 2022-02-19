#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e6+5;
const int MAXM=MAXN;
int edge,head[MAXN],nex[MAXM],tail[MAXM],w[MAXN],cnt[MAXN];
int n,M,ans,rt=0;
string s;
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
void ins(){
	int len=s.length();
	int u=rt;
	for (int i=0;i<len;i++){
		int x=s[i]-'a'+1;
		if (s[i]>='A'&&s[i]<='Z') x=s[i]-'A'+27;
		if (s[i]==' ') x=0;
		int pos=-1;
		for (int e=head[u];e;e=nex[e]){
			if (w[e]==x){ pos=tail[e]; break; }
		}
		if (pos<0){ M++; add(u,M,x); u=M; }
		else u=pos;
		cnt[u]++;
		ans=max(ans,cnt[u]*(i+1));
	}
}
int main(){
	scanf("%d\n",&n);
	for (int i=1;i<=n;i++){
		getline(cin,s);
		ins();
	}
	printf("%d\n",ans);
	return 0;
}
