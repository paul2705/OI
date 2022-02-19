#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e5+5;
int t[MAXN][32];
int n,m,M=3;
char s[100];
bool use[MAXN];
void ins(){
	int len=strlen(s);
	int pos=1;
	for (int i=0;i<len;i++){
		if (t[pos][s[i]]==0) t[pos][s[i]]=++M;
		pos=t[pos][s[i]];
	}
}
int find(){
	int pos=1;
	int len=strlen(s);
	for (int i=0;i<len;i++){
		if (t[pos][s[i]]) pos=t[pos][s[i]];
		else return 0;
	}
	if (!use[pos]) return use[pos]=1,1;
	else return 2;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		cin>>s;
		ins();
	}
	scanf("%d",&m);
	for (int i=1;i<=m;i++){
		cin>>s;
		int x=find();
		if (x==0) printf("WRONG\n");
		if (x==2) printf("REPEAT\n");
		if (x==1) printf("OK\n");
	}
	return 0;
}
