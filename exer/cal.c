#include<stdio.h>
#include<stdlib.h>
void dfs(int a[10005],int d,int n){
	if (n==0){
		for (int i=1;i<=d-1;i++) printf("%d ",a[i]);
		printf("\n");
		return;
	}
	for (int i=1;i<=n;i++){
		a[d]=i;
		dfs(a,d+1,n-i);
	}
}
int main(){
	int a[10005],n=0;
	scanf("%d",&n);
	dfs(a,1,n);
	return 0;
}
