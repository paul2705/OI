#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
int a[MAXN],cnt[MAXN];
int n,q;
int main(){
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	if (a[1]==0){
		int pos=0;
		for (int i=1;i<=n;i++){
			if (a[i]!=0) pos=i;
		}
//		cout<<pos<<" "<<a[pos]<<endl;
		if (pos==0) a[n+1]=a[0]=1;
		else a[0]=a[pos];
	}
	if (a[n]==0){
		int pos=0;
		for (int i=n;i>=1;i--){
			if (a[i]!=0) pos=i;
		}
		if (pos==0) a[n+1]=a[0]=1;
		else a[n+1]=a[pos];
	}
	for (int i=1;i<=n;i++){
		if (a[i]==0) continue;
		if (a[i]!=a[i-1]&&cnt[a[i]]!=0) return printf("NO\n"),0;
		else{
			if (a[i]!=a[i-1]) cnt[a[i]]=i;
		}
	}
	printf("YES\n");
	int res=a[0];
//	cout<<a[0]<<endl;
	for (int i=1;i<=n;i++){
		if (a[i]==0) a[i]=res;
		else res=a[i];
//		cout<<res<<" "<<a[i]<<endl;
	}
	if (a[0]==1&&a[n+1]==1) for (int i=n;i>=1;i--) printf("%d ",q--);
	else for (int i=1;i<=n;i++) printf("%d ",a[i]);
    printf("\n");
	return 0;
}
