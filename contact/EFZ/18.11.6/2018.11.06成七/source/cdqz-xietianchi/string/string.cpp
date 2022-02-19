#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
char s[N];
#define lb(x) (x&(-x))

int n , a[N] , q;

int L[N] , R[N] , f[N][2] , cnt , sum;


int b[N];
void mdy(int pos,int val){
	while (pos <= n){
		b[pos] += val;
		pos += lb(pos);
	}
}

int qry(int x){
	int res = 0;
	while (x){
		res += b[x];
		x -= lb(x);
	}
	return res;
}
int solve(int l,int r){
	sum = cnt = 0;int ans = 0;
	for (int k = l;k <= r;k++) sum += a[k];
	
	int i = l , j = l;
	while (i <= r && !a[i]) i++;
	if (i > r) return 0;
	
	
	while (i <= r){
		j = i;
		while (j + 1 <= r && a[j+1] == 1) j++;
		++cnt;
		L[cnt] = i;R[cnt] = j;
		i = j + 1;
		while (i <= r && !a[i]) i++;
	}
	
	for (int i = 1;i <= cnt;i++) f[i][0] = f[i][1] = sum;
	if (L[1] == R[1]){//0 is 1 1 isnt 1
		f[1][0] = 1;
	}else{
		f[1][1] = 2;
	}
	
	for (int i = 2;i <= cnt;i++){
		if (L[i] == R[i]){
			f[i][0] = min(f[i-1][0] , f[i-1][1]) + 1;
			f[i][1] = f[i-1][1] + L[i] - R[i-1] - 1;
			f[i][1] = min(f[i][1] , f[i-1][0] + 1 + L[i] - R[i-1] - 1 + 2);		
		}else{
			f[i][1] = min(f[i][1] , min(f[i-1][1] , f[i-1][0]) + 2);
			f[i][1] = min(f[i][1] , f[i-1][1] + L[i] - R[i-1] - 1);
			f[i][1] = min(f[i][1] , f[i-1][0] + 1 + L[i] - R[i-1] - 1 + 2);			
		}
			
	}
	return min(f[cnt][0] , f[cnt][1]);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",s+1);
	for (int i = 1;i <= n;i++) {
		a[i] = s[i] - '0';
		mdy(i , a[i]);
	}
	cin >> q;
//	q = 6;
	while (q--){
		int opt;scanf("%d",&opt);
		if (opt == 1){
			int l , r;scanf("%d%d",&l,&r);
			if (r - l <= 1000)	printf("%d\n",solve(l,r));
			else printf("%d\n",qry(r)-qry(l-1));
		}else{
			int pos , val;scanf("%d%d",&pos,&val);
			mdy(pos , val - a[pos]);
		
			a[pos] = val;
		}
	}
	return 0;
}
