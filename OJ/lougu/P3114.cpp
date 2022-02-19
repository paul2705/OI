#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
const int MAXN=5e4+5;
vector<pair<int,int> > a;
int n,ans;
set<int> s,act;
int main(){
	scanf("%d",&n);
	for (int i=1,x,y,r;i<=n;i++){
		scanf("%d%d%d",&x,&y,&r);
		x*=-r;
		a.push_back(make_pair(x-r,y));
		a.push_back(make_pair(x,-y));
	}
	sort(a.begin(),a.end());
	for (int i=0;i<a.size();i++){
		int j=i;
		for (int j=i;j<a.size()&&a[i].first==a[j].first;j++){
			int y=a[j].second;
			if (y>0) act.insert(y);
			else act.erase(-y);
		}
		if (!act.empty()) s.insert(*act.begin());
		i=j;
	}
	printf("%d\n",(int)s.size());
	return 0;
}
