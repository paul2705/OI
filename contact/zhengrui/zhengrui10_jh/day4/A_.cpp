#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;
const int MAXN=1e5+5;
typedef long long ll;
ll ans;
int n;
int cnt[MAXN],res[5005][5005];
bitset<15> t;
int main(){
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<=5000;i++){
		for (int j=0;j<=i;j++){
			t=i^j;
			if (t.count()%2==1)  res[j][i]=1;
		}
	}
	for (int i=1;i<=n;i++){
		int l,r; scanf("%d%d",&l,&r);
		for (int k=l;k<=r;k++){
			if (cnt[k]) continue;
			cnt[k]=1;
			for (int x=0;x<=k;x++){
				if (cnt[x]) ans+=res[x][k];
			}
			for (int x=k+1;x<=5000;x++){
				if (cnt[x]) ans+=res[k][x];
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
