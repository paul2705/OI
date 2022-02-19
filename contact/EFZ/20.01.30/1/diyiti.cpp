#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=3e5+5;
const int MAXT=MAXN*4*20;
struct tnode{
	int l,r,cl,cr;
	ll sz[2],sum[2];
} t[MAXT];
int n,m,rt[MAXN],M;
ll a[MAXN],b[MAXN];
int id[MAXN],rid[MAXN];
int newnode(int pid,int l,int r,int cl,int cr,int x){
	t[++M]=(tnode){l,r,cl,cr};
	for (int i=0;i<=1;i++){
		t[M].sz[i]=t[pid].sz[i];
		t[M].sum[i]=t[pid].sum[i];
	}
	t[M].sz[x&1]++,t[M].sum[x&1]+=x;
//	cout<<__func__<<" id:"<<M<<" L:"<<l<<" R:"<<r<<" sz0:";
//	cout<<t[M].sz[0]<<" sz1:"<<t[M].sz[1]<<" sum0:";
//	cout<<t[M].sum[0]<<" sum1:"<<t[M].sum[1]<<" cl:";
//	cout<<t[M].cl<<" cr:"<<t[M].cr<<endl;
	return M;
}
int build(int l,int r){
	if (l==r) return newnode(0,l,r,0,0,0);
	int mid=(l+r)>>1;
	int cl=build(l,mid),cr=build(mid+1,r);
	return newnode(0,l,r,cl,cr,0);
}
int ins(int pid,int l,int r,int a,int b,int val){
	int cl=t[pid].cl,cr=t[pid].cr;
	if (a<=l&&r<=b) return newnode(pid,l,r,0,0,val);
	int mid=(l+r)>>1;
	if (a>mid) return newnode(pid,l,r,cl,ins(cr,mid+1,r,a,b,val),val);
	else return newnode(pid,l,r,ins(cl,l,mid,a,b,val),cr,val);
}
ll cnt[2],S;
void qryS(int pid,int id,int k){
//	cout<<__func__<<endl;
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	int pcl=t[pid].cl,pcr=t[pid].cr;
//	cout<<" id:"<<id<<" cl:"<<cl<<" cr:"<<cr<<" pid:"<<pid<<" pcl:"<<pcl<<" pcr:"<<pcr<<endl;
	ll res=t[cr].sz[0]+t[cr].sz[1];
	res-=t[pcr].sz[0]+t[pcr].sz[1];
//	cout<<" crsz0:"<<t[cr].sz[0]<<" crsz1:"<<t[cr].sz[1]<<" pcrsz0:"<<t[pcr].sz[0]<<" pcrsz1:"<<t[pcr].sz[1]<<endl;
	ll tmp=t[cr].sum[0]+t[cr].sum[1];
	tmp-=t[pcr].sum[0]+t[pcr].sum[1];
//	cout<<" crsum0:"<<t[cr].sum[0]<<" crsum1:"<<t[cr].sum[1]<<" pcrsum0:"<<t[pcr].sum[0]<<" pcrsum1:"<<t[pcr].sum[1]<<endl;
//	cout<<" K:"<<k<<" res:"<<res<<" tmp:"<<tmp<<endl;
//	cout<<" L:"<<l<<" R:"<<r<<endl;
	//	cout<<"fuck"<<endl;
	if (l==r){
//		S+=t[id].sum[0]+t[id].sum[1]-t[pid].sum[0]-t[pid].sum[1];
//		for (int i=0;i<=1;i++) cnt[i]+=t[id].sz[i]-t[pid].sz[i];
		S+=(ll)::b[l]*k; cnt[::b[l]&1]+=k;
		return;
	}
	if (k>res){
		S+=tmp;
		for (int i=0;i<=1;i++) cnt[i]+=t[cr].sz[i]-t[pcr].sz[i];
		qryS(pcl,cl,k-res);
	}
	else qryS(pcr,cr,k);
}
ll kth(int pid,int id,int k,int tp){
//	cout<<__func__<<endl;
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	int pcl=t[pid].cl,pcr=t[pid].cr;
	ll res=t[cr].sz[tp]-t[pcr].sz[tp];
	ll tmp=t[cr].sum[tp]-t[pcr].sum[tp];
//	cout<<" id:"<<id<<" cl:"<<cl<<" cr:"<<cr<<endl;
//	cout<<" pid:"<<pid<<" pcl:"<<pcl<<" pcr:"<<pcr<<endl;
//	cout<<" crsz:"<<t[cr].sz[tp]<<" pcrsz:"<<t[pcr].sz[tp]<<endl;
//	cout<<" crsum:"<<t[cr].sum[tp]<<" pcrsum:"<<t[pcr].sum[tp]<<endl;
//	cout<<" K:"<<k<<" L:"<<l<<" R:"<<r<<" tp:"<<tp<<endl;
	if (l==r) return b[l];
	if (k>res) return kth(pcl,cl,k-res,tp);
	else return kth(pcr,cr,k,tp);
}
int main(){
	freopen("diyiti.in","r",stdin);
	freopen("diyiti.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	int nn=unique(b+1,b+n+1)-b-1;
	for (int i=1;i<=n;i++){
		id[i]=lower_bound(b+1,b+nn+1,a[i])-b;
//		cout<<i<<" "<<id[i]<<endl;
		rid[id[i]]=a[i];
	}
	rt[0]=build(1,n);
	for (int i=1;i<=n;i++) rt[i]=ins(rt[i-1],1,n,id[i],id[i],a[i]);
//	for (int i=1;i<=n;i++) cout<<t[rt[i]].sz[0]<<" "<<t[rt[i]].sz[1]<<endl;
//	for (int i=1;i<=n;i++) cout<<t[rt[i]].sum[0]<<" "<<t[rt[i]].sum[1]<<endl;
	scanf("%d",&m);
//	cout<<"done"<<endl;
	for (int i=1;i<=m;i++){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		S=0,cnt[0]=cnt[1]=0;
		qryS(rt[l-1],rt[r],k);
//		cout<<S<<" "<<cnt[0]<<" "<<cnt[1]<<endl;
		ll ans=-1;
		if (cnt[0]&1){
			if (cnt[0]){
				if (cnt[1]<t[rt[r]].sz[1]-t[rt[l-1]].sz[1]){ 
					ll tmp=S-kth(rt[l-1],rt[r],cnt[0],0)+kth(rt[l-1],rt[r],cnt[1]+1,1);
//					cout<<kth(rt[l-1],rt[r],cnt[0],0)<<" ";
//					cout<<kth(rt[l-1],rt[r],cnt[1]+1,1)<<endl;
					ans=max(ans,tmp);
				}
			}
		}
		else ans=S;
//		cout<<"fuck"<<endl;
		if (cnt[1]&1){
			if (cnt[1]){
				if (cnt[0]<t[rt[r]].sz[0]-t[rt[l-1]].sz[0]){
					ll tmp=S-kth(rt[l-1],rt[r],cnt[1],1)+kth(rt[l-1],rt[r],cnt[0]+1,0);
//					cout<<kth(rt[l-1],rt[r],cnt[1],1)<<" ";
//					cout<<kth(rt[l-1],rt[r],cnt[0]+1,0)<<endl;
					ans=max(ans,tmp);
				}
			}
		}
		else ans=S;
		printf("%lld\n",ans);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
