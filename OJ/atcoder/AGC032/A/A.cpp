#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e2+5;
int n,a[MAXN],ans[MAXN];
int main(){
	scanf("%d",&n);
	int m=n;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=n;i>=1;i--){
		int pos=-1;
		for (int j=n;j>=1;j--){
			if (a[j]==j){
				pos=j;
				break;
			}
		}
		if (pos==-1) return printf("-1\n"),0;
		ans[i]=pos;
		for (int j=pos;j<=n;j++) swap(a[j],a[j+1]);
		n--;
//		for (int j=1;j<=n;j++) printf("%d ",a[j]);
//		cout<<endl;
	}
	for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}
