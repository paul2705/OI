#pragma GCC optimise(3)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
typedef long long ll;
const int MAXN=5e4+5;
const int MAXM=MAXN*50;
const int mod=998244353;
const int mod1=1e9+7;
string s;
struct rec{
	int sz,cnt;
} has[MAXM];
int a[MAXN][10],n;
int ans,cnth;
//int ha[5000005];
map<ll,int> use,use1;
int main(){
	freopen("cowpatibility.in","r",stdin);
	freopen("cowpatibility.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=5;j++) scanf("%d",&a[i][j]);
		sort(a[i]+1,a[i]+6);
//		for (int j=1;j<=5;j++) printf("%d ",a[i][j]);
//		cout<<endl;
		for (int s=1;s<(1<<5);s++){
			ll key1=0,key2=0;
			int sz=0;
//			string ss;
			for (int j=0;j<5;j++){
				if (s&(1<<j)){
					key1=(key1*mod+a[i][j+1]);
					key2=(key2*mod1+a[i][j+1]);
					sz++;
				}
			}
//			int x=use[key1];
			int y=use1[key2];
			if (y>0) has[y].cnt++;
			else{
				cnth++;
				use[key1]=cnth; 
//				use1[key2]=cnth;
				has[cnth]=(rec){sz,1};
			}
		}
	}
	ans=n*(n-1)/2;
	for (int j=1;j<=cnth;j++){
//		if (has[j].sz==i) cout<<i<<" "<<(i%2==0?1:-1)*has[j].cnt*(has[j].cnt-1)/2<<endl;
		ans+=((has[j].sz%2==0)?1:-1)*has[j].cnt*(has[j].cnt-1)/2;
	}
	printf("%d\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
