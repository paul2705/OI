#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e4+5;
int a[MAXN][6];
int n,ans;
int cnt[1000005];
int main(){
	freopen("cowpatibility.in","r",stdin);
	freopen("cowpatibility1.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=5;j++) scanf("%d",&a[i][j]);
		sort(a[i]+1,a[i]+6);
	}
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			for (int k=1;k<=5;k++) cnt[a[i][k]]++;
			bool f=0;
			for (int k=1;k<=5;k++){
				if (cnt[a[j][k]]>0) f=1;
			}
			if (!f) ans++;
			for (int k=1;k<=5;k++) cnt[a[i][k]]--;
		}	
	}
	printf("%d\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
