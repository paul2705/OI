#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e2+5;
int a[MAXN],cnt[MAXN*MAXN];
int n,res,ret;
bool f=0;
char ans[MAXN];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++;
	for (int i=1;i<=n;i++){
		if (cnt[a[i]]>2) f=1;
		if (cnt[a[i]]>1) ans[i]='A';
		else res++;	
	}
//	cout<<res<<endl;
	if (f==0&&res%2==1) return printf("NO\n"),0;
	for (int i=1;i<=n&&(ret<(res+1)/2);i++){
		if (cnt[a[i]]==1) ans[i]='A',ret++;		
	}
	for (int i=1;i<=n;i++){
		if (ans[i]!='A') ans[i]='B';
	}
	if (res%2==1)
		for (int i=1;i<=n;i++){
			if (cnt[a[i]]>2){ ans[i]='B'; break; }
		}
	cout<<"YES"<<endl;
	for (int i=1;i<=n;i++) cout<<ans[i];
	cout<<endl;
	return 0;
}
