#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 100010

int fa[MAXN],ch[MAXN][2],tag[MAXN],s[MAXN];
int top = 0;

bool is_root(int x) {
	return ((ch[fa[x]][0] != x ) && (ch[fa[x]][1] != x));
}
void pushdown(int x) {
	if (tag[x]) {
		tag[x] =0 ,tag[ch[x][0]] ^= 1,tag[ch[x][1]] ^= 1;
		swap(ch[x][0],ch[x][1]);
	}
}
void rotate(int x) {
	int y = fa[x],z = fa[y],d = (ch[y][1] == x);
	if (!is_root(y)) ch[z][ch[z][1] == y] = x;
	fa[x] = z,fa[y] = x,fa[ch[x][d^1]] = y,ch[y][d] = ch[x][d^1],ch[x][d^1] = y;
}

void spaly(int x) {
	s[top=1] = x;
	for (int i=x;!is_root(i);i=fa[i]) s[++top] = fa[i];
	for (;top;top--) pushdown(s[top]);
	while (!is_root(x)) rotate(x);
	
}
void splay(int x) {
	s[top=1] = x;
	for (int i=x;!is_root(i);i=fa[i]) s[++top] = fa[i];
	for (;top;top--) pushdown(s[top]);
	while (!is_root(x)) {
		int y = fa[x],z = fa[y],d = (ch[y][1] == x);
		if (!is_root(y)) 
			if ((ch[y][1] == x) ^ (ch[z][1] == y)) rotate(x);
			else rotate(y);
		rotate(x);
	}
}
void access(int x){
	for (int t=0;x;x = fa[x]) {
		splay(x),ch[x][1] = t,t = x;
	}
}
void make_root(int x) {
	access(x),splay(x),tag[x] ^= 1;
}

void cut(int x,int y) {
	make_root(x),access(y),splay(y),fa[x] = ch[y][0] = 0;
}
void link(int x,int y) {
	make_root(x),fa[x] = y,access(x);
}

int find_root(int x) {
	access(x),splay(x);
	pushdown(x);
	while (ch[x][0]) {
		x = ch[x][0],pushdown(x);
	}
	return x;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) {
		char c= getchar();
		while (!('A' <= c && c <= 'z')) c = getchar();
		if (c == 'Q') {
			for (int i=1;i<=5;i++) c = getchar();
			int l,r;
			scanf("%d%d",&l,&r);
			puts(find_root(l) == find_root(r) ? "Yes" : "No");
		}
		if (c == 'C') {
			for (int i=1;i<=6;i++) c=  getchar();
			int l,r;
			scanf("%d%d",&l,&r);
			link(l,r);
		}
		if (c == 'D') {
			for (int i=1;i<=6;i++) c = getchar();
			int l,r;
			scanf("%d%d",&l,&r);
			cut(l,r);
		}
	}
}
