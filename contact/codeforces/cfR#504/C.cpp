#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
int st[MAXN],top;
char a[MAXN];
int n,k,cnt[MAXN],res=0;
int main(){
	scanf("%d%d",&n,&k);
	cin>>a;
	for (int i=0;i<n;i++){
		if (a[i]=='(') st[++top]=1;
		else{
			top--,st[top]++;
		} 
	}
	for (int i=1;i<=10;i++) cout<<st[i]<<endl;
	cout<<top<<endl;
	int ret=0,am=(n-k)/2;
	for (int i=1;i<=top;i++){
		cout<<st[i]<<endl;
		if (st[i]>1){
			ret+=st[i]-max(1,st[i]-am);
			for (int j=1;j<=max(1,st[i]-am);j++) printf("(");
			for (int j=1;j<=max(1,st[i]-am);j++) printf(")");
		}
		printf("()");
	}
	return 0;
}
