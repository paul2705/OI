#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
char s[MAXN][100];
int a[MAXN];
int n,m,pos=0;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf("%d %s",&a[i],s[i]);
	for (int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		int dir=(a[pos]==1?1:-1)*(x==0?1:-1);
		pos=((pos+dir*y)%n+n)%n;
//		cout<<s[pos]<<endl;
	}
	printf("%s\n",s[pos]);
	return 0;
}
