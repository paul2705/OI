#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+6;
int n,nxt[MAXN];
char a[MAXN],b[MAXN];
int la,lb;
int main(){
	scanf("%s",a);
	scanf("%s",b);
	la=strlen(a); lb=strlen(b);
	nxt[0]=-1;
	for (int i=1;i<lb;i++){
//		cout<<i<<endl;
		int pre=nxt[i-1];
		while (pre>0&&b[pre]!=b[i]) pre=nxt[pre-1];
		if (b[pre]==b[i]) nxt[i]=pre+1;
		else nxt[i]=0;
//		cout<<i<<" "<<nxt[i]<<endl;
	}
	int stp=0;
	for (int i=0;i<la&&stp<lb;){
//		cout<<i<<" "<<stp<<endl;
		if (stp==-1||a[i]==b[stp]) i++,stp++;
		else stp=nxt[stp];
		cout<<i<<" "<<stp<<endl;
		if (stp==lb){
			printf("%d\n",i-stp+1);
			stp=nxt[stp];
		}
//		cout<<i<<" ; "<<stp<<endl;
	}
	cout<<0<<" ";
	for (int i=1;i<lb;i++) printf("%d ",nxt[i]);
	return 0;
}
