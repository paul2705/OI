#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=7e6+6;
int f[2][MAXN],permu[10],permu2[10];
int n,d[105],a[105];
void inpermu(){
	for (int j=1;j<7;j++) permu[j]=j;
}
int ptoi(int *l){
	int res=0;
	for (int i=0;i<7;i++) res=res*10+l[i];
	return res;
}
void ini(){
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&d[i]);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
}
void solve(){
	for (int i=0;i<n;i++){
		inpermu();
		int b=(i&1),b_=b^1,cnt=0,code1,code2;
		do{
			code1=ptoi(permu);
			for (int k=0;k<=7;k++){
				cnt=0;
				int con=0;
				for (int kk=0;kk<k;kk++){
					int loc=i-1-permu[kk];
					if (loc>=0&&permu[kk]+1<=d[loc]) con+=a[loc];
					if (permu[kk]<6) permu2[cnt++]=permu[kk]+1;
				}
				permu2[cnt++]=0;
				for (int kk=k;kk<7;kk++){
					int loc=i-1-permu[kk];
					if (loc>=0&&permu[kk]+1<=d[i]) con+=a[i];
					if (permu[kk]<6) permu2[cnt++]=permu[kk]+1;
				}
				code2=ptoi(permu2);
				f[b_][code2]=max(f[b_][code2],f[b][code1]+con);
			}
			f[b][code1]=0;
		} while (next_permutation(permu,permu+7));
	}
	int ans=0;
	inpermu();
	do{
		ans=max(ans,f[n&1][ptoi(permu)]);
	}while (next_permutation(permu,permu+7));
	printf("%d\n",ans);
}
int main(){
	ini(); solve();
	return 0;
}
