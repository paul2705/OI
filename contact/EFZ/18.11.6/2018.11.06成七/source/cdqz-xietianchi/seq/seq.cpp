#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
#include <iostream>
using namespace std;

const int N = 1000005;
int ans , n , cnt , a[N] , b[N];
int f[N];
int pos1 , pos2 , mn ;
map<int , vector<int> > pos;
int main() {
//	freopen("seq.out","w",stdout);
scanf("%d",&n);
  for (int i = 1; i <= n; i++) {
    scanf("%d",&a[i]);
    b[i] = a[i];
  }

  for (int i = 1;i <= n;i++){
  	int j = i;
  	while (j + 1 <= n && b[j + 1] == b[i]){
  		j++;
	}
	a[++cnt] = b[i];
	i = j;
  }
  n = cnt;
  for (int i = 1;i <= cnt;i++) {	
  	b[i] = a[i];
  	pos[a[i]].push_back(i);
  }
  sort(b + 1 , b + 1 + n);
  
  b[0] = 0;pos[0].push_back(0);
  b[n + 1] = 2000000010; pos[ b[n + 1] ].push_back(n + 1);
  
//  for (int i = 0;i <= n + 1;i++) printf("%d ",b[i]);puts("");
  
  memset(f , 0x3f , sizeof f);
  f[0] = 0;
  	for (int k = 0;k < pos[b[1]].size();k++){
		f[ pos[b[1]][k] ] = 0;
	}
	
  for (int i = 1;i <= n;i++) {
  	int j = i;while (j + 1 <= n && b[j + 1] == b[i]) j++;
  	int all = j - i + 1;
  	if (i == j){
  		pos1 = pos[b[i]][0];
  		mn = f[pos1];
		for (int k = 0;k < pos[b[j+1]].size();k++){
			int cur = pos[b[j+1]][k];
			if ( a[ cur - 1 ] == b[i] || j == n){
				f[cur] = min(f[cur] , mn );	
			}else{
				f[cur] = min(f[cur] , mn + 1);
			}
		}
		
	}else{
		pos1 = pos[b[i]][0]  , pos2 = pos[b[i]][1] ; 
		if (f[ pos1 ] > f[ pos2 ]) swap( pos1 , pos2 );
		
		for (int k = 2;k < pos[b[i]].size();k++){
			if ( f[ pos[b[i]][k] ] <= f[ pos1 ]){
				pos2 = pos1;
				pos1 = pos[b[i]][k];
			}else
			if (f[ pos[b[i]][k] ] <= f[ pos2 ]){
				pos2 = pos[b[i]][k];
			}
		}
		
		mn = all - 1  + f[pos1];
		
		for (int k = 0;k < pos[b[j+1]].size();k++){
			int cur = pos[b[j+1]][k];
			if ( a[ cur - 1 ] == b[i] || j == n){
				if (cur - 1 != pos1){
					f[cur] = min(f[cur] , f[pos1] + all - 2 + 1);	
				}else{
					f[cur] = min(f[cur] , f[pos2] + all - 2 + 1);	
				}
			}else{
				f[cur] = min(f[cur] , mn + 1);
			}
		}
			
	}	
  	
//  	if ( j == n ){
//  		ans = n;
//		  for (int k = 0;k < pos[b[i]].size();k++){
//		  	printf("ass %d\n",f[ pos[b[i]][k] ]);
//			ans = min(ans , f[ pos[b[i]][k] ] + all - 2);
//		}
//		cout<<ans<<endl;
//		return 0;
//	}
  	i = j;
  	
  }
  
  printf("%d\n",f[n + 1]);
  
//  for (int i = 1;i <= n;i++) printf("%d ",f[i]);
  return 0;
}


