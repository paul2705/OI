#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3e5+5;
int a[MAXN],n,k;
bool check(int x){
	
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		char c=getchar(); while (c!='H'&&c!='G') c=getchar();
		a[i]=(c=='H');
	}
	int l=0,r=n,mid;
	while (l+1<r){
		int mid=(l+r)>>1;
		if (check(mid)) r=mid;
		else l=mid;
	}
	printf("%d\n",r);
	return 0;
}
