#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;

const int N = 2e6+5;
unsigned int SA,SB,SC;int n,a[N],b[N],c[N];
struct rec{
	int a,b,c;
} res[N];
map<int,int> mp;
unsigned int rd(){
	SA^=SA<<16;SA^=SA>>5;SA^=SA<<1;
//	cout<<__func__<<": "<<SA<<endl;
	unsigned int t=SA;SA=SB;SB=SC;SC^=t^SA;
	cout<<__func__<<": "<<SA<<" "<<SB<<" "<<SC<<endl;
	if (mp[SA]>0) printf("ERR\n");
	mp[SA]++;
	return SC;
}
void gen(int *P){
	for (int i=1;i<=n;++i) P[i]=i;
	for (int i=1;i<=n;++i) swap(P[i],P[1+rd()%n]);
}
bool cmp(rec a,rec b){return a.a<b.a; }
int main(){
	scanf("%d%u%u%u",&n,&SA,&SB,&SC);
	gen(a);gen(b);gen(c);
	for (int i=1;i<=n;i++) res[i]=(rec){a[i],b[i],c[i]};
	sort(res+1,res+n+1,cmp);
	for (int i=1;i<=n;i++) printf("%d ",res[i].a); cout<<endl;
	for (int i=1;i<=n;i++) printf("%d ",res[i].b); cout<<endl;
	for (int i=1;i<=n;i++) printf("%d ",res[i].c); cout<<endl;
	return 0;
}
