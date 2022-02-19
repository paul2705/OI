#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
char a[MAXN],b[MAXN],c[MAXN];
int n,m;
int main(){
	scanf("%s\n%s",b,a);
	n=strlen(a),m=strlen(b);
	int pos=0;
	for (int i=0;i<n;i++,pos++){
		if (pos==m) pos=0;
		int x,y;
		if (a[i]>='A'&&a[i]<='Z') x=a[i]-'A';
		else x=a[i]-'a';
		if (b[pos]>='A'&&b[pos]<='Z') y=b[pos]-'A';
		else y=b[pos]-'a';
		x-=y;
		if (x<0) x+=26;
		if (a[i]>='A'&&a[i]<='Z') c[i]='A'+x;
		else c[i]='a'+x;
	}
	printf("%s\n",c);
	return 0;
}
