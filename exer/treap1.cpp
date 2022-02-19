#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=1e5+5;
const int INF=1e9*2;
struct treap{
	int dat,val;
	int cnt,size;
	int l,r;
} tp[MAXN];
int n,q,M,root;
int newnode(int val){
	M++;
	tp[M]=(treap){rand(),val,1,1,0,0};
	return M;
}
void update(int p){
	tp[p].size=tp[tp[p].l].size+tp[tp[p].r].size+tp[p].cnt;
}
void build(){
	newnode(-INF); newnode(INF);
	root=1,tp[root].r=2; update(root);
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
int get_val(int p,int rank){
	if (p==0) return INF;
	if (tp[tp[p].l].size>=rank) return get_val(tp[p].l,rank);
	else if (tp[tp[p].l].size+tp[p].cnt>=rank) return tp[p].val;
	return get_val(tp[p].r,rank-tp[tp[p].l].size-tp[p].cnt);
}
int get_rank(int p,int val){
	if (p==0) return 0;
	if (tp[p].val>val) return get_rank(tp[p].l,val);
	if (tp[p].val==val) return tp[tp[p].l].size+1;
	return get_rank(tp[p].r,val)+tp[tp[p].l].size+tp[p].cnt;
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
int get_pre(int val){
	int ans=1,p=root;
	while (p){
		if (tp[p].val==val){
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
int get_next(int val){
	int ans=2,p=root;
	while (p){
		if (tp[p].val==val){
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
	if (p==0) return;
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
	srand(20180514);
	build();
	scanf("%d%d",&n,&q); 
	for (int i=0,x;i<n;i++){
		scanf("%d",&x);
		ins(root,x);
	}
	printf("R:get_rank V:get_val M:remove P:get_pre N:get_next \n");
	for (int i=0,x;i<q;i++){
		char c=getchar();
		while (c<'A'||c>'Z') c=getchar();
		scanf("%d",&x);
		switch(c){
			case 'R': printf("%d\n",get_rank(root,x)-1); break;
			case 'V': printf("%d\n",get_val(root,x+1)); break;
			case 'M': Remove(root,x); break;
			case 'P': printf("%d\n",get_pre(x)); break;
			case 'N': printf("%d\n",get_next(x)); break;
		}
	}
	return 0;
}
