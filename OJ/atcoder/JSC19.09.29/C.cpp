#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n;
ll L,tmp;
set<ll> s,ans;
int main(){
	scanf("%d%lld%lld",&n,&L,&tmp); L++; tmp++;
//	cout<<tmp<<endl;
	s.insert(0); s.insert(L+1);
	s.insert(tmp);
	for (int i=1;i<=n;i++){
		ll x; scanf("%lld",&x); x++;
		set<ll>::iterator it=s.lower_bound(x);
		int cnt[5]={0,0,x,0,0};
//		cout<<*s.begin()<<" "<<it<<" "<<s.end()<<endl;
//		cout<<(*it)<<" "<<x<<endl;
		if ((*it)!=x){
			if ((*it)>x) it--;
			if (it!=s.begin()){
				cnt[1]=(*it);
				it--;
			}
			if (it!=s.begin()) cnt[0]=(*it);
			while ((*it)<x) it++;
			if (it!=s.end()){
				cnt[3]=(*it)==L+1?0:(*it);
				it++;
			}
			if (it!=s.end()) cnt[4]=(*it)==L+1?0:(*it);
			cout<<"add: "<<endl;
			for (int i=0;i<5;i++) cout<<cnt[i]<<" ";
			cout<<endl;
			if (cnt[0]&&cnt[3]) ans.erase(cnt[3]-cnt[0]);
			if (cnt[1]&&cnt[4]) ans.erase(cnt[4]-cnt[1]);
			if (cnt[0]) ans.insert(cnt[2]-cnt[0]);
			if (cnt[4]) ans.insert(cnt[4]-cnt[2]);
			if (cnt[1]&&cnt[3]) ans.insert(cnt[3]-cnt[1]);
			if (!cnt[3]&&cnt[1]) ans.insert(L-cnt[2]-cnt[1]);
			s.insert(x);
		}
		else {
			if (it!=s.begin()){
				it--;
				cnt[1]=(*it);
			}
			if (it!=s.begin()){
				it--;
				cnt[0]=(*it);
			}
			while ((*it)<=x) it++;
			if (it!=s.end()){
				cnt[3]=(*it)==L+1?0:(*it);
				it++;
			}
			if (it!=s.end()) cnt[4]=(*it)==L+1?0:(*it);
			cout<<"delete: "<<endl;
			for (int i=0;i<5;i++) cout<<cnt[i]<<" ";
			cout<<endl;
			if (cnt[0]) ans.erase(cnt[2]-cnt[0]);
			if (cnt[4]) ans.erase(cnt[4]-cnt[2]);
			if (cnt[1]&&cnt[3]) ans.erase(cnt[3]-cnt[1]);
			if (!cnt[3]&&cnt[1]) ans.erase(L-cnt[2]-cnt[1]);
			if (cnt[0]&&cnt[3]) ans.insert(cnt[3]-cnt[0]);
			if (cnt[1]&&cnt[4]) ans.insert(cnt[4]-cnt[1]);
			s.erase(x);
		}
		it=ans.begin();
		printf("%lld\n",(*it));
	}
	return 0;
}
