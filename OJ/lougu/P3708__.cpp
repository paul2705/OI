#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+6;
int n;
int main(){
	scanf("%d",&n);
	int las=0;;;;;;;;;
	for (int i=1;i<=n;i++){
		int ans=0;
		for (int j=1;j<=n;j++) ans+=i%j;
		printf("%d ",ans-las); las=ans;
	}
	cout<<endl;
	return 0;
}
