#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
vector<long long>vec[31],val[61];
int n;
long long k;
void clear(vector<long long>& Vec){
	vector<long long>tmp;
	swap(tmp,Vec);
	return ;
}
bool check(long long x){
	long long sum=0;
	for(int i=0;i<=60;i++)
		val[i].clear();
	for(int i=0;i<=30;i++)
		for(int j=0;j<vec[i].size();j++)
			val[i].push_back(vec[i][j]);
	for(int i=0;i<=60;i++){
		sort(val[i].begin(),val[i].end());
		if((x&1)&&val[i].size()>0)
			sum+=val[i][val[i].size()-1];
		if(i<60){
			if(x&1){
				for(int j=(int)val[i].size()-2;j>=0;j-=2){
					long long t=val[i][j];
					if(j>0)t+=val[i][j-1];
					val[i+1].push_back(t);
				}
			}
			else{
				for(int j=(int)val[i].size()-1;j>=0;j-=2){
					long long t=val[i][j];
					if(j>0)t+=val[i][j-1];
					val[i+1].push_back(t);
				}
			}
		}
		x>>=1;
	}
	return sum>=k;
}
int main(){
	scanf("%d %lld",&n,&k);
	for(int i=1;i<=n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		vec[a].push_back((long long)b);
	}
	long long l=-1,r=1e16;
	while(l+1<r){
		long long mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid;
	}
	printf("%lld\n",r);
	return 0;
}
