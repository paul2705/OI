#include<iostream>
#include<cstdio>
using namespace std;
int lis[105];
int n,ans;
int main(){
	freopen("crossroad.in","r",stdin);
	freopen("crossroad.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=10;i++) lis[i]=-1;
	for (int i=0,a,b;i<n;i++){
		scanf("%d%d",&a,&b);
//		cout<<lis[a]<<" "<<a<<" "<<b<<endl;
		if (lis[a]!=b&&lis[a]!=-1) ans++,lis[a]=b;
		if (lis[a]==-1) lis[a]=b;
	}
	printf("%d\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
