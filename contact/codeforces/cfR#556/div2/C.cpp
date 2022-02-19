#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=4e5+5;
int n,cnt[3];
int pri[MAXN];
bool use[MAXN];
int sum=0;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x; scanf("%d",&x);
		cnt[x]++;
		sum+=x;
	}
	for (int i=2;i<=sum;i++){
		if (!use[i]) pri[++pri[0]]=i;
		for (int j=1;j<=pri[0]&&i*pri[j]<=sum;j++){
			use[i*pri[j]]=1;
			if (i%pri[j]==0) break;
		}
	}
	int las=0;
//	for (int i=1;i<=pri[0];i++) cout<<pri[i]<<endl;
	for (int i=1;i<=pri[0];i++){
//		printf("(%d %d)\n",las,pri[i]);
		int del=pri[i]-las;
		if (del%2==1){
//			cout<<pri[i]<<endl;
			if (cnt[1]>0){
				printf("1 ");
				cnt[1]--;
				del--;
				for (int i=del;i>1&&cnt[2]>0;i-=2){
					printf("2 ");
					cnt[2]--;
					del-=2;
				}
				if (del==0) las=pri[i];
				else las=pri[i]-del;
			}
			else break;
		}
		else {
//			for (int i=del;i>=1&&cnt[1]>0;i--){
//				if (del%2==0&&cnt[1]==1) break;
//				printf("1 ");
//				cnt[1]--;
//				del--;
//			}
			for (int i=del;i>1&&cnt[2]>0;i-=2){
				printf("2 ");
				cnt[2]--;
				del-=2;
			}
			for (int i=del;i>=1&&cnt[1]>0;i--){
				if (del%2==0&&cnt[1]==1) break;
				printf("1 ");
				cnt[1]--;
				del--;
			}
			if (del==0) las=pri[i];
			else las=pri[i]-del;
		}
		if (cnt[1]==0&&cnt[2]==0) break;
//		cout<<" :"<<las<<endl;
	}
	for (int i=1;i<=cnt[1];i++) printf("1 ");
	for (int i=1;i<=cnt[2];i++) printf("2 ");
	return 0;
}
