#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll cnt;
int a[15];
int n;
void dfs(int res,int id,int fg){
	if (id==11&&res==0){
		cnt++;
//		cout<<"in: "<<fg<<endl;
		if (fg){
			for (int i=1;i<=10;i++) printf("%d ",a[i]);
			printf("\n");
		}
		return;
	}
	else if (id==11) return;
//	cout<<__func__<<" "<<res<<" "<<id<<" "<<fg<<endl;
	for (int i=1;i<=min(res,3);i++){
		a[id]=i;
		dfs(res-i,id+1,fg);
	}
}
int main(){
	scanf("%d",&n);
	if (n>30) return printf("0\n"),0;
//	cout<<n<<endl;
	dfs(n,1,0);
	printf("%lld\n",cnt);
//	cout<<n<<endl;
	dfs(n,1,1);
	return 0;
}
