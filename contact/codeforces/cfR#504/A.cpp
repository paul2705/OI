#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
int n,m;
char a[MAXN],b[MAXN];
bool f1=1,f2=1;
int main(){
	scanf("%d%d",&n,&m);
	cin>>a>>b;
	int pos=-1;
	for (int i=0;i<n;i++){
		if (a[i]=='*'){ pos=i; break; }
	}
	if (pos==-1){
		if (n!=m) return printf("NO\n"),0;
		bool f=1;
		for (int i=0;i<n;i++){
			if (a[i]!=b[i]) f=0;
		}
		if (f) return printf("YES\n"),0;
		else return printf("NO\n"),0;
	}
	for (int i=0;i<pos;i++){
		if (a[i]!=b[i]) f1=0;
	}
	int r=n-1,rr=m-1;
	for (;r>pos;r--,rr--){
//		cout<<a[r]<<" "<<b[rr]<<endl;
		if (a[r]!=b[rr]) f2=0;
	} r++,rr++;
//	cout<<pos<<" "<<r<<" "<<rr<<" "<<f1<<" "<<f2<<endl;
	if (f1&&f2&&rr>=pos) printf("YES\n");
	else printf("NO\n");
	return 0;
}
