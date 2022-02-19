#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
const ll MAXN=1e3+5;
const ll MAXM=1e6+6;
ll a[MAXN][MAXN],b[MAXN][MAXN];
ll n,m;
struct rec{
	ll x,y,id,val;
};
vector<rec> c[MAXM];
bool use[MAXN][MAXN];
rec lis[MAXM];
ll cnt;
ll mx;
ll f[3][MAXM];
bool cmp(rec a,rec b){ return a.id<b.id; }
ll sum[3][5][102*4+10][1002*4+10];
void pushup(ll id,ll rt,ll xrt){
    sum[id][1][xrt][rt]=max(sum[id][1][xrt][rt*2],sum[id][1][xrt][rt*2+1]);
    sum[id][2][xrt][rt]=max(sum[id][2][xrt][rt*2],sum[id][2][xrt][rt*2+1]);
    sum[id][3][xrt][rt]=max(sum[id][3][xrt][rt*2],sum[id][3][xrt][rt*2+1]);
    sum[id][4][xrt][rt]=max(sum[id][4][xrt][rt*2],sum[id][4][xrt][rt*2+1]);
}
void buildy(ll id,ll rt,ll left,ll right,ll xrt){
    for (ll k=1;k<=4;k++) sum[id][k][xrt][rt] = -1;
    if(left != right){
        ll mid=(left+right)/2;
        buildy(id,rt*2,left,mid,xrt);
        buildy(id,rt*2+1,mid+1,right,xrt);
    }
}
void build(ll id,ll rt,ll left,ll right){
    buildy(id,1,0,n,rt);
    if(left!=right){
        ll mid=(left+right)/2;
        build(id,rt*2,left,mid);
        build(id,rt*2+1,mid+1,right);
    }
}
void updatey(ll id,ll rt,ll left,ll right,ll y,ll ad1,ll ad2,ll ad3,ll ad4,ll xrt){
    if(left==right&&left==y){
        sum[id][1][xrt][rt]=max(sum[id][1][xrt][rt],ad1);
        sum[id][2][xrt][rt]=max(sum[id][2][xrt][rt],ad2);
        sum[id][3][xrt][rt]=max(sum[id][3][xrt][rt],ad3);
        sum[id][4][xrt][rt]=max(sum[id][4][xrt][rt],ad4);
        return;
    }
    ll mid=(left+right)/2;
    if(y<=mid) updatey(id,rt*2,left,mid,y,ad1,ad2,ad3,ad4,xrt);
    if(y>mid) updatey(id,rt*2+1,mid+1,right,y,ad1,ad2,ad3,ad4,xrt);
    pushup(id,rt,xrt);
}
void update(ll id,ll rt,ll left,ll right,ll x,ll y,ll ad1,ll ad2,ll ad3,ll ad4){
    updatey(id,1,0,n,y,ad1,ad2,ad3,ad4,rt);
    if(left!=right){
        ll mid=(left+right)/2;
        if(x<=mid) update(id,rt*2,left,mid,x,y,ad1,ad2,ad3,ad4);
        if(x>mid)  update(id,rt*2+1,mid+1,right,x,y,ad1,ad2,ad3,ad4);
    }
}
void queryY(ll rid,ll rt,ll left,ll right,ll y1,ll y2,ll xrt,ll id){
    if(left>=y1&&right<=y2){
        mx=max(mx,sum[rid][id][xrt][rt]);
        return;
    }
    ll mid=(right+left)/2;
    if(y1<=mid) queryY(rid,rt*2,left,mid,y1,y2,xrt,id);
    if(y2>mid) queryY(rid,rt*2+1,mid+1,right,y1,y2,xrt,id);
}
void query(ll rid,ll rt,ll left,ll right,ll x1,ll y1,ll x2,ll y2,ll id){
	cout<<left<<" "<<right<<endl;
	if(left>=x1&&right<=x2){
        queryY(rid,1,0,n,y1,y2,rt,id);
        return ;
    }
    ll mid=(left+right)/2;
    if(x1<=mid) query(rid,rt*2,left,mid,x1,y1,x2,y2,id);
    if(x2>mid) query(rid,rt*2+1,mid+1,right,x1,y1,x2,y2,id);
}
int main(){
	scanf("%lld%lld",&n,&m);
	for (ll i=1;i<=n;i++){
		for (ll j=1;j<=m;j++) scanf("%lld",&a[i][j]);
	}
	for (ll i=1;i<=n;i++){
		for (ll j=1;j<=m;j++){
			scanf("%lld",&b[i][j]);
			lis[++cnt]=(rec){i,j,a[i][j],b[i][j]};
		}
	}
	build(0,1,n,m); build(1,1,n,m);
	sort(lis+1,lis+cnt+1,cmp);
	ll l=1,r=1,res=0,las=0;
	for (;lis[l].id==lis[r].id;r++) f[1][res++]=lis[r].val;
	ll cur=1,old=0;
	for (;r<cnt;){
		cout<<l<<" "<<r<<endl;
		swap(cur,old);
		ll nl=r+1,nr=r+1;
		for (;lis[nl].id==lis[nr].id;nr++){
			ll x=lis[nr].x,y=lis[nr].y;
			for (ll k=1;k<=4;k++){
				mx=0;
				query(old,1,n,m,1,1,x,y,k);
				f[cur][nr-r-1]=max(f[cur][nr-r-1],x+y+mx);
			}
			f[cur][nr-r-1]+=lis[nr].val;
			ll ret=f[cur][nr-r-1];
			update(cur,1,n,m,x,y,-x-y+ret,x-y+ret,-x+y+ret,x+y+ret);
		}
//		cout<<"fuck"<<endl;
		for (ll i=l;i<=r;i++){
			ll ret=f[old][i-las-1];
			ll x=lis[i].x,y=lis[i].y;
			update(old,1,n,m,x,y,x+y-ret,-x+y-ret,x-y-ret,-x-y-ret);
		}
		las=r,l=nl,r=nr;
	}
	ll ans=0;
	for (ll i=l;i<=r;i++){
		ans=max(ans,f[cur][i-las-1]);
	}
	printf("%lld\n",ans);
	return 0;
}
