#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=1e9;
const int MAXK=4e4;
const int mod=998244353;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
ll f[MAXK],a[MAXK];
int n,k;
mat A;
int main(){
	scanf("%d%d",&n,&k);
	for (int i
