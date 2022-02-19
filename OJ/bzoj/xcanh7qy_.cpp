#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1e5+5;
const int MAXT=1e6+6;
int t[3][MAXT],cnt[3];
int a[MAXN],n,ans;
void add(int id,int x){
	cnt[id]++; x++;
	for (;x<=1e6;x+=x&-x) t[id][x]++;
}
int sum(int id,int x){
	int ans=0; x++;
	for (;x>0;x-=x&-x) ans+=t[id][x];
	return ans;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]+=a[i-1];
	for (int i=0;i<=20;i++){
		memset(t,0,sizeof(t)); cnt[0]=cnt[1]=0;
		int res=0;
		for (int j=0;j<=n;j++){
			int pre=a[j]%(1<<i);
			if (a[j]&(1<<i)){
				res=(res+sum(0,pre)+cnt[1]-sum(1,pre))%2;
				add(1,pre);
			}
			else {
				res=(res+sum(1,pre)+cnt[0]-sum(0,pre))%2;	
				add(0,pre);
			}
		}
//		cout<<res<<endl;
		ans+=(1<<i)*res;
	}
	printf("%d\n",ans);
	return 0;
}
