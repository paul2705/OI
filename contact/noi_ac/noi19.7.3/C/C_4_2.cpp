#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=66;
int a[MAXN];
int n;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) printf("%d ",a[i]);
	cout<<endl;
	for (int i=0;i<=59;i++){
		bool flag=0;
		for (int j=1;j<=n;j++){
			if (a[j]==i) flag=1;
		}
		if (flag) printf("1\n");
		else printf("0\n");
	}
	return 0;
}
