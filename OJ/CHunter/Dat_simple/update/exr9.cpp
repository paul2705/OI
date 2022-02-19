#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e6+6;
int n,m;
char s1[MAXN],s2[MAXN];
int pos1,pos2;
int calc(char *s){
	int l=strlen(s+1);
	for (int i=1;i<=l;i++) s[i+l]=s[i];
	int i=1,j=2,k;
	while (i<=l&&j<=l){
		k=0;
		while (k<=l&&s[i+k]==s[j+k]) k++;
		if (k==l) break;
		if (s[i+k]>s[j+k]) i+=k+1;
		else j+=k+1;
		if (i==j) i++;
	}
	return min(i,j);
}
bool check(int x,int y){
	for (int i=0;i<n;i++){
		if (s1[i+x]!=s2[i+y]) return 0;
	}
	return 1;
}
int main(){
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	n=strlen(s1+1);
	m=strlen(s2+1);
	pos1=calc(s1);
	pos2=calc(s2);
	if (n==m&&check(pos1,pos2)){
		printf("Yes\n");
		for (int i=pos1;i<=pos1+n-1;i++) printf("%c",s1[i]);
		printf("\n");
	}
	else printf("No\n");
	return 0;
}
