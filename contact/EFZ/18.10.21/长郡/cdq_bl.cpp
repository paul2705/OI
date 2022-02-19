#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 2e6+5;
int ans;
unsigned int SA,SB,SC;int n,a[N],b[N],c[N];
struct rec{
    int a,b,c;
} res[N];
unsigned int rd(){
    SA^=SA<<16;SA^=SA>>5;SA^=SA<<1;
   unsigned int t=SA;SA=SB;SB=SC;SC^=t^SA;
   return SC;
}
void gen(int *P){
    for (int i=1;i<=n;++i) P[i]=i;
    for (int i=1;i<=n;++i) swap(P[i],P[1+rd()%n]);
}
bool cmp(rec a,rec b){return a.a<b.a; }
int main(){
	freopen("cdq.in","r",stdin);
	freopen("cdq1.out","w",stdout);
	scanf("%d%u%u%u",&n,&SA,&SB,&SC);
    gen(a);gen(b);gen(c);
    for (int i=1;i<=n;i++) res[i]=(rec){a[i],b[i],c[i]};
    sort(res+1,res+n+1,cmp);
    for (int i=1;i<=n;i++){
    	for (int j=1;j<i;j++){
    		if (res[j].b<res[i].b&&res[j].c<res[i].c)ans++;
		}
	}
	printf("%d\n",ans);
    fclose(stdin); fclose(stdout);
    return 0;
}

