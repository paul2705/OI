#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=505;
int n,m,ans,a[MAXN],b[MAXN];
char tp[MAXN];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		char c=getchar(); 
		while (c!='-'&&c!='+') c=getchar();
		tp[i]=c;
		while (c<'0'||c>'9') c=getchar();
		int h=0,m=0;
		h=c-'0';
		while (c>='0'&&c<='9') h=h*10+c-'0',c=getchar();
		c=getchar();
		while (c>='0'&&c<='9') m=m*10+c-'0',c=getchar();
		a[i]=h,b[i]=m;
//		cout<<tp[i]<<" "<<h<<" "<<m<<endl;
	}
	int mx=0;
	for (int i=1;i<=n;i++){
		if (tp[i]=='+') ans++;
		else ans--;
		mx=max(mx,ans);
	}
	printf("%d\n",mx);
	return 0;
}
