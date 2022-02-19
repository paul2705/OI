#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,k,a[MAXN];
char s[MAXN];
ll ans;
struct rec{
	int x,id;
	bool operator < (const rec& b) const {
		return x<b.x;
	}
	bool operator > (const rec& b) const {
		return x>b.x;
	}
};
priority_queue<rec> q;
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++){
		char c=getchar(); while (c<'a'||c>'z') c=getchar();
		s[i]=c;
	}
	q.push((rec){a[1],1});
	for (int i=2;i<=n+1;i++){
		if (s[i]!=s[i-1]){
			int cnt=0;
			while (!q.empty()){
				if (cnt>=k) break;
				cnt++;
				rec u=q.top(); q.pop();
				ans+=a[u.id];
			}
			while (!q.empty()) q.pop();
			q.push((rec){a[i],i});
		}
		else q.push((rec){a[i],i});
	}
	cout<<ans<<endl;
	return 0;
}
