#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e4+5;
int f[MAXN+1],dis[MAXN+1],n;
int pri[MAXN+1];
bool use[MAXN+1];
int main(){
	scanf("%d",&n);
	for (int i=2;i<=MAXN;i++){
		if (!use[i]) pri[++pri[0]]=i;
		for (int j=1;j<=pri[0];j++){
			if (i*pri[j]>(int)2e4) break;
			use[i*pri[j]]=1;
			if (i%pri[j]==0) break;
		}
	}
	f[2]=f[3]=dis[2]=dis[3]=1;
	f[0]=f[1]=-1; dis[0]=dis[1]=0;
//	cout<<"ftk?!"<<endl;
	for (int i=4;i<=MAXN;i++){
//		cout<<"fuck::"<<i<<" ";
		for (int j=1;j<=pri[0];j++){
			if (pri[j]>i) break;
			if (f[i-pri[j]]==-1){
				if (f[i]==0||f[i]==-1){
					f[i]=1;
					dis[i]=dis[i-pri[j]]+1;
				}
				else dis[i]=min(dis[i],dis[i-pri[j]]+1);
			}
			else {
				if (f[i]==0){
					f[i]=-1;
					dis[i]=dis[i-pri[j]]+1;
				}
				else if (f[i]==-1) 
					dis[i]=max(dis[i],dis[i-pri[j]]+1);
			}
		}
	}
//	cout<<endl;
	for (int i=1,x;i<=n;i++){
		scanf("%d",&x);
		if (f[x]==-1) printf("%d\n",f[x]);
		else printf("%d\n",dis[x]);
	}
	return 0;
}
