#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+6;
char s[MAXN],s1[MAXN];
int nxt[MAXN];
int n,m;
int main(){
	cin>>s;
	n=strlen(s);
	cin>>s1;
	m=strlen(s1);
	int j=0,k=-1; nxt[0]=-1;
	while (j<m){
		if (k==-1||s1[j]==s1[k]) nxt[++j]=++k;
		else k=nxt[k];
	}
	int i=0; j=0;
	while (i<n&&j<m){
		if (j==-1||s[i]==s1[j]) i++,j++;
		else j=nxt[j];
		if (j==m){
			printf("%d\n",i-j+1);
			j=nxt[j];
		}
	}
	for (int i=1;i<=m;i++) printf("%d ",nxt[i]);
	return 0;
}
