#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=1e7+7;
int f[MAXN],pri[MAXN],t[MAXN];
int T;
vector<int> a;
bool check(int x){
	while (x){
		if (x%10==7) return 1;
		x/=10;
	}
	return 0;
}
int main(){
//	freopen("P7960.in","r",stdin);
//	freopen("P7960.out","w",stdout);
	for (int i=1;i<=1e7+5;i++) f[i]=t[i]=0;
	for (int i=2;i<=1e7+5;i++){
		if (t[i]==0) pri[++pri[0]]=i;
		for (int j=1;j<=pri[0]&&i*pri[j]<=1e7+5;j++){
			t[i*pri[j]]=1;
			if (i%pri[j]==0) break;
		}
	}
	a.push_back(1);
	for (int i=2;i<=1e7+5;i++){
		if (check(i)) f[i]=1;
		if (f[i]==0) a.push_back(i);
		else {
			for (int j=1;j<=pri[0]&&i*pri[j]<=1e7+5;j++){
//				printf("cut: %d\n",i*pri[j]);
				f[i*pri[j]]=1;
//				if (i%pri[j]==0) break;
			}
		}
	}
//	for (int i=0;i<a.size();i++) printf("%d\n",a[i]);
	scanf("%d",&T);
	while (T--){
		int x; scanf("%d",&x);
		int l=0,r=a.size(),mid;
//		printf("%d",x);
		while (l+1<r){
			mid=(l+r)>>1;
			if (a[mid]<=x) l=mid;
			else r=mid;
		}
//		printf("%d %d\n",a[l],a[r]);
		if (a[l]!=x) printf("-1\n");
		else printf("%d\n",a[r]);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
