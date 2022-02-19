#include <bits/stdc++.h>
const double pi = acos(-1);

using namespace std;
double seta , v , d , g , ans;
int T;
int main(){
	freopen("physics.in","r",stdin);
	
	freopen("physics.out","w",stdout);
	cin >> T;
	while (T--){
		scanf("%lf%lf%lf%lf",&seta,&v,&d,&g);
		ans = ( sin( (seta * pi ) / 90 ) * v * v) / ( g * (1 - d * d) );
		printf("%.5lf\n",ans);
	}
	return 0;
}
