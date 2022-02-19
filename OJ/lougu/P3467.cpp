#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
ll top,n,num,j,k,sta[250100];
int main(){
	scanf("%lld",&n);
	for (int i=1;i<=n;i++){
		scanf("%lld%lld",&j,&k);
		while (top>0&&k<=sta[top]){
			if (k==sta[top]) num++;
			top--;
		}
		sta[++top]=k;
	}
	printf("%lld\n",n-num);
	return 0;
}
