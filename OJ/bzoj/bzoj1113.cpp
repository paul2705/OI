#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e5+5;
int n,cnt;
int st[MAXN],top;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int tmp,x; scanf("%d%d",&tmp,&x);
		while (top&&st[top-1]>=x){
			if (st[top-1]==x) cnt++;
			top--;
		}
		st[top++]=x;
	}
	printf("%d\n",n-cnt);
	return 0;
}
