#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
int s,p,n,k;
map<int,int> vis;
int main(){
	scanf("%d%d%d%d",&s,&p,&n,&k);
	int len=0;
	while (1){
		s=(ll)s*s%p;
//		s%=n;
//		cout<<s<<endl;
		if (vis[s]>0) return printf("len: %d\n",len),0;
		vis[s]=1; len++;
	}
	return 0;
}
