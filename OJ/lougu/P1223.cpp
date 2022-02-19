#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
struct rec{
	int id,T;
} a[MAXN];
int n;
double ans,sum;
bool cmp(rec a,rec b){ return a.T<b.T; }
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i].T),a[i].id=i;
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++){
		printf("%d ",a[i].id);
		ans+=sum;
		sum+=a[i].T;
	}
	ans/=n;
	printf("\n%.2lf\n",ans);
	return 0;
}
