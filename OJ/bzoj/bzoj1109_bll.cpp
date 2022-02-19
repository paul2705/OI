#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=25;
int n,a[MAXN];
int ans=0;
int main(){
	freopen("bzoj1109.in","r",stdin);
	freopen("bzoj1109_bll.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int s=0;s<(1<<n);s++){
		int cnt=0,pos=1;
		for (int j=0;j<n;j++){
			if (s&(1<<j)){
				if (a[j+1]==pos) cnt++;
				pos++;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
	fclose(stdin); fclose(stdout);
	return 0;
}
