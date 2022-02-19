#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=23;
struct rec{
	int tp,val;
} a[MAXN];
int n,T,cnt[20],ans=1e9;
int cnt1[20];
void dfs(int d){
	if (d+1>ans) return;
	bool fl=1;
	for (int i=0;i<=13;i++){
		if (cnt[i]>1) fl=0;
	}
	if (fl){
		int ret=d-1;
//		cout<<ans<<" "<<ret<<endl;
		for (int i=0;i<=13;i++) cnt1[i]=cnt[i];
		for (int i=3;i<=9;i++){
			int res=0;
			for (int j=i;j<=13;j++){
				if (cnt[j]<1) break;
				res++;
			}
			if (res>=5){
				ret++;
				for (int j=i;j<i+res;j++) cnt[j]--;
			}
		}
		for (int i=0;i<=13;i++){
			if (cnt[i]>0) ret+=cnt[i],cnt[i]=0;
		}
		ans=min(ans,ret);
		for (int i=0;i<=13;i++) cnt[i]=cnt1[i];
		return;
	}
	if (cnt[0]>1){
		cnt[0]-=2;
		dfs(d+1);
		cnt[0]+=2;
	}
	for (int i=0;i<=13;i++){
		if (cnt[i]>3){
			cnt[i]-=4;
			for (int j=0;j<=13;j++){
				if (j==i) continue;
				for (int k=0;k<=13;k++){
					if (k==i) continue;
					if (cnt[j]>0&&cnt[k]>0){
						cnt[j]--; cnt[k]--;
						dfs(d+1);
						cnt[j]++; cnt[k]++;
					}
					if (cnt[j]>1&&cnt[k]>1){
						cnt[j]-=2; cnt[k]-=2;
						dfs(d+1);
						cnt[j]+=2; cnt[k]+=2;
					}
				}
			}
			dfs(d+1);
			cnt[i]+=4;
		}
	}
	for (int i=3;i<=9;i++){
		int res=0;
		for (int j=i;j<=13;j++){
			if (cnt[j]<1) break;
			res++;
		}
		if (res>=5){
			for (int j=i;j<i+res;j++) cnt[j]--;
			dfs(d+1);
			for (int j=i;j<i+res;j++) cnt[j]++;
		}
	}
	for (int i=3;i<=11;i++){
		int res=0;
		for (int j=i;j<=13;j++){
			if (cnt[j]<2) break;
			res++;
		}
		if (res>=3){
			for (int j=i;j<i+res;j++) cnt[j]-=2;
			dfs(d+1);
			for (int j=i;j<i+res;j++) cnt[j]+=2;
		}
	}
	for (int i=3;i<=12;i++){
		int res=0;
		for (int j=i;j<=13;j++){
			if (cnt[j]<3) break;
			res++;
		}
		if (res>=2){
			for (int j=i;j<i+res;j++) cnt[j]-=3;
			dfs(d+1);
			for (int j=i;j<i+res;j++) cnt[j]+=3;
		}
	}
	for (int i=0;i<=13;i++){
		if (cnt[i]>2){
			for (int j=0;j<=13;j++){
				if (i==j) continue;
				if (cnt[j]>0){
					cnt[j]--; 
					cnt[i]-=3;
					dfs(d+1);
					cnt[j]++;
					if (cnt[j]>1){
						cnt[j]-=2;
						dfs(d+1);
						cnt[j]+=2;
					}
					cnt[i]+=3;
				}
			}
			cnt[i]-=3;
			dfs(d+1);
			cnt[i]+=3;
		}
	}
	for (int i=0;i<=13;i++){
		if (cnt[i]>1){
			cnt[i]-=2;
			dfs(d+1);
			cnt[i]+=2;
		}
	}
}
int main(){
	scanf("%d%d",&T,&n);
	while (T--){
		bool fl=0;
		for (int i=1;i<=n;i++) scanf("%d%d",&a[i].val,&a[i].tp);
		for (int i=0;i<=15;i++) cnt[i]=0;
		for (int i=1;i<=n;i++) cnt[a[i].val]++;
//		for (int i=0;i<=13;i++) cout<<cnt[i]<<" ";cout<<endl;
		ans=1e9;
//		if (cnt[0]==2) fl=1,cnt[0]=0;
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}
