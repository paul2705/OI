#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
bool f=0;
int main(){
	scanf("%d",&n);
	for (int i=1,x;i<=n;i++){
		scanf("%d",&x);
		f|=x;
	}
	if (f) printf("HARD\n");
	else printf("EASY\n");
	return 0;
}
