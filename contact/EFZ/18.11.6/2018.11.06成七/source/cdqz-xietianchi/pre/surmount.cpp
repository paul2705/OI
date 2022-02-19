#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;

double f[N][N] , ans;//f[turn][suffix]

int n , g , t , a[N];
int cnt[N] , res;

void dfs(int cur,int sum){
	if (cur == t + 1){
		res += sum;
		return;
	}
	
//	for (int i = 1;i <= g;i++) printf("%d ",cnt[i]);putchar('\n');
	
	int near = g + 1;
	for (int i = g;i >= 1;i--){
		if (cnt[i]) near = i;
		if (near != g + 1){
			cnt[near]--;
			dfs(cur + 1 , sum + i);
			cnt[near]++;
		}else
		 dfs(cur + 1 , sum);
	}
}

int main(){
		freopen("surmount.in","r",stdin);
	freopen("surmount.out","w",stdout);

	scanf("%d%d%d",&n,&g,&t);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]) , cnt[a[i]]++;
//	for (int i = g - 1;i >= 1;i--) cnt[i] += cnt[i+1];
	
	sort(a + 1 , a + 1 + n);
	
	f[0][n + 1] = 1.00;
	
	for (int d = 0;d < t;d++){
		double p;
		for (int pos = n + 1;pos >= 1;pos--){
			if (pos != 1)
			{
				p = (double) 1.00 * ( a[pos-1] - a[pos-2] + 1 ) / g; 
			}else
			{
				p = 0;
			}
			f[d + 1][pos - 1] += p * (f[d][pos] - f[d][pos-1]);
			f[d + 1][pos] += (1 - p) * f[d][pos];
		}
	}
	
	for (int d = 1;d <= t;d++){
		for (int pos = 1;pos <= g;pos++){
			double p = 1.00 / g * f[d][n - cnt[pos]];
			
//			printf("%d %d %lf\n",d,pos,f[d][pos]);
			ans += (1.00 - p) * pos;
		}
	}
	if (g <= 8 && t <= 8){
		dfs(1 , 0);
		ans = 1.00  * res / pow(g , t);
	}
	printf("%.6lf\n",ans);
	return 0;
}
