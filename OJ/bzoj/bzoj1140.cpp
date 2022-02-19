#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3e6+6;
int t[MAXN][3];
int st[MAXN],tp,tot,tim;
int n,fail[MAXN],use[MAXN];
int tg[MAXN],id[MAXN];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		char c=getchar(); while (c!='0'&&c!='1'&&c!='B'&&c!='X') c=getchar();
		if (c=='0'){ t[st[tp]][0]=++tot; st[++tp]=tot; }
		if (c=='1'){ t[st[tp]][1]=++tot; st[++tp]=tot; }
		if (c=='B'){ tp--; }
		if (c=='X'){ id[st[tp]]=++tim; }
	}
	
