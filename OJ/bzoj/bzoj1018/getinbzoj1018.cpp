#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include"sys/time.h"
using namespace std;
int n;
const int mod=1e3;
vector<pair<int,int> > use;
int main(){
	freopen("bzoj1018.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	n=rand()%mod+1;
	cout<<n<<endl;
	int m=rand()%mod+1;
	for (int i=1;i<=m;i++){
		int x=rand()%2+1,y=rand()%n+1,nx,ny;
		int cn=rand()%4+1,op=rand()%3+1;
		if (cn==1) nx=x-1,ny=y;
		if (cn==2) nx=x,ny=y+1;
		if (cn==3) nx=x+1,ny=y;
		if (cn==4) nx=x,ny=y-1;
		if (nx<1||nx>2||ny<1||ny>n) nx=x,ny=y;
		if (op==1) cout<<"O "<<nx<<" "<<ny<<" "<<x<<" "<<y<<endl;
		if (op==2) cout<<"C "<<nx<<" "<<ny<<" "<<x<<" "<<y<<endl;
		if (op==3){
			int sz=use.size();
			if (sz==0) continue;
			int ord=rand()%sz,l=rand()%sz;
			cout<<"A "<<use[ord].first<<" "<<use[ord].second<<" ";
			cout<<use[l].first<<" "<<use[l].second<<endl;
			continue;
		}
		use.push_back(make_pair(x,y));
		use.push_back(make_pair(nx,ny));
	}
	cout<<"E"<<endl;
	fclose(stdout);
	return 0;
}
