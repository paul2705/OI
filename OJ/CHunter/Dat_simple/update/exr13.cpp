#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=3e4+5;
struct mx{
	int dat;
	bool operator < (const mx& b) const{
		return dat<b.dat;
	}
};
priority_queue<mx> q1;
struct mn{
	int dat;
	bool operator < (const mn& b) const{
		return dat>b.dat;
	}
};
priority_queue<mn> q2;
int n,m,a[MAXN];
void Push(int x){
	if (q1.empty()) return q2.push((mn){x}),void();
	int q1t=q1.top().dat;
	if (x<q1t){
		q1.pop(); q2.push((mn){q1t});
		q1.push((mx){x});
	}
	else q2.push((mn){x});
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int pos=1;
	for (int i=1;i<=m;i++){
		int x; scanf("%d",&x);
		while (x>=pos) Push(a[pos++]);
		q1.push((mx){q2.top().dat}); q2.pop();
		printf("%d\n",q1.top().dat);
	}
	return 0;
}
