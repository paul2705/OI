#include<iostream>
#include<cstdio>
using namespace std;
int n,m,k;
int a[150],loc[150],lis[150];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++) scanf("%d",&a[i]);
	for (int i=1,x;i<=k;i++){
		scanf("%d",&x); scanf("%d",&loc[x]);
		lis[loc[x]]=x;
	}
	int r=m;
	for (int i=n;i>0;i--){
//		printf("%d %d %d\n",i,a[r],loc[a[r]]);
		if (loc[a[r]]==0&&r>0) lis[i]=a[r--];
		else if (loc[a[r]]<i) i=loc[a[r--]];
	}
//	for (int i=1;i<=n;i++) cout<<lis[i]<<" ";
//	cout<<endl;
	for (int i=1;i<=n;i++)
		if (lis[i]==0) return printf("%d\n",i),0;
	return 0;
}
