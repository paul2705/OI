#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
const int MAXN=2e5+5;
const int MAXM=4e5+5;
int n,l[MAXN],r[MAXN],pos[MAXM],M;
struct rec{
	int l,r,m,id;
	bool operator < (const rec &a) const { return l>a.l; }
} a[MAXN];
set<rec> s;
int f[MAXM][20];

bool cmp_l(rec a,rec b){ return a.l==b.l?a.r<b.r:a.l<b.l; }
bool cmp_id(rec a,rec b){ return a.id<b.id; }

int calc(int i,int j){
	int ans=0;
	for (int k=18;k>=0;k--){
		if (f[i][k]<=j) ans+=(1<<k),i=f[i][k];
	}
	return ans;
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&a[i].l,&a[i].r),a[i].r++;
		pos[++M]=a[i].l,pos[++M]=a[i].r;
		a[i].id=i;
	}
	sort(pos+1,pos+M+1);
	int len=unique(pos+1,pos+M+1)-pos-1;
	for (int i=1;i<=n;i++){
		a[i].l=lower_bound(pos+1,pos+len+1,a[i].l)-pos;
		a[i].r=lower_bound(pos+1,pos+len+1,a[i].r)-pos;
//		cout<<i<<" "<<a[i].l<<" "<<a[i].r<<endl;
	}
	sort(a+1,a+n+1,cmp_l);
	
	for (int i=1;i<=n;i++){
		if (!f[a[i].l][0]) f[a[i].l][0]=a[i].r;
	}
	int j=0; while (f[j][0]==0) j++; f[len+1][0]=len+1;
	for (int i=1;i<=len;i++){
		if (!f[i][0]&&i>j){
			j=i; while (f[j][0]==0) j++;
			f[i][0]=f[j][0];
		}
		else if (!f[i][0]) f[i][0]=f[j][0];
//		cout<<i<<" "<<j<<" "<<f[i][0]<<endl;
	}
	for (int i=1;i<=len;i++){
//		cout<<i<<" 0"<<f[i][0]<<endl;
		for (int k=1;k<20;k++){
			if (f[i][k-1]==MAXM) f[i][k]=MAXM;
			else f[i][k]=f[f[i][k-1]][k-1];
			if (f[i][k]==0) f[i][k]=MAXM;
//			cout<<i<<" "<<k<<" "<<f[i][k]<<endl;
		}
	}
	sort(a+1,a+n+1,cmp_id);
	M=calc(1,len);
	s.insert((rec){1,len,M,0});
	cout<<M<<endl;

//	cout<<calc(2,7)<<endl;

	for (int i=1;i<=n;i++){
		set<rec>::iterator it=s.lower_bound(a[i]);
		if (it!=s.end()){
			int x=(*it).l,y=(*it).r,c=a[i].l,d=a[i].r;
			if (d<=y){
				int ans1=calc(x,c),ans2=calc(d,y);
				if (ans1+1+ans2==(*it).m){
					cout<<i<<" ";
					s.erase(it);
					s.insert((rec){x,c,ans1});
					s.insert((rec){d,y,ans2});
				}
			}
		}
	}
}
