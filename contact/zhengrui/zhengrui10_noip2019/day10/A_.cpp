#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
const int MAXT=MAXN*4;
int n,q;
ll a[MAXN],b[MAXN];
struct rec{
	int l,r;
	bool operator < (const rec& b) const{
		return l<b.l;
	}
};
set<rec> s;
ll ans;
int main(){
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<n;i++){
		if (a[i]>0) ans+=max(a[i],a[i+1]);
		else {
			int l=i;
			while (a[i+1]<=0) i++;
			ans+=a[i+1];
			s.insert((rec){l,i});
		}
	}
	printf("%lld\n",ans);
	for (int i=1;i<=q;i++){
		ll x,y; scanf("%lld%lld",&x,&y);
		ans-=(x>1?max(0ll,max(a[x-1],a[x])):0)+(x<n?max(0ll,max(a[x],a[x+1])):0);
		if (a[x]>0&&y>0){
			a[x]=y;
			ans+=max(a[x-1],a[x])+max(a[x],a[x+1]);
		}
		else if (a[x]>0){
			if (a[x-1]>0){
				if (a[x+1]>0){
					ans+=a[x-1]+a[x+1];
					a[x]=y;
					s.insert((rec){x,x});
				}
				else {
//					cout<<"in"<<endl;
					set<rec>::iterator it=s.lower_bound((rec){x+1,0});
					if (it==s.end()){
						s.insert((rec){x,x}); a[x]=y;
					}
					else {
						int l=it->l,r=it->r; s.erase(it);
						s.insert((rec){x,r}); a[x]=y;
					}
					ans+=a[x-1];
				}
			}
			else {
				if (a[x+1]>0){
//					cout<<"in"<<endl;
					set<rec>::iterator it=s.lower_bound((rec){x,0});
					if (it!=s.begin()){
						it--;
						int l=it->l,r=it->r; s.erase(it);
						s.insert((rec){l,x}); a[x]=y;
					}
					else {
						s.insert((rec){x,x}); a[x]=y;
					}
					ans+=a[x+1];
				}
				else {
//					cout<<"in"<<endl;
					set<rec>::iterator it1=s.lower_bound((rec){x+1,0});
					if (x==1){
						int l=it1->l,r=it1->r; s.erase(it1);
						s.insert((rec){x,r}); a[x]=y;
					}
					else if (x==n){
						it1--;
						int l=it1->l,r=it1->r; s.erase(it1);
						s.insert((rec){l,x}); a[x]=y;
					}
					else {
						set<rec>::iterator it2=(--it1); it1++;
						int l=it2->l,r=it1->r; s.erase(it1); s.erase(it2);
						s.insert((rec){l,r}); a[x]=y;
					}
				}
			}
		}
		else if (y>0){
			if (a[x-1]>0){
				if (a[x+1]>0){
					set<rec>::iterator it=s.lower_bound((rec){x,0});
					s.erase(it); a[x]=y;
					ans+=max(a[x-1],a[x])+max(a[x],a[x+1]);
				}
				else {
					set<rec>::iterator it=s.lower_bound((rec){x,0});
					int l=it->l,r=it->r; s.erase(it);
					s.insert((rec){x+1,r}); a[x]=y;
					ans+=max(a[x-1],a[x])+max(a[x],a[x+1]);
				}
			}
			else {
				if (a[x+1]>0){
					set<rec>::iterator it=s.lower_bound((rec){x+1,0});
					it--;
					int l=it->l,r=it->r; s.erase(it);
					s.insert((rec){l,x-1}); a[x]=y;
					ans+=a[x+1];
				}
				else {
					set<rec>::iterator it=s.lower_bound((rec){x+1,0});
					it--;
					int l=it->l,r=it->r; s.erase(it);
					s.insert((rec){l,x-1}); a[x]=y;
					s.insert((rec){x+1,r});
					ans+=a[x]+a[x];
				}
			}
		}
		else a[x]=y;
		printf("%lld\n",ans);
	}
	return 0;
}
