#include <bits/stdc++.h>
#define pir pair<long long,long long> 
#define plll pair<long long,pair<long long,long long> >
#define ll long long
//ljoihwqcQAQ
using namespace std;
const ll QJN=2000010;//新区间MAXN NUM 
const ll N=1000001;
struct NODE{
	ll l,r;
	NODE* lc;
	NODE* rc;
	ll maxn,tag;
	ll num;
};
ll h,w;
ll h1,h2,w1,w2;
char s1[N],s2[N];
//有关新区间
struct QJOP{
	ll l,r,add;
};
ll wqjn;//在w方向(横向)新区间个数
ll hqjn;//h方向：纵向
ll wqj2zxl[QJN];//区间从哪里开始[,
ll hqj2zxl[QJN];//区间从哪里开始[, 
ll wgz2qj1[N],wgz2qj2[N],w1n,w2n;
ll hgz2qj1[N],hgz2qj2[N],h1n,h2n;
vector<QJOP> op[QJN]; //在新纵向区间的操作
priority_queue<plll> Q;
//线段树 
void update(NODE* now){
	if(now->tag==0)
		return;
	now->lc->tag+=now->tag;
	now->lc->maxn+=now->tag;
	now->rc->tag+=now->tag;
	now->rc->maxn+=now->tag;
	now->tag=0; 
	//显然,lc与rc满足新maxn的num不变 
}
void build(NODE* now,ll l,ll r){//[l,r)
	now->lc=NULL;
	now->rc=NULL;
	now->maxn=0;now->tag=0;
	now->l=l;now->r=r;
	if(l==r-1){
		now->num=wqj2zxl[l+1]-wqj2zxl[l];
	}
	if(l!=r-1){
		ll mid=(l+r)/2;
		now->lc=new NODE;
		now->rc=new NODE;
		build(now->lc,l,mid);
		build(now->rc,mid,r);
		now->num=now->lc->num + now->rc->num;
	}
	return;
}
void change(NODE* now,ll l,ll r,ll add){
	if(l<=now->l && r>=now->r){
		now->maxn+=add;
		now->tag+=add;
		return;//显然now->num不变 
	}
	update(now);
	if(l<now->lc->r)	change(now->lc,l,r,add);
	if(r>now->rc->l)	change(now->rc,l,r,add);
	now->maxn=max(now->lc->maxn,now->rc->maxn);
	now->num=0;
	if(now->maxn == now->lc->maxn)	now->num+=now->lc->num;
	if(now->maxn == now->rc->maxn)	now->num+=now->rc->num;
	return;
}
pir query(NODE* now,ll l,ll r){
	if(l<=now->l && r>=now->r){
		return make_pair(now->maxn,now->num);
	}
	update(now);
	ll maxn=0,num=0;
	pir temp1=make_pair(0,0),temp2=make_pair(0,0);
	if(l<now->lc->r){
		temp1=query(now->lc,l,r);
	}
	if(r>now->rc->l){
		temp2=query(now->rc,l,r);
	}
	maxn=max(temp1.first,temp2.first);
	if(maxn==temp1.first)	num+=temp1.second;
	if(maxn==temp2.first)	num+=temp2.second;
	return make_pair(maxn,num);
}
// 
void zjsolve(){
		//计算新区间
	hqjn=h1+h2-1;
	wqjn=w1+w2-1;
	//``计算纵向区间的hqj2zxl
	ll gzx=1;
	for(ll i=1;i<=h;i+=h1)
		Q.push(make_pair(-i,make_pair(2,gzx++)));
	gzx=2;
	for(ll i=1+h2;i<=h;i+=h2)
		Q.push(make_pair(-i,make_pair(1,gzx++)));
	ll cur=1;
	plll temp;
	while(!Q.empty()){
		temp=Q.top();Q.pop();
		hqj2zxl[cur]=-temp.first;
		if(temp.second.first==1)
			hgz2qj1[temp.second.second]=cur,h1n++;
		else
			hgz2qj2[temp.second.second]=cur,h2n++;
		cur++;
	}
	hgz2qj1[1]=1;h1n++;
	hgz2qj1[h1n+1]=hqjn+1;
	hgz2qj2[h2n+1]=hqjn+1;
	hqj2zxl[hqjn+1]=h+1;
	//``计算横向区间的wqj2zxl
	gzx=1; 
	for(ll i=1;i<=w;i+=w1)
		Q.push(make_pair(-i,make_pair(2,gzx++)));
	gzx=2;
	for(ll i=1+w2;i<=w;i+=w2)
		Q.push(make_pair(-i,make_pair(1,gzx++)));
	cur=1;
	while(!Q.empty()){
		temp=Q.top();Q.pop();
		wqj2zxl[cur]=-temp.first;
		if(temp.second.first==1)
			wgz2qj1[temp.second.second]=cur,w1n++;
		else
			wgz2qj2[temp.second.second]=cur,w2n++;
		cur++;
	}
	wgz2qj1[1]=1;w1n++;
	wgz2qj1[w1n+1]=wqjn+1;
	wgz2qj2[w2n+1]=wqjn+1;
	wqj2zxl[wqjn+1]=w+1; 
	
	//计算op
	//``计算s1带来的op
	ll s1get=w/w1;
	//以s1为序遍历
	bool flag;
	int add;
	for(ll i=1;i<=h1;i++){
		for(ll j=1;j<=w1;j++){
			flag=false;
			if(s1[(i-1)*w1+j-1]-'0' && i==1)	flag=true,add=s1[(i-1)*w1+j-1]-'0';
			if (s1[(i-1)*w1 + j-1]-s1[(i-2)*w1 + j-1] && i!=1)
				flag=true,add=s1[(i-1)*w1 + j-1]-s1[(i-2)*w1 + j-1];
			if(flag){
				op[hgz2qj1[i]].push_back((QJOP){wgz2qj1[j],wgz2qj1[j+1],add});
			}
		}
	}
	//以s2为序遍历
	for(ll i=1;i<=h2;i++){
		for(ll j=1;j<=w2;j++){
			flag=false;
			if(add=s2[(i-1)*w2+j-1]-'0' && i==1)	flag=true;
			if (add=s2[(i-1)*w2 + j-1]-s2[(i-2)*w2 + j-1] && i!=1)
				flag=true;
			if(flag){
				op[hgz2qj2[i]].push_back((QJOP){wgz2qj2[j],wgz2qj2[j+1],add});
			}
		}
	}
	 
/*	for(int i=1;i<5;i++){
		printf("%d::\n",i);
		for(int j=0;j<op[i].size();j++)
			printf("%d %d %d\n",op[i][j].l,op[i][j].r,op[i][j].add);
	}*/
	return;
}
ll gcd(ll x,ll y){
	if(x<y){
		ll temp=x;x=y;y=temp;
	}
	//x>=y
	if(y==0)	return x;
	else	return gcd(y,x%y);
}
int main(){
	//input
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	scanf("%lld %lld",&h1,&w1);
	scanf("%s",s1);
	scanf("%lld %lld",&h2,&w2);
	scanf("%s",s2);
	h=h1/gcd(h1,h2)*h2;
	w=w1/gcd(w1,w2)*w2;
	zjsolve();
	//work
	NODE* root=new NODE;
	build(root,1,wqjn+1);
	//''第一遍 找1
	QJOP opnow; 
	ll ans=0;
	pir temp;
	for(int i=1;i<=hqjn;i++){
		for(int j=0;j<op[i].size();j++){
			opnow=op[i][j];
			change(root,opnow.l,opnow.r,opnow.add);
		}
		temp=query(root,1,wqjn+1);
		if(temp.first==2)
			ans+=temp.second*(hqj2zxl[i+1]-hqj2zxl[i]);
	}
	NODE* root2=new NODE;
	build(root2,1,wqjn+1);
	for(int i=1;i<=wqjn;i++){
		for(int j=0;j<op[i].size();j++){
			opnow=op[i][j];
			change(root2,opnow.l,opnow.r,-opnow.add);
		}
		temp=query(root2,1,wqjn+1);
		if(temp.first==0)
			ans+=temp.second*(hqj2zxl[i+1]-hqj2zxl[i]);
	} 
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
