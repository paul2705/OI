#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+6;
int nxt[MAXN];
char a[MAXN],b[MAXN];
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
	int tmp=0;
	for (int i=1;i<=n;i++){
		if (b[tmp+1]==a[i]) tmp++;
		else {
			while (tmp>=0&&b[tmp+1]!=a[i]) tmp=nxt[tmp];
			tmp++;
		}
		if (tmp==m){
			printf("%d\n",i-m+1);
			tmp=nxt[tmp];
		}
	}
	for (int i=1;i<=m;i++) printf("%d ",nxt[i]);
	cout<<endl;
	return 0;
}
