#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int c[5];
struct rec{
	int val,c;
} a[MAXN*2];
int n,m,ans;
bool cmp(rec a,rec b){
	return a.val>b.val;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n-1;i++) scanf("%d",&a[i].val),a[i].c=0;
//	cout<<"done"<<endl;
	for (int i=n;i<=n+m-2;i++) scanf("%d",&a[i].val),a[i].c=1;
//	cout<<"done"<<endl;
	sort(a+1,a+n+m-1,cmp);
	for (int i=1;i<=n+m-2;i++){
		c[a[i].c]++;
		ans+=a[i].val*(c[a[i].c^1]+1);
	}
	printf("%d\n",ans);
	return 0;
}
