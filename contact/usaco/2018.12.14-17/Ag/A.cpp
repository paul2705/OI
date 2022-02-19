#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int a[MAXN],n,m,c;
bool check(int x){
	int l=1,cnt=0;
//	cout<<__func__<<" "<<x<<endl;
	a[n+1]=a[n]+x+1;
	for (int r=1;r<=n;r++){
//		cout<<l<<" "<<r<<" "<<cnt<<endl;
		if (a[r+1]-a[l]>x||r-l+2>c) cnt++,l=r+1;
	}
//	cout<<l<<" "<<cnt<<endl;
	return cnt<=m;
}
int main(){
	freopen("convention.in","r",stdin);
	freopen("convention.out","w",stdout);
	scanf("%d%d%d",&n,&m,&c);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int l=0,r=1e9+1,mid;
	while (r-l>1){
		mid=(l+r)>>1;
		if (check(mid)) r=mid;
		else l=mid;
	}
	printf("%d\n",r);
	fclose(stdin);fclose(stdout);
	return 0;
}
