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
	scanf("%s",a); scanf("%s",b);
	la=strlen(a); lb=strlen(b);
	nxt[0]=-1;
	int j=0,k=-1;
	while (j<lb){
//		cout<<j<<" "<<k<<endl;
		if (k==-1||b[j]==b[k]) nxt[++j]=++k;
		else k=nxt[k];
	}
	int i=0;j=0;
	while (i<la&&j<lb){
		if (j==-1||a[i]==b[j]) i++,j++;
		else j=nxt[j];
		if (j==lb){
			printf("%d\n",i-j+1);
			j=nxt[j];
		}
	}
	for (int i=1;i<=lb;i++) cout<<nxt[i]<<" ";
	cout<<endl;
	return 0;
}
