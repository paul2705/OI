#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int N,A[MAXN];
int main(){
	freopen("taming.in","r",stdin);
	freopen("taming.out","w",stdout);
	cin>>N;
	for(int i=0;i<N;i++) cin>>A[i];
	if(A[0]>0) return printf("-1\n"),0;
	A[0] = 0;
	int t = -1,req = 0,pos = 0;
	for(int i=N-1;i>=0;i--){
		if(t!=-1&&A[i]!=-1&&A[i]!=t) return printf("-1\n"),0;
		if(t==-1) t=A[i];
		if(A[i]==-1) A[i]=t;
		if(A[i]==0) req++;
		if(A[i]==-1) pos++;
		if(t>-1) t--;
	}
	printf("%d %d\n",req,req+pos);
	return 0;
}
