#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int a[MAXN];
int n,cnt,ans=0;
struct rec{
	int l,r;
} pre,now;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		char c=getchar(); while (c!='G'&&c!='S') c=getchar();
		a[i]=c=='G'; cnt+=a[i];
	}
//	cout<<cnt<<endl;
	for (int i=1;i<=n;i++){
		if (a[i]==1){
			pre.l=i;
			for (pre.r=i;pre.r<=n;pre.r++){
				if (a[pre.r]==0) break;
			}
			pre.r--;
			break;
		}
	}
//	cout<<pre.l<<" "<<pre.r<<endl;
	if (pre.r==0){
		printf("0\n");
		return 0;
	}
	ans=pre.r-pre.l+1;
	for (int i=pre.r+1;i<=n;i++){
		if (a[i]==1){
			now.l=i;
			for (now.r=i;now.r<=n;now.r++){
				if (a[now.r]==0) break;
			}
			now.r--;
//			cout<<pre.l<<" "<<pre.r<<" "<<now.l<<" "<<now.r<<endl;
			if (pre.r+2==now.l){
				if (cnt>pre.r-pre.l+1+now.r-now.l+1){
					ans=max(ans,now.r-pre.l+1);
				}
				else if (cnt==pre.r-pre.l+1+now.r-now.l+1){
					ans=max(ans,now.r-pre.l);
				}
			}
			ans=max(ans,now.r-now.l+1);
			pre=now;
			i=now.r;
		}
	}
	printf("%d\n",ans);
	return 0;
}
