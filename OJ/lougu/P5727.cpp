#include<iostream>
#include<cstdio>
using namespace std;
int n,cnt=0;
int a[505];
int main(){
	scanf("%d",&n);
	a[++cnt]=n;
	while (n!=1){
		if (n%2==0) n/=2;
		else n=3*n+1;
		a[++cnt]=n;
	}
	for (int i=cnt;i>=1;i--) printf("%d ",a[i]);
	cout<<endl;
	return 0;
}
