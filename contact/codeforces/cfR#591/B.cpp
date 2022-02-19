#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define pb push_back
#define F first
#define S second
#define f(i,a,b)  for(int i = a; i < b; i++)
#define endl '\n'
using ll = long long;
using db = long double;
using ii = pair<int, int>;
const int N = 1e5 + 5, LG = 17, MOD = 998244353;
const int SQ = 450;
const long double EPS = 1e-7;
int32_t main(){
  int t;
  cin >> t;
  while(t--){
    string s, t;
    cin >> s >> t;
    bool ok = false;
    for(char c = 'a'; c <= 'z' && !ok; ++c){
      if(count(s.begin(), s.end(), c) && count(t.begin(), t.end(), c))
        ok = true;
 
    }
    if(ok)cout << "Yes\n";
    else
      cout << "No\n";
 
  }
  return 0;
}
