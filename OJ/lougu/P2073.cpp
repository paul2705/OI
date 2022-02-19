#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
struct tnode{
	int cl,cr,fa,dat,c;
} t[MAXN];
int M,root=-1;
void rightrot(int x){
	int f=t[x].fa;
	t[f].cl=t[x].cr;
	t[x].cr=f; t[x].c=t[f].c;
	t[f].c=0; t[t[f].cl].c=1;
	t[x].fa=t[t[f].fa].fa;
	t[f].fa=x;
	t[t[f].cl].fa=f;
}
void leftrot(int x){
	int f=t[x].fa;
	t[f].cr=t[x].cl;
	t[x].cl=f; t[x].c=t[f].c;
	t[f].c=1; t[t[f].cr].c=0;
	t[x].fa=t[t[f].fa].fa;
	t[f].fa=x;
	t[t[f].cr].fa=f;
}
void splay(int x,int s){
	if (t[s].cl==x){
		if (s==root) root=x;
		return rightrot(x),void();
	}
	if (t[s].cr==x){
		if (s==root) root=x;
		return leftrot(x),void();
	}
	int f=t[x].fa,fa=t[f].fa;
	if (fa!=0){
		if (t[x].c&&t[f].c) rightrot(f),rightrot(x);
		else if (t[x].c) rightrot(x),leftrot(x);
		else if (t[f].c) leftrot(x),rightrot(x);
		else leftrot(f),leftrot(x);
	}
	if (t[x].c) rightrot(x);
	else leftrot(x);
	splay(x,s);
}
int find(int val){
    int p=root;
    while (p){
        if (t[p].dat<val){
            if (t[p].cr) p=t[p].cr;
            else break;
        }
        if (t[p].dat>val){
            if (t[p].cl) p=t[p].cl;
            else break;
        }
        if (t[p].dat==val) return p;
    }
    return p;
}
void insert(int val){
	if (root==-1){
		t[++M]=(tnode){0,0,0,val,1};
		root=M;
		return;
	}
	int p=find(val);
	cout<<"loc: "<<p<<" "<<t[p].dat<<" "<<t[p].cl<<" "<<t[p].cr<<endl;
	if (p==0) return;
	t[++M]=(tnode){0,0,p,val,t[p].dat>val};
	if (t[M].c) t[p].cl=M;
	else t[p].cr=M;
	splay(M,root);
}
int Max(int x){
	while (x){
		if (t[x].cr!=0) x=t[x].cr;
		else break;
	}
	return x;
}
int Min(int x){
	while (x){
		if (t[x].cl!=0) x=t[x].cl;
		else break;
	}
	return x;
}
int join(int x,int y){
	int p=Max(x);
	int f=t[p].fa;
	t[f].cr=0;
	f=t[x].fa;
	t[p].cl=t[f].cl; t[p].cr=t[f].cr;
	t[x].fa=p;
	int fa=t[f].fa;
	if (t[f].c) t[fa].cl=p;
	else t[fa].cr=p;
	return p;
}
void del(int val){
	int p=find(val),x;
	cout<<"loc: "<<p<<endl;
	if (p==root&&t[p].cl+t[p].cr==0) root=-1;
	if (t[p].cl>0||t[p].cr>0){
		x=join(t[p].cl,t[p].cr);
		int f=t[p].fa;
		if (t[f].dat>val) t[f].cl=x;
		else t[f].cr=x;
		splay(x,root);
	}
	else{
		int f=t[p].fa;
		if (t[f].dat>val) t[f].cl=0;
		else t[f].cr=0;
	}
}
void dfs(int x){
	if (x<=0) return;
	cout<<t[x].dat<<" "<<t[x].cl<<" "<<t[x].cr<<endl;
	dfs(t[x].cl);
	dfs(t[x].cr);
}
int main(){
	int x,op;
	while (scanf("%d",&op)){
		if (op==-1) break;
		if (op==1){
			scanf("%d",&x);
			insert(x);
			cout<<"root: "<<root<<endl;
		}
		if (op==2){
			scanf("%d",&x);
			del(x);
			cout<<"root: "<<root<<endl;
		}
		if (op==3){
			printf("%d\n",t[Max(root)].dat);
		}
		if (op==4){
			printf("%d\n",t[Min(root)].dat);
		}
		cout<<"deg: "<<endl;
		dfs(root);
	}
	return 0;
}
