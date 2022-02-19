#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=60;
bool flag;
int a[MAXN],b[MAXN],c[MAXN],n,sz,f[MAXN];
void find(int x){
	
int main(){
	while (~scanf("%d",&n)){
		sz=n*(n-1)/2;
		for (int i=1;i<=sz;i++) scanf("%d",&a[i]);
		sort(a+1,a+sz+1);
		for (int i=0;i<=a[1]/2;i++){
			flag=0;
			find(i);
			if (flag) break;
		}
	}
	return 0;
}
