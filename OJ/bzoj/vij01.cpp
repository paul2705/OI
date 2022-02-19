#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=4e3+5;
int a[MAXN],n;
int ans,cnt,las;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++){
		for (int j=las;j<i;j++){
			if (a[i]==a[j]){
				cnt++,a[i]=a[j]=-1;
				break;
			}
		}
		if (cnt==2) ans++,cnt=0,las=i;
	}
	printf("%d\n",ans);
	return 0;
}
