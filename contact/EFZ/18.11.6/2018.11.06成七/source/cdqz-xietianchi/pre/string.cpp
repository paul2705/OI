#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

struct Node{
	int a[2][2];
}tr[N * 4];

void merge(Node &a,const Node &b,const Node &c){
	static Node res;
	memset(res.a , 0x3f , sizeof res.a);
	
	for (int i = 0;i < 2;i++)
	for (int j = 0;j < 2;j++) 
	for (int k = 0;k < 2;k++) 
	res.a[i][j] = min(res.a[i][j] , b.a[i][k] + c.a[k][j]);
	a = res;
}

int a[N] , n , q;
void modify(int o,int l,int r,int pos){
	if (l == r){
		
		if (a[l] == 0){
			tr[o].a[0][0] = 0; 
			tr[o].a[0][1] = 1;
			tr[o].a[1][0] = 2;
			tr[o].a[1][1] = 1;
		}else{
			tr[o].a[0][0] = 1;
			tr[o].a[0][1] = 2;
			tr[o].a[1][0] = 1;
			tr[o].a[1][1] = 0;
		}
		return;
	}
	int mid = l + r >> 1;
	if (pos <= mid) modify(o << 1 , l , mid , pos);
		else 		modify(o << 1 | 1 , mid + 1 , r , pos);
	merge(tr[o] , tr[o << 1] , tr[o << 1 | 1]);
}

void build(int o,int l,int r){
	if (l == r){
		if (a[l] == 0){
			tr[o].a[0][0] = 0; 
			tr[o].a[0][1] = 1;
			tr[o].a[1][0] = 1;
			tr[o].a[1][1] = 1;
		}else{
			tr[o].a[0][0] = 1;
			tr[o].a[0][1] = 1;
			tr[o].a[1][0] = 1;
			tr[o].a[1][1] = 0;
		}
		return;
	}
	int mid = l + r >> 1;
	build(o << 1 , l , mid);
	build(o << 1 | 1 , mid + 1 , r);	

	merge(tr[o] , tr[o << 1] , tr[o << 1 | 1]);
}

Node ans;
void query(int o,int l,int r,int ql,int qr){
	if (ql <= l && r <= qr){
		merge(ans , ans , tr[o] );
		return;
	}
	
	int mid = l + r >> 1;
	if (ql <= mid) query(o << 1 , l , mid , ql , qr);
	if (mid < qr ) query(o << 1 | 1 , mid + 1 , r , ql , qr);
}
char s[N];
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	for (int i = 1;i <= n;i++) a[i] = s[i] - '0';
	
	
	build(1 , 1 , n);
	cin >> q;
	while (q--){
		int opt;scanf("%d",&opt);
		if (opt == 1){
			int l , r;scanf("%d%d",&l,&r);
				ans.a[0][0] = 0; 
				ans.a[0][1] = 1;
				ans.a[1][0] = 1;
				ans.a[1][1] = 1;
			
			query(1 , 1 , n , l , r);
			printf("%d\n" , ans.a[0][0] );
		}else{
			int pos , val;scanf("%d%d",&pos,&val);
			a[pos] = val;
			modify(1 , 1 , n , pos);
		}
	}
	
	return 0;
}
