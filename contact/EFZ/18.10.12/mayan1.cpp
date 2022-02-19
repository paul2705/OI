#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3e6+6;
int n,m,ans;
char a[MAXN],b[MAXN];
int cnt[MAXN],use[MAXN];
int main(){
	freopen("mayan.in","r",stdin);
	freopen("mayan1.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>a>>b;
	for (int i=0;i<n;i++) use[a[i]]++;
	for (int i=0;i<n;i++) cnt[b[i]]++;
	bool f=1;
	for (int i=0;i<n;i++) if (cnt[a[i]]!=use[a[i]]) f=0;
	if (f) ans++;
	for (int i=n;i<m;i++){
		cnt[b[i]]++; cnt[b[i-n]]--;
		f=1;
		for (int i=0;i<n;i++){
			if (cnt[a[i]]!=use[a[i]]) f=0;
		}
		if (f) ans++;
	}
	printf("%d\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
