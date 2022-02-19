#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3e5+5;
int a[MAXN],n,m,t[MAXN];
bool check(int x){
	for (int i=1;i<=n;i++){
		t[i]=a[i];
		if (t[i]>=t[i-1]){
			if (t[i]+x>=m) if ((t[i]+x)%m>=t[i-1]) t[i]=t[i-1];
		}
		else if (t[i]+x>=t[i-1]) t[i]=t[i-1];
		else return 0;
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int l=0,r=m,mid;
	while (l<r){
		mid=(l+r)>>1;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}
