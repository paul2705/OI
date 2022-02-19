#include <bits/stdc++.h>
#define mp make_pair
#define fx first
#define fy second
using namespace std;

typedef pair<int,int> pii;
const int N = 1e5 + 10;
const double inf = 100000000000000000.00;
void Upmin(pii &t1 , pii t2) {
	if (t2.fx < t1.fx || ( t2.fx == t1.fx && t2.fy > t1.fy ) )	t1 = t2;
}

struct Seg {
	struct Node {
		int near , id;
	} tr[N << 2];

	void up(int x){
	
	}
	void modify(int x , int l , int r , int ql , int qr , int pos , int id) {
		if( ql <= l && r <= qr) {
			if(tr[x].near >= pos) {
				tr[x].near = pos;
				tr[x].id = id;
			}
			return;
		}
		int mid = l + r >> 1;
		if(ql <= mid) modify(x << 1 , l , mid , ql , qr , pos , id);
		if(mid < qr ) modify(x << 1 | 1 , mid + 1 , r , ql , qr , pos , id);
	}
	
	
	pii query(int x , int l , int r , int pos) {
		if(l == r){
			return mp(tr[x].near , tr[x].id);
		}
		int mid = l + r >> 1;
		pii ans = mp(tr[x].near , tr[x].id);
		if(pos <= mid) Upmin( ans , query(x << 1 , l , mid , pos));
		else Upmin( ans, query(x << 1 | 1 , mid + 1 , r , pos));
		return ans;
	}
	
	
	void build(int x , int l , int r) {

		tr[x].near = 2000000000;
		if(l == r) return;
		int mid = l + r >> 1;
		build(x << 1 , l , mid);
		build(x << 1 | 1 , mid + 1 , r);
	}
} Tx,Ty;

struct Tranagle {
	int opt , xl , xr , yl , yr;
	double up , mid , rig;
} t[N];


double slope[N << 2];
double K(int x , int y) {
	if(x == 0) return inf;
	return 1.00 * y / (1.00 * x );
}

int zeroy , idzeroy , zerox , idzerox;
int n , cnt;

int main() {
	freopen("raytracing.in","r",stdin);
	freopen("raytracing.out","w",stdout);
	cin >> n;
	zeroy = zerox = 2000000000;
	for(int i = 1; i <= n; i ++ ) {
		scanf("%d",&t[i].opt);
		if(t[i].opt == 1) {
			scanf("%d%d%d%d" , &t[i].xl , &t[i].yl , &t[i].xr , &t[i].yr);

			slope[ ++cnt ] = t[i].up = K(t[i].xl , t[i].yr);
			slope[ ++cnt ] = t[i].mid = K(t[i].xl , t[i].yl);
			slope[ ++cnt ] = t[i].rig = K(t[i].xr , t[i].yl);


		} else {
			scanf("%d%d",&t[i].xl,&t[i].yl);
			t[i].up = K(t[i].xl , t[i].yl);
			slope[ ++cnt ] = t[i].up;
		}
	}
	
	sort(slope + 1 , slope + 1 + cnt);
	cnt = unique(slope + 1 , slope + 1 + cnt) - slope - 1;
	Tx.build(1 , 1 , cnt);
	Ty.build(1 , 1 , cnt);
	
	
	for(int i = 1; i <= n; i ++ ) {
		if(t[i].opt == 1) {
			
			
			int Mid = lower_bound(slope + 1 , slope + 1 + cnt , t[i].mid) - slope , 
				Up = lower_bound(slope + 1 , slope + 1 + cnt , t[i].up) - slope , 
				Rig = lower_bound(slope + 1 , slope + 1 + cnt , t[i].rig) - slope; 
			
			if(t[i].yl == 0 && zeroy >= t[i].xl ) zeroy = t[i].xl , idzeroy = i;
			if(t[i].xl == 0 && zerox >= t[i].yl ) zerox = t[i].yl , idzerox = i;
			Tx.modify(1 , 1 , cnt ,  Mid , Up , t[i].xl , i);
			Ty.modify(1 , 1 , cnt , Rig , Mid , t[i].yl , i);
			
		} else {
			
			if(t[i].up == 0) {
				printf("%d\n" , idzeroy);
				continue;
			}
			if(t[i].up == inf) {
				printf("%d\n" , idzerox);
				continue;
			}
			
			int Up = lower_bound(slope + 1 , slope + 1 + cnt , t[i].up) - slope ;
			
			
			pii resx = Tx.query(1 , 1 , cnt , Up ) , resy = Ty.query(1 , 1 , cnt , Up );
			
			if( 1.00 * resx.fx * t[i].up < resy.fx) {
				printf("%d\n" , resx.fy);
			} else if( 1.00 * resx.fx * t[i].up > resy.fx) {
				printf("%d\n" , resy.fy);
			} else  {
				printf("%d\n" , max(resy.fy , resx.fy) );
			}
		}
	}
	return 0;
}
