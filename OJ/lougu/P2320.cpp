#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int m,s=1,a[100005];
int main(){
	scanf("%d",&m);
	while (m){
		m%2==0? a[s]=m/2 : a[s]=m/2+1;
		m/=2; s++;
	}
	s--;
	sort(a+1,a+s+1);
	printf("%d\n",s);
	for (int i=1;i<=s;i++) printf("%d ",a[i]);
	return 0;
}
