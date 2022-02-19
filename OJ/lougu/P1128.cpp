#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=25;
const int MAXM=505;
double f[MAXN][MAXM];
int n,ans[100005];
int pre[MAXN][MAXM];
int d[MAXM],cnt;
int pri[MAXM]=
{20,2,3,5,7,11,13,17,19,23,29,
31,37,41,43,47,53,59,61,67,71};
void mul(int x){
	int tmp=0;
	for (int i=1;i<=ans[0];i++){
		ans[i]=ans[i]*x+tmp;
		tmp=ans[i]/10;
		ans[i]%=10;
	}
	while (tmp>0){
		ans[0]++;
		ans[ans[0]]=tmp%10;
		tmp/=10;
	}
}
void prt(){
//	cout<<ans[0]<<endl;
	for (int i=ans[0];i>=1;i--) printf("%d",ans[i]);
	printf("\n");
}
int main(){
	scanf("%d",&n);
	ans[0]=ans[1]=1;
	for (int i=0;i<=pri[0];i++){
		for (int j=0;j<505;j++) f[i][j]=1e9;
	}
	for (int i=1;i<=n;i++){
		if (n%i==0) d[cnt++]=i;
	}
//	cout<<cnt<<endl;
	f[0][0]=0;
	for (int i=1;i<=pri[0];i++){
		for (int j=1;j<cnt;j++){
			for (int k=0;k<j;k++){
				if (d[j]%d[k]!=0) continue;
				int t=d[j]/d[k];
				double tmp=log(pri[i]);
				if (f[i][j]>f[i-1][k]+tmp*(t-1)){
					pre[i][j]=k;
					f[i][j]=f[i-1][k]+tmp*(t-1);
				}
			}
//			cout<<f[i][j]<<" "<<pre[i][j]<<" ";
		}
//		cout<<endl;
	}
//	cout<<log(2)<<" "<<log(3)<<endl;
//	cout<<"done"<<endl;
	int pos=-1,mn=1e9;
	for (int i=1;i<=pri[0];i++){
		if (pos==-1||f[i][cnt-1]<mn){
			pos=i;
			mn=f[i][cnt-1];
		}
	}
//	cout<<"fuck "<<mn<<" "<<pos<<endl;
	for (int i=pos,x=cnt-1;i>0;i--){
		int cnt=d[x]/d[pre[i][x]];
//		cout<<pri[i]<<" "<<cnt<<endl;
		for (int j=1;j<cnt;j++) mul(pri[i]);
		x=pre[i][x];
	}
	prt();
	return 0;
}
