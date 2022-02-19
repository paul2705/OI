#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+6;
int a[MAXN],b[MAXN],n,ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		char c=getchar(); while (c!='0'&&c!='1') c=getchar();
		a[i]=c-'0';
	}
	for (int i=1;i<=n;i++){
		char c=getchar(); while (c!='0'&&c!='1') c=getchar();
		b[i]=c-'0';
	}
	for (int i=1;i<n;i++){
		if (a[i]!=b[i]&&a[i+1]!=b[i+1]&&a[i]!=a[i+1]){
			ans++;
			swap(a[i],a[i+1]);
		}
	}
	for (int i=1;i<=n;i++){
		if (a[i]!=b[i]) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
