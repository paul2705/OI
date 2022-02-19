#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=4e6+5;
int a[MAXN*2],n,ans=-1;
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence1.out","w",stdout);
	scanf("%d",&n);
//	cout<<n<<endl;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) a[i+n]=a[i];
	for (int i=1;i<=n;i++){
		int l=i,r=i+n-1;
		int sum=a[l]+a[r];
		bool f=1;
		for (;l<r;l++,r--){
			if (a[l]+a[r]!=sum){
				f=0;
				break;
			}
		}
		if (f){
			ans=i-1;
			break;
		}
	}
	if (ans==-1) printf("IMPOSSIBLE\n");
	else printf("%d\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
