#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=1e5+5;
const int INF=1e9*2;
struct t{
	int l,r;
	int val,dat;
	int cnt,size;
} tp[MAXN];
int M,root,n,q;
int newnode(int val){
	M++;
	tp[M].val=val,tp[M].dat=rand(),tp[M].cnt=tp[M].size=1;
	return M;
}
void update(int p){
	tp[p].size=tp[tp[p].l].size+tp[tp[p].r].size+tp[p].cnt;
}
void build(){
	newnode(-INF); newnode(INF);
	root=1,tp[root].r=2; update(root);
}
int GRBV(int p,int val){
	if (p==0) return 0;
	if (val==tp[p].val) return tp[tp[p].l].size+1;
	if (val<tp[p].val) return GRBV(tp[p].l,val);
	return GRBV(tp[p].r,val)+tp[tp[p].l].size+tp[p].cnt;
}
int GVBR(int p,int rank){
	if (p==0) return INF;
	if (tp[tp[p].l].size>=rank) return GVBR(tp[p].l,rank);	
	if (tp[tp[p].l].size+tp[p].cnt>=rank) return tp[p].val;
	return GVBR(tp[p].r,rank-tp[tp[p].l].size-tp[p].cnt);
}
void rightrot(int &p){
	int q=tp[p].l;
	tp[p].l=tp[q].r,tp[q].r=p,p=q;
	update(tp[p].r); update(p);
}
void leftrot(int &p){
	int q=tp[p].r;
	tp[p].r=tp[q].l,tp[q].l=p,p=q;
	update(tp[p].l); update(p);
}
void ins(int &p,int val){
	if (p==0) return p=newnode(val),void();
	if (val==tp[p].val) return tp[p].cnt++,update(p),void();
	if (val<tp[p].val){
		ins(tp[p].l,val);
		if (tp[p].dat<tp[tp[p].l].dat) rightrot(p);
	}
	else {
		ins(tp[p].r,val);
		if (tp[p].dat<tp[tp[p].r].dat) leftrot(p);
	}
	update(p);
}
int GPre(int val){
	int ans=1,p=root;
	while (p){
		if (val==tp[p].val){
			if (tp[p].l>0){
				for (p=tp[p].l;tp[p].r>0;) p=tp[p].r;
				ans=p;
			}
			break;
		}
		if (tp[p].val<val&&tp[p].val>tp[ans].val) ans=p;
		p=val<tp[p].val?tp[p].l:tp[p].r;
	}
	return tp[ans].val;
}
int GNext(int val){
	int ans=2,p=root;
	while (p){
		if (val==tp[p].val){
			if (tp[p].r>0){
				for (p=tp[p].r;tp[p].l>0;) p=tp[p].l;
				ans=p;
			}
			break;
		}
		if (tp[p].val>val&&tp[p].val<tp[ans].val) ans=p;
		p=val<tp[p].val?tp[p].l:tp[p].r;
	}
	return tp[ans].val;
}
void Remove(int &p,int val){
	if (p==0) return void();
	if (val==tp[p].val){
		if (tp[p].cnt>1) return tp[p].cnt--,update(p),void();
		if (tp[p].l||tp[p].r){
			if (tp[p].r==0||tp[tp[p].l].dat>tp[tp[p].r].dat) rightrot(p),Remove(tp[p].r,val);
			else leftrot(p),Remove(tp[p].l,val);
			update(p);
		}
		else p=0;
		return void();
	}
	val<tp[p].val?Remove(tp[p].l,val):Remove(tp[p].r,val);
	update(p);
}
int main(){
	scanf("%d%d",&n,&q);
	build();
	for (int i=0,x;i<n;i++){
		scanf("%d",&x);
		ins(root,x);
	}
	printf("GPre\n");
	for (int i=0,x;i<q;i++){
		scanf("%d",&x);
		printf("%d\n",GPre(x));
	}
	printf("GNext\n");
	for (int i=0,x;i<q;i++){
		scanf("%d",&x);
		printf("%d\n",GNext(x));
	}
	printf("Remove\n");
	for (int i=0,x;i<q;i++){
		scanf("%d",&x);
		Remove(root,x);
	}
	printf("GVBR\n");
	for (int i=0,x;i<q;i++){
		scanf("%d",&x);
		printf("%d\n",GVBR(root,x+1));
	}
	printf("GRBV\n");
	for (int i=0,x;i<q;i++){
		scanf("%d",&x);
		printf("%d\n",GRBV(root,x)-1);
	}
	return 0;
}
