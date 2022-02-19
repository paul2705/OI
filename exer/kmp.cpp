#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+6;
char a[MAXN],b[MAXN];
int nxt[MAXN];
int n,m;
int main(){
	scanf("%s",a+1); scanf("%s",b+1);
	n=strlen(a+1); m=strlen(b+1);
	nxt[0]=-1;
	for (int i=1;i<=m;i++){
		int pre=nxt[i-1];
		while (pre>=0&&b[pre+1]!=b[i]) pre=nxt[pre];
		nxt[i]=pre+1;
//		cout<<i<<" "<<nxt[i]<<endl;
	}
	int stp=0;
	for (int i=1;i<=n;i++){
//		cout<<stp<<endl;
		if (a[i]==b[stp+1]) stp++;
		else{
			while (stp>=0&&a[i]!=b[stp+1]) stp=nxt[stp];
			stp++;
		}
		if (stp==m){
			stp=nxt[stp-1];
			printf("%d\n",i-m+1);
		}
	}
	for (int i=1;i<=m;i++) printf("%d ",nxt[i]);
	return 0;
}
