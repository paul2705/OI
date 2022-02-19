#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=5e4+5;
int n;
int main(){
	scanf("%d",&n);
	if (n<=2) return printf("No\n"),0;
	cout<<"Yes"<<endl;
	int cnt1=0,cnt2=0;
	for (int i=1;i<=n;i++) if (i%2==1) cnt1++; else cnt2++;
	printf("%d ",cnt1);
	for (int i=1;i<=n;i++) if (i%2==1) printf("%d ",i);
	printf("\n%d ",cnt2);
	for (int i=1;i<=n;i++) if (i%2==0) printf("%d ",i);
	cout<<endl;
	return 0;
}
