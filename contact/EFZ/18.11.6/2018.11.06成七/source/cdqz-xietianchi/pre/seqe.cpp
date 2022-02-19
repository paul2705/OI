#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int n , ans , a[N];
int maxn , minm;
set < pair<int,int> > s;
set < pair<int,int> > ::iterator it;

int main() {
  scanf("%d",&n);
  for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
  s.insert(make_pair(0,0));
  s.insert(make_pair(n+1,n+1));

  for (int i = 1; i <= n; i++) {
    int j = i;

    while (j + 1 <= n) {
      j++;
      if (a[j] < a[j-1]) {
        j--;
        break;
      }

//			if ( (a[i] >= minm && a[i] <= maxn && a[j] > maxn ) )


      s.insert(make_pair(a[i],a[j]));
      it = s.find( make_pair(a[i],a[j]) );

      it--;
      if ( a[i] <= it->second && a[j] >= it->first && a[j] != it -> second) {
        it++;
        j--;
        s.erase(it);
        break;
      }
      it++;

      it++;
      if ( a[j] <= it->second && a[j] >= it->first && a[j] != it -> first) {
        it--;
        j--;
        s.erase(it);
        break;
      }
      it--;

      s.erase(it);
    }
    ans++;
    s.insert(make_pair(a[i],a[j]));
		printf("[%d %d]\n",i,j);
    i = j;

  }
  ans--;
  printf("%d\n",ans);
  return 0;
}

