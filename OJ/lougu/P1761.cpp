#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=55;
int a[MAXN],l[MAXN],r[MAXN];
int n,ans;
int main(){
	scanf("%d",&n);
	while (n!=0){
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		l[1]=0,r[1]=2*a[1];
		for (int i=2;i<=n;i++){
			int j=i-1;
			for (;j>=1;j--) if (a[j]*2>=a[i]||a[j]*2>=a[j-1]) break;
			if (a[i]>a[j]) l[i]=r[j]-(a[i]-a[j]);
			else l[i]=(l[j]+r[j])/2+a[i];
			r[i]=l[i]+2*a[i];
		}
		for (int i=1;i<=n;i++){
			bool f=true;
			for (int j=1;j<i;j++){
				for (int k=i+1;k<=n;k++){
					if (r[j]>=l[k]) f=false;
				}
			}
			if (f) printf("%d ",i);
		}
		printf("\n");
		scanf("%d",&n);
	}
	return 0;
}
