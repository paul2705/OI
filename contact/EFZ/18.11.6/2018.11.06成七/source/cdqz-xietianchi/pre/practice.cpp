#include <bits/stdc++.h>
using namespace std;
const int N = 360360 + 10;
typedef long long ll;
const ll inf = 1e18;
ll dis[N];//to zero// a
ll dis2[N];
queue <int> q;
void dp2(int mul,int k){
	memset(dis2 , 0x3f , sizeof (int) * (mul + 10));
	dis2[mul-1] = 0;q.push(mul-1);
	
	while (q.size()){
		int cur = q.front();q.pop();
		if (cur == 0) continue;
		if (dis2[cur - 1] >= inf){
			dis2[cur - 1] = dis2[cur] + 1;
			q.push(cur - 1);
		}
		
		for (int i = 2;i <= k;i++) {
			if ( (cur % i ) && dis2[cur - (cur % i)] >= inf){
				dis2[cur - (cur % i)] = dis2[cur] + 1;
				q.push(cur - (cur % i) );
			}
		}
	}
	
	
}

ll dp(int x,int k){
	
	if (dis[x] < inf) return dis[x];
	ll &ans = dis[x];
	
//	printf("fafa %d\n",x);
	ans = min(ans , dp(x - 1 , k) + 1);
	for (int i = 2;i <= k;i++) if (x % i){
//		printf("wxh %d %d\n",x,x-(x%i));
		ans = min(ans , dp(x - (x % i) , k) + 1 );	
	}
	return ans;
}


ll  a , b , res[20];
int T , lcm[20] ;
int k ;
int main(){
	freopen("practice.in","r",stdin);
	freopen("practice.out","w",stdout);

	scanf("%d",&T);
	lcm[1] = 1;for (int i = 2;i <= 15;i++) lcm[i] = lcm[i-1] * i / __gcd(lcm[i-1] , i);
	
	for (int i = 1;i <= T;i++){
		scanf("%lld%lld%d",&a,&b,&k);
		if (k != 1){
			ll bela = ( a / lcm[k] ) + 1 , belb = (b / lcm[k]) + 1;
			memset(dis , 0x3f, sizeof (int) * (lcm[k] + 10) );
			
			if (bela != belb){
				dis[0] = 0;
				dp(lcm[k] - 1 , k);
				dp2(lcm[k] , k);
//				printf("%lld\n",dis[lcm[k]-1]);
				
				res[i] = dis[a % lcm[k]] + 1ll * (bela - belb - 1) * (1 + dis[lcm[k]-1]) + dis2[b % lcm[k]] + 1;
			}else{	
//				printf("gg %d\n",lcm[k]);
				
				dis[b % lcm[k]] = 0;
				dp(a % lcm[k] , k);
//			for (int o = 0;o < lcm[k];o++) printf("%d %d\n",o,dis[o]);
				
				res[i] = dis[a % lcm[k]];
			}
		}
		else res[i] = b - a;
		
		printf("%lld\n",res[i]);
	}
	return 0;	
}



